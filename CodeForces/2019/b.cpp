#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;
  for (ll ttt=0; ttt<t; ttt++) {
    ll n, q;
    cin>>n>>q;
    vector<ll> X(n);
    for(auto &x: X) cin>>x;
    vector<ll> K(q);
    for(auto &x: K) cin>>x;

    map<ll,ll> ret;

    for (ll i=0; i<n-1; i++) {
      // Step 1, on the point X_i
      ll a = i;
      ll b = n-i-1;
      ll have  = a*b + a + b;
      ret[have] += 1;

      // Step 2, between X_i and X_(i+1)
      a = i+1;
      b = n-i-1;
      have = a*b;
      ll cnt = X[i+1]-X[i]-1;
      ret[have]+=cnt;
    }
    // final step
    {
      ll i=n-1;
      ll a = i;
      ll b = n-i-1;
      ll have  = a*b + a + b;
      ret[have] += 1;

    }
    
    for (ll i=0; i<q; i++) {
      cout<<ret[K[i]]<<" ";
    }
    cout<<endl;
  }
}





