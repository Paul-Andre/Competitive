#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;

#define M 5000001
//#define M 50001

ll t;
int l, r;

ll T[M];
ll D[M];

#define INV_2 500000004

bool seive[M];

int main(){
    cin>>t>>l>>r;
    
    for(ll i=1; i<M; i++) {
        D[i] = i;
    }


    for(ll p=2; p*p<=M; p++) {
        if (!seive[p]) {
            for(ll pp = p; pp<M; pp*=p) {
                for(ll i=pp; i<M; i+=pp) {
                    //cout << i << " ";
                    seive[i] = true;
                    D[i] /= p;
                    T[i] += ((((D[i] * p)%MOD * (p-1))%MOD) * INV_2) % MOD;
                    T[i] %= MOD;
                }
            }
        }
    }

    for(ll i=1; i<M; i++) {
        if (D[i] != 1) {
            //cerr <<D[i]<<endl;
            ll p = D[i];
            D[i] /= p;
            T[i] += ((((D[i] * p)%MOD * (p-1))%MOD) * INV_2) % MOD;
            T[i] %= MOD;
        }
    }


    ll tot = 0;
    ll mult = 1;

    for(int i=l; i<=r; i++) {
        tot += (T[i] *mult) % MOD;
        tot %= MOD;
        mult *= t;
        mult %=MOD;
    }
    cout <<tot <<endl;
}
