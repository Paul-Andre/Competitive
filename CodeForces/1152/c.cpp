#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif


ll lcm(ll a, ll b) {
  return a * b / __gcd(a,b);
}

ll best = -1000;
ll bestbest = -1000;


pair<ll,ll> t(ll a, ll b, ll i) {
  if (a % i == 0) return make_pair(lcm(a,b), 0);
  ll r = a%i;
  return make_pair(lcm(a + i - r, b + i - r), i - r);
}
void tt(ll a, ll b, ll i) {
  pair<ll,ll> asdf = t(a,b,i);
  ll l = asdf.first;
  ll k = asdf.second;
  if (best == -1000 || l < best || (l == best && k < bestbest)) {
    best = l;
    bestbest = k;
  }
}

int main() {
  ll a, b;
  cin >> a >> b;
  if ( b < a) {
    ll tmp = a;
    a = b;
    b = tmp;
  }

  ll g = b - a;
  if (g == 0) { cout << 0 <<endl; exit(0); }

  for (ll i=1; i*i< g+10; i++) {
    if (g % i == 0) {
      ll ii = g/i;
      tt(a,b,i);
      tt(a,b,ii);
    }
  }
  cout << bestbest <<endl;
}
