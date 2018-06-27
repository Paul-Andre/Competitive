#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int N;

pii inter[100000];
int cont[100000];
int parent[100000];

bool ss(pii a, pii b) {
    if (a.first!=b.first) return b.first<a.first;
    return a.second < b.second;
}


struct T {
    T*left = nullptr;
    T*right = nullptr;
    int a, b;
    int c = -1;
    int p;

    T(int aa, int bb) {
        //cerr << "Creating " << aa << " " << bb << endl;
        a = aa;
        b = bb;
    };

    void insert(int cc, int pp) {
        //cerr << "inserting " << pp << endl;
        if (!(a<=pp && pp<=b)) return;
        if (c == -1) {
            c = cc ;
            p = pp ;
        }
        else if (left == nullptr) {
            if ( p != pp) {
                int C = (a+b)/2;
                left = new T(a, C);
                right = new T(C+1, b);
                left->insert(c, p);
                right->insert(c, p);
                left->insert(cc, pp);
                right->insert(cc, pp);
            }
        }
        else {
            left->insert(cc, pp);
            right->insert(cc, pp);
        }

        if (cont[cc] > cont[c]) {
            c = cc;
            p = pp;
        }
    };

    int query(int aa, int bb) {
        //cerr << "Querying " << aa << " "<< bb << endl;

        if (c == -1) return -1;
        if ( left == nullptr) {
           if (aa<=p && p<=bb) return c;
           return -1;
        }

        if (bb < a || b < aa) return -1;
        if ( aa <= a && b <= bb) return c;

        int c1 = left->query(aa, bb);
        int c2 = right->query(aa, bb);
        if (c1 == -1 || c2 == -1) return max(c1, c2);
        if (cont[c1] >= cont[c2]) return c1;
        return c2;
    };
};

T tree(1, 1000000);


int main() {
    cin >> N;
    set<pii> seen;
    for(int i=0; i<N; i++) {
        int A,B;
        cin >> A >> B;
        if (seen.find(pii(A,B)) != seen.end()) {
            N--;
            i--;
            continue;
        }
        seen.insert(pii(A,B));
        inter[i] = pii(A,B);
    }

    sort(inter, inter+N, ss);
    
    for(int i=0; i< N; i++) {
        pii pa = inter[i];
        //int A = pa.first;
        int B = pa.second;
        int c = tree.query(1, B);
        parent[i] = c;
        if (c == -1) {
            cont[i] = 1;
        }
        else {
            cont[i] = cont[c] + 1;
        }
        tree.insert(i, B);
    }

    int mc = -1;
    int mx = -100;

    for(int i=0; i< N; i++) {
        if( cont[i] > mx) {
            mx = cont[i];
            mc = i;
        }
    }

    /*
    for(int i=0; i< N; i++) {
        cerr << i << ": " << inter[i].first << " " << inter[i].second << "  " << cont[i] << " " <<  parent[i] << endl;
    }
    */

    cout << mx << endl;

    while(mc != -1) {
        cout << inter[mc].first << " " << inter[mc].second << endl;
        mc = parent[mc];
    }
    
}

