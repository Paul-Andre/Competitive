#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m;


ll cnt(ll m) {
    if (m == 0) return 1;
    ll tot = 0;
    while(m!=0) {
        tot += (m%10)==0;
        m/=10;
    }
    return tot;
}
        

int main() {
    while(cin>>m>>n) {
        if (m<0) break;

        ll tot = 0;
        ll mult = 1;
        while(true) {

            while(m%10 != 0 && m<n) {
                tot += cnt(m) *mult;
                m++;
            }
            while(n%10 != 9 && m<n) {
                tot += cnt(n) *mult;
                n--;
            }

            if (m == n) {
                tot += cnt(n) * mult;
                break;
            }
            else {
                tot +=  (n-m+1)/10 * mult;
            }

            

            m/=10;
            n/=10;
            mult *= 10;

            if (m == 0) m = 1;
            if (n == 0) break;
        }

        cout << tot << endl;
    }
}

