#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif


ll N, K;

struct S {
  ll value;
  ll width;
  bool bigger;
};

ll calculate(vector<ll> &X, vector<ll> &Y) {
  /*
  for (int i=0; i<N; i++) {
    cerr << X[i] << " ";
  }
  cerr << endl;
  for (int i=0; i<N; i++) {
    cerr << Y[i] << " ";
  }
  cerr << endl;
  */


  ll tot = 0;
  ll cur = 0;
  vector<S> mm;

  for (int i=0; i<N; i++) {
    ll x = X[i];
    ll y = Y[i];
    bool bigger = x > y;
    ll m = max(x,y);

    int ii;
    {
      int a=0;
      int b=mm.size();
      while(a < b) {
        int c = (a + b) / 2;
        assert(c != mm.size());
        S s = mm[c];
        if (s.value > m || (s.value == m && s.bigger == false)) {
          a = c+1;
        } else {
          b = c;
        }
      }
      assert(a == b);
      ii = a;
    }
    int iii = ii;

      ll replacing = 0;
    for(; ii< mm.size(); ii++) {
      replacing += mm[ii].width;
      if (mm[ii].bigger) {
        cur -= mm[ii].width;
      }
    }

    S ss;
    ss.value = m;
    ss.width = replacing+1;
    ss.bigger = bigger;
    mm.resize(iii);
    mm.push_back(ss);
    if (bigger) {
      cur += replacing+1;
    }
    /*
    cerr << " = ";
    for (int i=0; i<mm.size(); i++) {
      cerr << "(" <<mm[i].value <<" " << mm[i].width << " " <<mm[i].bigger << ")  ";
    }
    cerr << endl;
    cerr << tot << " " << cur <<endl;
    */
    tot += cur;
  }
  return tot;
}




void solve() {
  cin >> N >> K;
  vector<ll> A;
  vector<ll> B;
  for (int i=0; i<N; i++) {
    ll x; cin >> x; A.pb(x);
  }
  for (int i=0; i<N; i++) {
    ll x; cin >> x; B.pb(x);
  }
  vector<ll> AK(N);
  vector<ll> BK(N);
  for (int i=0; i<N; i++) {
    AK[i] = A[i] -K;
    BK[i] = B[i] -K;
  }
  ll ret = (N+1)*N/2 - calculate(BK, A) - calculate(AK, B);
  cout << ret;
}

int main() {
  int T;
  cin >> T;
  for (int ttt=1; ttt<=T; ttt++) {
    cout << "Case #" << ttt << ": ";
    solve();
    cout << endl;
  }
}
