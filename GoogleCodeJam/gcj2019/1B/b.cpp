#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif

#define FOR(r) for (ll r=0; r<=100; r++)


void solve() {
  ll a, b;

  cout << 210 <<endl;
  cin >> a;
  if (a == -1) exit(0);

  cout << 50 <<endl;
  cin >> b;
  if (b == -1) exit(0);

  ll v[7] = {0};
  ll vv[7] = {0};
  for (ll i=1;i <=6 ;i++) {
    v[i] = (1ll << (50ll/i));
    vv[i] = (1ll << (210ll/i));
  }

  FOR(r4) FOR(r5) FOR(r6) {
    if ( r4*vv[4] + r5*vv[5] + r6*vv[6] == a ) {
      FOR(r1) FOR(r2) FOR(r3) {
        /*
          cerr <<
            r1 << " " << 
            r2 << " " << 
            r3 << " " << 
            r4 << " " << 
            r5 << " " << 
            r6 << endl;
            */
        if ( r1*v[1] + r2*v[2] + r3*v[3] +
            r4*v[4] + r5*v[5] + r6*v[6] 
            == b ) {
          cout <<
            r1 << " " << 
            r2 << " " << 
            r3 << " " << 
            r4 << " " << 
            r5 << " " << 
            r6 << endl;
        }
      }
      return;
    }
  }
}

int main() {
  int T, W;
  cin >> T >> W;
  for (int ttt=1; ttt<=T; ttt++) {
    solve();
    int res;
    cin >> res;
    if (res == -1) exit(0);
  }
}
