#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

int main() {
    string s;
    cin >> s;

    int size = s.size();

    ll tot = 0;

    ll up = 1;
    ll mult = 1;

    for (int i=size-1; i>=0; i--) {
        ll add = (i+1)*up*(s[i]-'0');
        add %= MOD;

        tot += add;
        tot %= MOD;

        mult *= 10;
        mult %= MOD;

        up += mult;
        up %= MOD;
    }

    cout << tot << endl;

    return 0;
}

