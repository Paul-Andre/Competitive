#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define N 1000001

typedef long long ll;

ll tot;

ll toAdd[N];
ll has[N];

int n;

/// sumn[n] = sum{k=0 to n} (n choose k)*k
ll sumn[N];


int main() {
    cin>>n;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        has[x] ++;
    }

    ll t = 0;
    ll ways = 1;
    for(int i=1; i<N; i++) {
        t *=2;
        t += ways;
        ways *= 2;
        t %= MOD;
        ways %= MOD;
        sumn[i] = t;
    }

    for(int i=2; i<N; i++) {
        toAdd[i] = i;
    }

    for(int i=2; i<N; i++) {
        for(int j=i*2; j<N; j+=i) {
            toAdd[j] -= toAdd[i];
            toAdd[j] %= MOD;
        }
    }

    for(int i=2; i<N; i++) {
        ll cnt = 0;
        for(int j=i; j<N;j+=i) {
            cnt += has[j];
        }
        ll t = sumn[cnt];
        tot += t* toAdd[i];
        tot %= MOD;
    }

    tot %= MOD;
    tot += MOD;
    tot %= MOD;

    cout <<  tot << endl;
        
}


