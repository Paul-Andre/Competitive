#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
  int n;
  cin>>n;
  map<int,int> M;
  for(int i=0; i<n; i++) {
    int a;
    cin>>a;
    if (a<0) {
      a=-a;
    }
    M[a]++;
  }
  int cnt=0;
  for (auto const &p: M) {
    if (p.first != 0 and p.second >=2) {
      cnt+=2;
    }else {
      cnt++;
    }
  }
  cout<<cnt<<endl;
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
