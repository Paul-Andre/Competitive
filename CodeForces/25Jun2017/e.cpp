#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007


typedef vector<vector<ll> > vvl;


vvl identity(int n) {
    vvl ret(n, vector<ll>(n, 0));
    for(int i=0; i<n; i++) {
        ret[i][i] = 1;
    }
    return ret;
}

vvl bnd(int n) {
    vvl ret(16, vector<ll>(16, 0));

    for(int i=0; i<=n; i++) {
        ret[i][i] = 1;
    }
    for(int i=0; i<n; i++) {
        ret[i+1][i] = 1;
        ret[i][i+1] = 1;
    }

    return ret;
}


vvl operator*(vvl const &a, vvl const &b) {
    vvl ret(a.size(),  vector<ll>(b[0].size(), 0));

    assert(a[0].size() == b.size());

    for(int i=0; i<a.size(); i++) {
        for(int j=0; j<b[0].size(); j++) {
            for(int k=0; k< b.size(); k++) {
                ret[i][j] += (a[i][k]*b[k][j]) % MOD;
                ret[i][j] %= MOD;
            }
        }
    }

    return ret;
}

vvl matrixExp(vvl base, ll exp) {
    vvl acc = identity(base.size());
    while(exp!=0) {
        if (exp%2 == 0) {
            exp/=2;
            base = (base * base);
        }
        else {
            exp-=1;
            acc = acc*base;
        }
    }

    return acc;
}




int main() {
    ll n, k;
    cin >> n >> k;

    vvl ac = identity(16);
    for(int i=0; i<n; i++) {
        ll a, b, c;
        cin>>a>>b>>c;
        b = min(b, k);
        ac = ac * matrixExp(bnd(c), b-a);
    }

    cout << ac[0][0] << endl;
}

