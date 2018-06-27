#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> pii;

#define NONE pii(-1,-1)

string s;
int n;
int palin[5005][5005];

int tot[5005];

int main() {
    cin>>s;
    n = s.size();


    for(int i=0; i<n; i++) {
        palin[i][1] = 1;
    }

    
    for(int i=0; i<n-1; i++) {
        if (s[i] == s[i+1]) palin[i][2] = 2;
    }
    

    for(int l=3; l<=n; l++) {
        for(int i=0; i<=n-l; i++) {
            if (s[i] == s[i+l-1] && palin[i+1][l-2]) {
                palin[i][l] = palin[i][l/2] + 1;
            }
        }
    }

    for(int l=1; l<=n; l++) {
        for(int i=0; i<=n-l; i++) {
            tot[palin[i][l]] ++;
        }
    }

    for(int i=n-1; i>=0; i--) {
        tot[i] += tot[i+1];
    }
    //cerr << tot[0] <<endl;
    for(int i=1; i<=n; i++) {
        cout << tot[i] << " " ;
    }
    cout <<endl;
}
