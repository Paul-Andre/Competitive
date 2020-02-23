#include <bits/stdc++.h>
using namespace std;

// combinatorics

typedef long long ll;

#define MOD 1000000007

ll fac[100000];

ll pp (ll a, ll b) {
  ll acc = 1;
  while(b != 0) {
    if (b%2 == 0) {
      a = (a*a) % MOD;
      b /= 2;
    } else {
      acc *= a;
      acc %= MOD;
      b -= 1;
    }
  }
  return acc;
}


ll div(ll a) {
  assert(a != 0);
  return pp(a, MOD - 2);
}

ll binom(ll n, ll k) {
  assert(n >= k);
  assert(k >= 0);
  //cerr << n << " asdf " << k <<endl;
  return fac[n] * div(fac[n-k] * fac[k] % MOD) % MOD;
}

int main() {

  fac[0] = 1;
  for (int i=1; i<100000; i++) {
    fac[i] = (fac[i-1]*i)% MOD;
  }

  ll n, m;
  cin >> n >> m;

  ll tot = 0;

  for (int i=1; i<=n; i++) {
    ll bot = binom(m-1 + i-1, i-1);
    ll top = binom(m   + n-i, n-i);
    //cerr << "with i " << i << " we have " << bot << " " <<top <<endl;
    tot = tot + (bot * top % MOD);
    tot %= MOD;
  }
  cout << tot <<endl;
}
