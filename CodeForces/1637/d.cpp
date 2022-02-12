#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
  int n;
  cin>>n;
  vector<int> A(n);
  for(auto &a:A)cin>>a;
  vector<int> B(n);
  for(auto &a:B)cin>>a;

  vector<ll> C(14321, 800000000);
  C[0] = 0;
  ll running = 0;
  for (ll i=0; i<n; i++) {
    ll a = A[i];
    ll b = B[i];
    vector<ll> D(14321, 800000000);
    for (ll sum_a=0; sum_a<=10000; sum_a++) {
      ll sum_b = running-sum_a;
      D[sum_a+a] = min(D[sum_a+a],
          sum_a*a + sum_b*b + C[sum_a]);
      D[sum_a+b] = min(D[sum_a+b],
          sum_a*b + sum_b*a + C[sum_a]);
    }
    running+=a+b;
    C = move(D);
  }
  ll best = C[0];
  for(auto c:C) {
    best = min(best, c);
  }
  best*=2;
  for(auto a:A) {
    best += (n-1)*a*a;
  }
  for(auto a:B) {
    best += (n-1)*a*a;
  }
  cout<<best<<endl;
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
