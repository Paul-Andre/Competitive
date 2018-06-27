#include <bits/stdc++.h>
using namespace std;

#define SQR(x) ((x)*(x))
int n;

vector<string> rules[26];

int init;
vector<pii> found;

bool find(string &in, int rule, int pos, string &out) {
    for(int i=0; i<rules[rule].size(); i++) {
        string &r = rules[rule][i];
        if (r == "") {
            found.push_back(pii(init, pos));
        }
        else {
            char c = r[0];
            if (
            

int main() {

    cin>>n;
    for(int i=0; i<n; i++) {
        string s;
        getline(cin, s);
        rules[s[0] - 'A'].push_back(substr(5));
    }

    string s;
    while(getline(cin, s)) {
        found.clear();

        



    }

}



    


