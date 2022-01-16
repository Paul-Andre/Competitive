#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
  ll n;
  cin>>n;
  vector<int> A(n);
  for(auto&a:A)cin>>a;
  sort(A.begin(), A.end());
  vector<int> B(1,1);
  for (int i=1; i<n; i++) {
    if (A[i] == A[i-1]) {
      B.back()++;
    } else {
      B.push_back(1);
    }
  }
  ll best = (1ll<<20) + 2;
  for (int i=0; i<20; i++) {
    ll ii = (1ll<<i);
    if (ii + 1 + 1 >= best) break;
    for (int j=0; j<20; j++) {
      ll jj = (1ll<<j);
      if (ii + jj + 1 >= best) break;
      for (int k=0; k<20; k++) {
        ll kk = (1ll<<k);
        if (ii + jj + kk >= best) break;

        int l = 0;
        int m = B.size();
        {
          ll targ = ii;
          while(l<m && B[l] <= targ) {
            targ -= B[l];
            l++;
          }
        }
        {
          ll targ = jj;
          while(l<m && B[l] <= targ) {
            targ -= B[l];
            l++;
          }
        }
        {
          ll targ = kk;
          while(l<m && B[l] <= targ) {
            targ -= B[l];
            l++;
          }
        }
        if (l == m) {
          best = ii + jj + kk;
        }
      }
    }
  }
  cout<<(best-n)<<endl;
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
