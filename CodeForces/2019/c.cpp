#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;
  for (ll ttt=0; ttt<t; ttt++) {
    ll n, k;
    cin>>n>>k;
    vector<ll> A(n);
    for(auto &x: A) cin>>x;
    ll tot = 0;
    for(auto x: A) tot+=x;

    ll mx = A[0];
    for(auto x: A) mx = max(mx, x);

    ll best = 1;
    for (ll i=n; i>=1; i--) {
      ll rest = tot%i;
      ll num = tot/i;
      ll need = 0;
      if (rest) {
        num+=1;
        need = i-rest;
      }
      if (num >= mx and need<=k) {
        best = max(best, i);
        cerr << "using horizontal " << i <<endl;
        break;
      }
    }

    {
      ll height = tot/mx;
      ll rest = tot%mx;
      ll need = 0;
      if (rest) {
        height+=1;
        need = mx-rest;
      }
      if (need <= k) {
        ll rem_k = k-need;
        // how much more can we pile up.
        ll pile = rem_k/mx;
        ll new_height = min(height+pile, n);
        cerr << "using vertical " << new_height <<endl;
        best = max(best, new_height);
      }
    }
    cout << best <<endl;;
  }
}





