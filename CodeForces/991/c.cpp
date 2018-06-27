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


bool simul(ll n, ll k) {
  ll orig  = n;
  ll tot = 0;

  while(n) {
    if ( n > k){
      tot += k;
      n -= k;
    }else {
      tot += n;
      n = 0;
    }
    ll sub = n/10;
    n -= sub;
    //cerr << n << endl;
  }

  return tot * 2 >= orig;
}

void solve() {
  ll n;
  cin >> n;

  ll a = 1;
  ll b = 1000000000000000000;

  /*
  for (int i=1; i<10; i++) {
    cerr << i << " " << simul(n, i) <<endl;
  }
  cerr <<endl;
  */

  while(a != b) {
    ll c  = (a + b) / 2;
    if (simul(n, c)) {
      b = c;
    }
    else {
      a = c+1;
    }
  }
  cout << a <<endl;
}

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  solve();
}

