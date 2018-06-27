#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll powers[27];
// 0, 4, 24, 124, ...
ll powEvens[27];

int main() {
    powers[0] = 1;
    for (int i=1; i<27; i++) {
        powers[i] = powers[i-1]*5;
    }

    powEvens[0] = 1;
    for (int i=1; i<27; i++) {
        if (i%2) {
            powEvens[i] = powEvens[i-1]*5;
        }
        else {
            powEvens[i] = powEvens[i-1]*3 + (powers[i-1]-powEvens[i-1])*2;
        }
        //cout << powers[i]-1 << " " << powEvens[i] << '\n';
    }

    while(true) {
        ll n;
        cin >> n;
        if (n==-1) return 0;
        bool inv = false;
        ll tot = 0;
        for (int i=26; i>=0; i--) {
            while(n>=powers[i]) {
                n-= powers[i];
                //cout << n << "n \n";
                if (!inv) {
                    tot += powEvens[i];
                }else {
                    tot += (powers[i] - powEvens[i]);
                }
                //cout << tot << "tot \n";
                if (i%2) {
                    inv = !inv;
                }
            }
        }
                if (!inv) {
        tot ++;
                }
        cout << tot <<'\n';
    }




            





}
