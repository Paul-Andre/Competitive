#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
  ll n,m;
  cin>>n>>m;

  vector<ll> A(n);
  for(auto&a:A)cin>>a;

  set<pair<ll,ll>> bad_pairs;
  for(ll i=0; i<m; i++) {
    ll x,y;
    cin>>x>>y;
    bad_pairs.insert(make_pair(x,y));
    bad_pairs.insert(make_pair(y,x));
  }

  map<ll,ll> counts;
  for(ll i=0; i<n; i++) {
    ll a = A[i];
    counts[a]++;
  }

  vector<pair<ll,ll>> cnt_val;
  for(auto &p: counts){
    cnt_val.emplace_back(p.second, p.first);
  }
  sort(cnt_val.begin(), cnt_val.end());
  map<ll,ll> pnt;
  for(ll i=0; i<cnt_val.size(); i++) {
    pnt[cnt_val[i].first] = i;
  }
  ll best = 0;
  for(const auto &p: cnt_val) {
    ll cx = p.first;
    ll x = p.second;
    for(const auto &q: pnt) {
      ll index = q.second;
      ll cy = cnt_val[index].first;
      while(index >= 0 && cnt_val[index].first == cy) {
        ll y = cnt_val[index].second;
        ll bad = false;
        if (y == x) {
          bad = true;
        }
        if (bad_pairs.count(make_pair(x,y))) {
          bad = true;
        }
        if (bad) {
          index--;
          continue;
        }
        ll next = (cx+cy)*(x+y);
        best = max(best, next);
        break;
      }
    }
  }
  cout<<best<<endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
