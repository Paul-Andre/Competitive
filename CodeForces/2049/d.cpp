#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int main(){
  ll t = 0;
  cin>>t;
  for (ll ttt=0;ttt<t; ttt++) {
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>> A;
    for (int i=0; i<n; i++) {
      vector<ll> B(m);
      for (auto&b:B) cin>>b;
      A.push_back(move(B));
    }

    vector<ll> prev(m, 1ll<<60);
    prev[0] = 0;
    for (int i=0; i<n; i++) {
      vector<ll> best(m, 1ll<<60);
      // shift
      for (int s=0; s<m; s++) {
        vector<ll> B(m, -1);

        {
          ll j = 0;
          B[j] = prev[j]+A[i][(j+s)%m];
          best[j] = min(best[j], B[j]+s*k);
        }
        for (ll j=1; j<m; j++) {
          B[j] = min( prev[j], B[j-1]) + A[i][(j+s)%m];
          best[j] = min(best[j], B[j]+s*k);
        }
      }
      prev = move(best);
    }
    cout <<prev[m-1]<<endl;
  }
}

