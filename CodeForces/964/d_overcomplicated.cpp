#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> tree[200010];
int subtree[200010];
bool vis[200010];
int vis2[200010];

int tag;

void findCentroidSubtree(int i) {
  vis2[i] = tag;
  subtree[i] = 1;
  for(int j=0; j<tree[i].size(); j++) {
    int u = tree[i][j];
    if (!vis[u] && vis2[u] != tag) {
      findCentroidSubtree(u);
      subtree[i] += subtree[u];
    }
  }
}

int top;
void findCentroid(int i) {
  tag ++;
  findCentroidSubtree(i);
  int n = subtree[i];
  top = 0;

  while(true) {

    int ms = -100;
    int mu = -1;
    bool good = true;

    for (int j=0; j<tree[i]; j++) {
      int u = tree[i][j];
      if (!vis[u]) {
        if (subtree[u] > n/2) {
          good = false;
        }
        if (subtree[u] > ms) {
          mu = u;
          ms = subtree[u];
        }
      }
    }
    if (good) {
      vis[i] = true;
      return i;
    }
    i = mu;
  }
}




int main() {

  cin>>n;
  for(int i=1; i<=n; i++) {
    int d;
    cin >> d;
    if (d==0) continue;
    tree[d].push_back(i);
    tree[i].push_back(d);
  }

}



