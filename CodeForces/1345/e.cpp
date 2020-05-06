#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<int> G[254321];
vector<int> H[254321];

bool vis[254321];
int color[254321];

bool A[254321];

bool vis_cyc(int i) {
  if (color[i] == 2) return false;
  if (color[i] == 1) return true;
  color[i] = 1;
  for (int j=0; j<G[i].size(); j++) {
    int u = G[i][j];
    if (vis_cyc(u)) return true;
  }
  color[i] = 2;
  return false;
}

void vis_up(int i) {
  if (vis[i]) return;
  vis[i] = true;
  for (int j=0; j<G[i].size(); j++) {
    int u = G[i][j];
    vis_up(u);
  }
}
void vis_down(int i) {
  if (vis[i]) return;
  vis[i] = true;
  for (int j=0; j<H[i].size(); j++) {
    int u = H[i][j];
    vis_down(u);
  }
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);


  cin >> n>>m;
  for (int i=0; i<m; i++) {
    int x,y;
    cin >> x >> y;
    // (_x < _y)
    
    G[x].push_back(y);
    H[y].push_back(x);
  }
  bool good = true;
  memset(vis, 0, sizeof(vis));
  for (int i=1; i<=n; i++) {
    if (!vis[i]) {
      if (vis_cyc(i)) {
        good = false;
      }
    }
  }
  if (!good) {
    cout << "-1\n";
    return 0;
  }
  int tot = 0;
  memset(vis, 0, sizeof(vis));
  for (int i=1; i<=n; i++) {
    if (!vis[i]) {
      A[i] = true;
      tot ++;
    }
    vis[i] = false;
    vis_up(i);
    vis[i] = false;
    vis_down(i);
  }
  cout << tot << endl;
  for (int i=1; i<=n; i++) {
    if (A[i]) {
      cout << "A";
    }else {
      cout << "E";
    }
  }
  cout <<endl;
}
