#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
  int t;
  cin>>t;
  while(t--){
    int n, m;
    cin>>n>>m;

    vector<int> A(n+1, 0);
    vector<bool> vis(n+1, false);
    for (int i=0; i<m; i++) {
      int x,y;
      cin>>x>>y;
      A[x] = y;
    }
    int cycles = 0;
    int in_place = 0;
    for (int i=1; i<=n; i++) {
      if (A[i] == 0) continue;

      if (vis[i]) continue;

      vis[i] = true;

      int ii = A[i];
      if (ii == i) {
        in_place++;
        continue;
      }

      while(true) {
        if (ii == i) {
          cycles ++;
          break;
        } else if (ii == 0) {
          break;
        }
        vis[ii] = true;
        ii = A[ii];
      }
    }
    cout << (m-in_place + cycles) <<endl;
  }
}
