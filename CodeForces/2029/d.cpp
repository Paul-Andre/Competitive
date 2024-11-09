#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  for (int ttt=0; ttt<t;ttt++) {
    int n, m;
    cin>>n>>m;
    vector<bool> edgeFromRoot(n+1, false);
    vector<pair<int,int>> otherEdges;
    for (int i=0; i<m; i++) {
      int u,v;
      cin>>u>>v;
      if (u == 1) {
        edgeFromRoot[v] =true;
      } else if (v == 1) {
        edgeFromRoot[u] =true;
      } else {
        otherEdges.emplace_back(u,v);
      }
    }
    vector<tuple<int,int,int>> ret;
    for (auto p: otherEdges) {
      int u = p.first;
      int v = p.second;
      ret.push_back({u,v,1});
      edgeFromRoot[u] = not edgeFromRoot[u];
      edgeFromRoot[v] = not edgeFromRoot[v];
    }
    int avail = -1;
    for (int i=2; i<=n; i++) {
      if (edgeFromRoot[i]) {
        avail = i;
        break;
      }
    }
    if (avail != -1) {
      // Not done, but can make a tree

      for (int i=2; i<=n; i++){
        if (not edgeFromRoot[i]) {
          ret.emplace_back(1, avail, i);
          avail = i;
        }
      }
    }
    cout<<ret.size()<<endl;
    for (int i=0; i<ret.size(); i++) {
      cout
        <<get<0>(ret[i])<<" "
        <<get<1>(ret[i])<<" "
        <<get<2>(ret[i])<<" "
        <<endl;
    }

         
  }
}

