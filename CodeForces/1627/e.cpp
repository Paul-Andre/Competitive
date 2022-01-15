#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n,m,k;
  vector<ll> X(n);
  for(auto &a:X)cin>>a;
  map< pair<int,int>, pair< pair<int,int>,  ll> > ladders;
  for(int i=0; i<k; i++){
    int a,b,c,d,h;
    cin>>a>>b>>c>>d>>h;
    ladders[make_pair(a,b)] =make_pair


  }
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
