#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007

ll sss (ll a) {
    return ((a*(a+1))/2)%MOD;
}

ll ss (ll a, ll b) {
    if (a > b) return 0;
    return (sss(b) - sss(a-1))%MOD;
}

ll area (ll x1, ll y1, ll x2, ll y2, ll k, int space) {
    if ( x2 < x1 || y2 < y1) return 0;
    return ( (x2-x1+1) *( y2-y1+1) ) % MOD;
}


ll count(ll a, ll b) {
    if (a > b) return 0;
    return (b-a+1)%MOD;
}


ll calc (ll x1, ll y1, ll x2, ll y2, ll k, ll space, ll m) {
    if ( x2 < x1 || y2 < y1) return 0;

    //cout << x1 <<" " << y1 <<" "<< x2 << " " << y2 << " " << k << " " << space << " " << m <<  '\n';

    if (space == 0) {
        exit(1);
    }

    if (x1 == 1 && y1 == 1 &&  x2 == space && y2 == space) {
        //cout << "if\n";
        
        k = min(space + m - 1, max(1LL, k));

        ll c = ss(m, k) * space;

        cout << "pop\n";
        return c%MOD;
    }

    else {
        //cout << "else\n";
        ll sp = space/2;
        ll ret = 
                calc(x1, y1, min(x2, sp), min(y2, sp), k, sp, m)+
                
                calc(max(x1, sp+1)-sp, y1, x2-sp, min(y2, sp), k, sp, m+ sp) +

                calc(x1, max(y1, sp+1)-sp, min(x2, sp), y2-sp,  k, sp, m+ sp) +

                calc(max(x1, sp+1)-sp, max(y1, sp+1)-sp, x2-sp, y2-sp,  k, sp, m);
        ret %= MOD;

        return ret;
    }
}






int main() {
    int q;
    cin >>q;
    
    while(q--) {
        ll x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;

        cout << (calc(x1, y1, x2, y2, k, 1LL<<31, 1)+MOD)%MOD << endl;
    }
}




