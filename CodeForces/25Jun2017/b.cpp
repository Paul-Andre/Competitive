#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m, b;

ll ss(ll a) {
    return a*(a+1)/2;
}

ll calc(ll x, ll y) {
    //cerr << x << " " << y << endl;
    return ss(x)*(y+1) + ss(y)*(x+1);
}


int main() {
    cin >> m>> b;

    ll n = -100;

    for(ll y=b; y>=0; y--) {
        ll x = m*(b-y);

        n = max(n, calc(x, y));
    }

    cout << n << endl;
}
