#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x,y;
ll acc;

vector<ll> factors;
bool picked[500];

bool sieve[1000006];

int main() {
    cin>>x>>y;

    ll xx = x;

    for(ll i=2; i<=1000005; i++) {
        if (!sieve[i]) {
            while(xx%i==0) {
                xx/=i;
                factors.push_back(i);
            }
            for(ll ii=i; ii<=1000005; ii+=i) {
                sieve[ii] = true;
            }
        }
    }
    if(xx != 1) {
        factors.push_back(xx);
        xx = 1;
    }


    while(y != 0) {
        for(int i=0; i<factors.size(); i++) {
            if (!picked[i]) {
                ll p = factors[i];
                if (y%p==0) {
                    picked[i] = true;
                    y/=p;
                    x/=p;
                }
            }
        }

        if (x==1) {
            acc += y;
            break;
        }

        ll minStep = 10e15;
        for(int i=0; i<factors.size(); i++) {
            if (!picked[i]) {
                ll p = factors[i];
                minStep = min(minStep, y%p);
            }
        }

        acc += minStep;
        y-=minStep;
    }

    cout << acc <<endl;
}





