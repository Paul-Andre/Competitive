#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

vector<int> G[112345];
bool vis[112345];

int tot;

int trav(int i) {
  vis[i] = true;
  int size = 0;

  for (int j=0; j<G[i].size(); j++) {
    int u = G[i][j];
    if (!vis[u]) {
      int s = trav(u);
      if (s % 2 == 0) {
        tot ++;
      }
      size += s;
    }
  }

        //cerr << "i s " << i << " " << size+1 <<endl;
  return size + 1;
}


int main() {

  cin>>n;
  for (int i=1; i<n; i++) {
    int u,v;
    cin>>u>>v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if (n%2) {
    cout  << "-1\n";
    exit(0);
  }
  trav(1);
  cout << tot <<endl;
}



