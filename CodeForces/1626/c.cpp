#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
  ll n;
  cin>>n;
  vector<pair<ll,ll>> A;
  vector<ll> K;
  for (ll i=0; i<n; i++) {
    ll k;
    cin>>k;
    K.push_back(k);
  }
  for (ll i=0; i<n; i++) {
    ll h;
    ll k = K[i];
    cin>>h;
    A.push_back(make_pair(k-h+1,0));
    A.push_back(make_pair(k,1));
  }
  sort(A.begin(), A.end());
  ll n_opened = 0;
  ll first_open = 0;
  ll tot = 0;
  for (auto p: A) {
    ll t = p.first;
    ll oc = p.second;
    if (oc == 0) {
      if (n_opened == 0) {
        first_open = t;
      }
      n_opened++;
    } else {
      n_opened--;
      if (n_opened == 0) {
        ll dist = t-first_open + 1;
        tot += (dist*(dist+1))/2;
      }
    }
  }
  cout << tot <<endl;

}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
