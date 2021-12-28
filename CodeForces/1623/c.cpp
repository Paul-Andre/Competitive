#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin>>n;
  vector<ll> H(n);
  for(auto &a:H)cin>>a;
  ll a=0;
  ll b=1123456789;

  while(a!=b){
    ll c = (a+b+1)/2;
    vector<ll> G = H;
    bool good = true;
    for (int i=n-1; i>=2; i--) {
      if (G[i] < c) {
        good = false;
        break;
      }
      ll excess = G[i] - c;
      excess = min(excess, H[i]);
      ll mov = excess/3;
      G[i]-=mov*3;
      G[i-1]+=mov*1;
      G[i-2]+=mov*2;
    }
    if (G[1] < c || G[0] < c) {
      good = false;
    }
    if (good) {
      a = c;
    } else {
      b = c-1;
    }
  }
  cout<<a<<endl;
}






int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
