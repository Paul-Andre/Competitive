#include <bits/stdc++.h>
using namespace std;


bool twoColor(int i, vector<vector<int>> &G, vector<int> &colors, int current) {
  if (colors[i] == current) return true;
  if (colors[i] != 0) return false;
  colors[i] = current;
  for (int j=0; j<G[i].size(); j++) {
    int u = G[i][j];
    int ret = twoColor(u, G, colors, -current);
    if (!ret) {
      return false;
    }
  }
  return true;
}

typedef pair<int,int> pii;

pair<int,int> cnt(int i, vector<vector<int>> &G, vector<int> &colors) {
  if (colors[i] == 2) return pii(0,0);
  int cn = 0;
  int cp = 0;
  if (colors[i] == -1) cn++;
  if (colors[i] == 1) cp++;
  colors[i] = 2;
  for (int j=0; j<G[i].size(); j++) {
    int u = G[i][j];
    pii ret = cnt(u, G, colors);
    cn+=ret.first;
    cp+=ret.second;
  }
  return pii(cn,cp);
}
  



int main() {
  int t;
  cin>>t;
  for(int ttt=0;ttt<t;ttt++) {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> G(n);

    vector<int> colors(n,0);

    for (int i=0; i<m; i++) {
      int u,v;
      cin>>u>>v;
      u--;
      v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    int tot = 0;
    for (int i=0; i<n; i++) {
      if (colors[i] == 0) {
        bool ret = twoColor(i, G, colors, 1);
        if (ret) {
          pair<int,int> counts = cnt(i, G, colors);
          tot += max(counts.first, counts.second);
        } else {
          // even if it's not two-colorable, we still call cnt to fill the whole graph component with 2
          cnt(i, G, colors);
        }
      }
    }
    cout<<tot<<endl;
  }
}
