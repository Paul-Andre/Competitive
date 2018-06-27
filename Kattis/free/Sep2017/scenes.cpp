#include <bits/stdc++.h>

using namespace std;

int n,w,h;

typedef long long ll;

ll t[101][10001];

#define MOD 1000000007

int main() {
    cin>>n>>w>>h;

    for(int i=0; i<=n; i++){
        t[0][i] = 1;
    }

    for(int j=1; j<=w; j++) {
        for(int i=0; i<=n; i++) {
            ll tot = 0;
            for(int k=0; k<=h; k++) {
                if (i-k>=0 ) {
                    tot += t[j-1][i-k];
                    tot %= MOD;
                }
            }
            t[j][i] = tot;
        }
    }

    ll have = t[w][n];

    for(int i=0; i<=h; i++) {
        if (i*w <=n) have--;
    }

    have %= MOD;
    have+=MOD;
    have %= MOD;

    cout << have<<endl;
}





            
        


