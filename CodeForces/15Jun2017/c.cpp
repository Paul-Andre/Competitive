#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

    ll n, s;

bool isBig(ll n) {
    ll m= n;
    ll t = 0;
    while(m!=0) {
        t += m%10;
        m/=10;
    }
    return (n-t >= s);
}


int main() {
    cin >> n >> s;
    
    ll a = 1;
    ll b = n;

    if (!isBig(n)) {
        cout << "0\n";
        exit(0);
    }

    while(a!=b) {
        ll c = (a+b)/2;
        if (isBig(c)) {
            b = c;
        }
        else {
            a = c + 1;
        }
    }

    cout<< (n+1-b) << endl;
}


