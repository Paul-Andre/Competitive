#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> G[112345];
vector<int> edges[112345];
vector<int> result(112345, -1);

int main() {
  //   ios_base :: sync_with_stdio(false); cin.tie(NULL); 
  

  cin >> n;
  for (int i=0;i<n-1; i++) {
    int u,v;
    cin >>u>>v;
    G[u].push_back(v);
    G[v].push_back(u);
    edges[u].push_back(i);
    edges[v].push_back(i);
  }
  int sm = 0;
  for (int i=1; i<=n; i++) {
    if (G[i].size() > 2) {
      for (int j=0; j<3; j++) {
        int e = edges[i][j];
        result[e] = j;
      }
      sm = 3;
      break;
    }
  }
  for (int i=0; i<n-1; i++) {
    if (result[i] == -1) {
      result[i] = sm;
      sm++;
    }
  }
  for (int i=0; i<n-1; i++) {
    cout << result[i] << endl;
  }
}
