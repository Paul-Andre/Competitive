#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, q;
vector<ll> A;

int main(){
  cin>>n>>q;
  A = vector<ll>(n);
  for(auto&a:A)cin>>a;
  sort(A.begin(), A.end());
  for(int qqq=0; qqq<q; qqq++){
    ll k;
    cin>>k;
    vector<ll> B = A;
    assert(k>0);
    int to_sub;

    if (k <= n) {
      to_sub = k;
    } else {
      if (k%2 == n%2) {
        to_sub = n;
      } else {
        to_sub = n-1;
      }
    }

    for (ll i=0; i<to_sub; i++) {
      B[i]+=k;
      k-=1;
    }
    sort(B.begin(), B.end());
    assert(k%2 == 0);
    ll pops = k/2;

    ll to_equalize = 0;
    for (int i=0; i<(int)B.size(); i++) {
      to_equalize+= B[i]-B[0];
    }

    if (to_equalize >= pops) {
      cout << B[0] << " ";
    } else {
      ll more = pops-to_equalize;
      if (more % n == 0) {
        cout << B[0]- (more/n) << " ";
      } else {
        cout << B[0]- (more/n) - 1 << " ";
      }
    }
  }
  cout <<endl;
}
