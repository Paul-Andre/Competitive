#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
using namespace std;

struct Node {
    unordered_map<string,int> answers;
    int q;
    unordered_map<string, unique_ptr<Node>> next;
    double guessProb;
    Node();
};

Node::Node() {
    this->q = 0;
}

Node tree;
double table[101];

string answ(Node &n) {
    n.q++;
    string a;
    cin >> a;
    n.answers[a]++;
    return a;
}


string insert(Node &n){
    n.q++;
    string s;
    cin >> s;

    if (n.next.find(s) == n.next.end()) {
        n.next[s] =  unique_ptr<Node>(new Node());
    }

    string a;
    if (s.back()!='?') {
        a = insert(*n.next[s]);
    }
    else {
        a = answ(*n.next[s]);
    }

    n.answers[a] ++;
    return a;
}

void calcGuess(Node &n) {
    int max=0;
    for (auto it=n.answers.begin(); it!=n.answers.end(); it++) {
        if (it->second > max) {
            max = it->second;
        }
    }
    n.guessProb = (double)max/(double)n.q;
    for ( auto it = n.next.begin(); it!=n.next.end(); it++) {
        calcGuess(*it->second);
    }
}

double expect(Node &n, int depth) {
    if (depth == 0) {
        return 0;
    }
    else {
        // try out luck
        double A = n.guessProb + table[depth-1];
        // or wait
        double tot = 0;
        for ( auto it = n.next.begin(); it!=n.next.end(); it++) {
            tot += expect(*it->second, depth-1)*it->second->q;
        }
        double B = tot/n.q;
        //cout << A << "," << B << '\n';
        return max(A,B);
    }
}

/*
void pr(Node &n) {
    if (n.leaf) {
        cout << "[" << n.answer << "]";
    }
    else {
        cout << "(";
        for ( auto it = n.next.begin(); it!=n.next.end(); it++) {
            pr(*it->second);
            cout << " " ;
        }
        cout << ")";
    }
}
*/



int main() {
    int t, n;
    cin >> t >> n;
    for (int ii=0; ii<n; ii++) {
        insert(tree);
    }
    calcGuess(tree);
    table[0] = 0.;
    //pr(tree);
    //
    //cout <<'\n';
    for (int ii=0; ii<=t; ii++) {
        table[ii] = expect(tree, ii);
    };
    /*
    for (int ii=0; ii<=t; ii++) {
        cout << table[ii] << " ";
    };
    cout << "\n";
    */

    printf("%.9f\n", table[t]);
}

