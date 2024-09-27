#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void traverse(const vector<vector<int>> &G, vector<pair<int,int>> &ret, vector<bool> &vis, int i, int depth) {
  if (vis[i]) return;
  vis[i] = true;
  for (int j=0; j<G[i].size(); j++) {
    int u = G[i][j];
    traverse(G, ret, vis, u, depth+1);
  }
  int max_reach = depth;
  for (int j=0; j<G[i].size(); j++) {
    int u = G[i][j];
    int child_reach = ret[u].second;
    max_reach = max(max_reach, child_reach);
  }
  ret[i] = make_pair(depth, max_reach);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;
  for (ll ttt=0; ttt<t; ttt++) {
    ll n;
    cin>>n;
    vector<vector<int>> G(n);
    for (int i=0; i<n-1; i++) {
      int u,v;
      cin>>u>>v;
      u--;
      v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }

    vector<pair<int,int>> ret(n, make_pair(0,0));
    vector<bool> vis(n, false);

    traverse(G, ret, vis, 0, 0);

    vector<pair<int,int>> bounds;
    for (auto p: ret) {
      bounds.emplace_back(p.first, 0);
      bounds.emplace_back(p.second, 1);
    }
    sort(bounds.begin(), bounds.end());

    int best = 0;
    int running = 0;

    for (auto p: bounds) {
      if (p.second == 0) {
        running+=1;
      }
      if (p.second == 1) {
        running-=1;
      }
      best = max(best, running);
    }
    cout << (n-best) <<endl;;
  }
}





