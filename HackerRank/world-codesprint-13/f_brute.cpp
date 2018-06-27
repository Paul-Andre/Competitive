#include <bits/stdc++.h>
using namespace std;

int n, q;

set<pair<int,int>> s;

vector<int> g[212345];
bool vis[212345];
int level[212345];
int parent[212345];

int first[212345];
int last[212345];

int orig[512345];

int p = 1;

void trav(int i, int lvl) {
  vis[i] = true;
  level[i] = lvl;
  

  for(int j=0; j<g[i].size(); j++) {
    int u = g[i][j];
    if (!vis[u]) {

      first[u] = p;
      orig[p] = i;
      p++;

      parent[u] = i;

      trav(u, lvl+1);


    }
  }

  last[i] = p;
  orig[p] = i;
  p++;
}

int dfs(int i, int target) {
  vis[i] = true;
  if (i == target) return 0;

  int b = 512345;

  for(int j=0; j<g[i].size(); j++) {
    int u = g[i][j];
    if (!vis[u]) {
      b = min(b, dfs(u, target));
    }
  }
  if (b!=512345) {
    b++;
  }
  return b;
}


bool blocked[212345];


int which(int i, int j) {
  if (parent[i] == j) return i;
  if (parent[j] == i) return j;
  return 0;
}

void remove(int x, int y) {
  for (int i=0; i<g[x].size(); i++) {
    if (g[x][i] == y) {
      g[x][i] = g[x].back();
      g[x].pop_back();
    }
  }
  
  for (int i=0; i<g[y].size(); i++) {
    if (g[y][i] == x) {
      g[y][i] = g[y].back();
      g[y].pop_back();
    }
  }
}




int main() {
  level[0] = 512345;

  first[1] = p;
  orig[p] = 0;
  p++;

  cin >> n;
  for (int i =1; i<n; i++) {
    int x, y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  trav(1,1);

  /*
  for (int i=1; i<p; i++) {
    cerr << orig[i] << " ";
  }
  cerr << endl;
  */



  cin >>q;
  for (int qqq=0; qqq<q; qqq++) {
    char cmd;
    int x, y;
    cin>>cmd>>x>>y;
    if (cmd =='d') {
      int z = which(x,y);
      if (z == 0) continue;
      if (blocked[z]) continue;

      blocked[z] = true;
      remove(x,y);

    }else if (cmd == 'c') {
      int z = which(x,y);
      if (z == 0) continue;
      if (!blocked[z]) continue;

      blocked[z] = false;

      g[x].push_back(y);
      g[y].push_back(x);

    }else {

      for(int i=1; i<=n; i++) {
        vis[i] = false;
      }

      int t = dfs(x,y);
      if (t == 512345) {
        cout << "Impossible\n";
      }else {
        cout <<  t <<endl;
      }

    }
  }
}


