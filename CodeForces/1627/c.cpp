#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin>>n;
  vector<pair<int,int>> edges;
  vector<vector<pair<int,int>>> adjAndRef(n+1);
  for (int i=0; i<n-1; i++) {
    int x,y;
    cin>>x>>y;
    edges.emplace_back(x,y);
    adjAndRef[x].emplace_back(y, i);
    adjAndRef[y].emplace_back(x, i);
  }

  map<int,int> counts;
  for (int i=0; i<n-1; i++) {
    int x = edges[i].first;
    int y = edges[i].second;
    counts[x]++;
    counts[y]++;
  }
  bool good = true;
  int end = -1;
  for (auto &p : counts) {
    if (p.second > 2) {
      good = false;
    }
    if (p.second == 1) {
      end = p.first;
    }
  }

  if (!good) {
    cout << "-1" <<endl;
    return;
  }

  assert(end != -1);

  vector<bool> vis(n, false);
  vector<int> res(n-1, -1);
  int current = end;
  vis[end] =true;
  int ass = 2;
  while(true) {
    for (pair<int,int> p: adjAndRef[current]) {
      if (not vis[p.first]) {
        current = p.first;
        vis[current] = true;
        res[p.second] = ass;
        if (ass == 2) ass = 3; else ass = 2;
        goto continue_outer;
      }
    }
    break;
continue_outer:;
  }
  for (int a: res) {
    cout<<a << " ";
  }cout<<endl;
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
