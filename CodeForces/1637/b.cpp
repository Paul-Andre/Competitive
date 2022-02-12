#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
  int n;
  cin>>n;
  vector<int> A(n);
  for(auto &a:A)cin>>a;
  for(auto &a:A){
    if (a == 0) {
      a = 2;
    }else {
      a = 1;
    }
  }
  ll tot = 0;
  for (int i=0; i<n; i++) {
    ll running = 0;
    for (int j=i; j<n; j++) {
      running+=A[j];
      tot+=running;
    }
  }
  cout<<tot<<endl;
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
