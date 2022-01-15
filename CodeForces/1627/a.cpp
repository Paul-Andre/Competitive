#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n,m,r,c;
  cin>>n>>m>>r>>c;
  r--;
  c--;
  vector<string> a(n);
  for(auto &s:a)cin>>s;
  int ans = -1;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (a[i][j] == 'B') {
        ans = 2;
      }
    }
  }
  for (int i=0; i<n; i++) {
    if (a[i][c] == 'B') {
        ans = 1;
    }
  }
  for (int i=0; i<m; i++) {
    if (a[r][i] == 'B') {
        ans = 1;
    }
  }
  if (a[r][c] == 'B') {ans=0;}

  cout <<ans<<endl;
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
