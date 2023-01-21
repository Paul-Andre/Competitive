#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007

//vector<int> UG[112345];
vector<vector<int>> G;
bool vis[212345];

ll tot=0;

int visit(int i){
  if (vis[i]) return 0;
  vis[i] = true;
  int depth = 0;
  for (int j=0; j<G[i].size(); j++) {
    int u = G[i][j];
    int ud = visit(u);
    depth = max(ud, depth);
  }
  tot += depth+1;
  tot %= MOD;
  return depth+1;
}

int main() {
  int t;
  cin>>t;
  for(int ttt=0; ttt<t; ttt++){
    int n;
    cin>>n;
    // memset(vis, 0, sizeof(vis));
    // ^ Ok, this is dumb; I might fail because of this; I should have had a vector and reinitialized it;
    // Or, alternatively, had a for-loop to do this based on n.
    // Since the bound I have is for the SUM of n over all test cases
    for (int i=0; i<n+1; i++) {
      vis[i] = 0;
    }
    G = vector<vector<int>>(n+1);
    tot=0;

    for (int i=0; i<n-1; i++) {
      int x,y;
      cin>>x>>y;
      G[x].push_back(y);
      G[y].push_back(x);
    }

    visit(1);
    
    for (int i=0; i<n-1; i++) {
      tot *=2;
      tot %= MOD;
    }
    cout<<tot<<endl;
  }
}


