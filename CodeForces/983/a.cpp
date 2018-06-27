#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  while(true) {
    ll c = a%b;
    if (c == 0) return b;
    a = b;
    b = c;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int Q;
  cin >> Q;
  for(int iii=0; iii<Q; iii++) {
    ll p,q,b;
    cin>>p>>q>>b;

    ll g = gcd(p,q);
    q /= g;

    while(true) {
      b = gcd(b,q);
      q /= b;
      if (b == 1) break;
    }
    if (q == 1) {
      cout << "Finite\n";
    }else {
      cout << "Infinite\n";
    }
  }
}
