#include <bits/stdc++.h>
using namespace std;


void solve() {
  int c, d;
  cin >>c>>d;
  vector<vector<pair<int,int>>> G(c+1);
  vector<int> X(c+1);
  vector<int> lat(d, 100000);
  X[1] = 0;
  for(int i=2;i <=c; i++) {
    cin>> X[i];
  }
  for (int  i=0; i<d; i++) {
    int x,y;
    cin>>x>>y;
    G[x].emplace_back(y,i);
    G[y].emplace_back(x,i);
  }
  vector<int> comps(c);
  for (int i=1; i<=c; i++) {
    comps[i-1] = i;
  }
  sort(comps.begin(),comps.end(), [&](int a, int b) {
      return (-X[a]) < (-X[b]);
      });
  int time = 0;
  vector<bool> vis(c+1, false);
  vector<int> timeAt(c+1, -1);
  vis[1] = true;
  timeAt[1] = 0;
  int prev_beef = 0;
  for (int i=1; i<c; i++) {
    int comp = comps[i];
    int beef = -X[comp];
    if (prev_beef != beef) {
      time++;
      prev_beef = beef;
    }
    for (int j=0; j<G[comp].size(); j++) {
      int u = G[comp][j].first;
      int link = G[comp][j].second;
      if (vis[u]) {
        if (timeAt[u] == time) {
          lat[link] = 100000;
        } else {
          lat[link] = time - timeAt[u];
        }
      }
    }
    timeAt[comp] = time;
    vis[comp] = true;
  }
  for (int i=0; i<d; i++) {
    cout << lat[i] << " ";
  }
  cout << endl;
}



int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int T;
  cin >> T;
  for(int i=1; i<=T; i++) {
    cout << "Case #" << i << ":  ";
    solve();
  }
}

