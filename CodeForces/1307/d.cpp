#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

vector<int> G[212345];
bool spec[212345];

bool vis[212345];
int from_start[212345];
int from_end[212345];

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); 

  int n,m,k;
  cin>>n>>m>>k;
  for (int i=0; i<k; i++) {
    int ai;
    cin >> ai;
    spec[ai] = true;
  }
  for (int i=1; i<=m; i++) {
    int x,y;
    cin>>x>>y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  queue<int> q;
  vis[1] = true;
  q.push(1);
  while(q.size() > 0) {
    int i = q.front();
    q.pop();
    for (int j=0; j<G[i].size(); j++) {
      int u = G[i][j];
      if (!vis[u]) {
        from_start[u] = from_start[i] + 1;
        vis[u] = true;
        q.push(u);
      }
    }
  }
  for(int i=0; i<=n; i++) {
    vis[i] = false;
  }
  q = queue<int>();
  vis[n] = true;
  q.push(n);
  while(q.size() > 0) {
    int i = q.front();
    q.pop();
    for (int j=0; j<G[i].size(); j++) {
      int u = G[i][j];
      if (!vis[u]) {
        from_end[u] = from_end[i] + 1;
        vis[u] = true;
        q.push(u);
      }
    }
  }
  int before = from_start[n];
  vector<int> ds;
  vector<int> de;
  for (int i=1; i<=n; i++) {
    if (spec[i]) {
      ds.push_back(from_start[i]);
      de.push_back(from_end[i]);
    }
  }
  sort(ds.begin(), ds.end());
  sort(de.begin(), de.end());

  // /*
  for (int i=0; i<ds.size(); i++) {
    cerr << ds[i] << " ";
  }
  cerr <<endl;
  for (int i=0; i<ds.size(); i++) {
    cerr << de[i] << " ";
  }
  cerr <<endl;
  // */
  
  {
    int i = 0;
    int j = de.size()-1;

    int mm = 0;

    while(i < ds.size() && j >= 0) {
      while(j >= 0 && ds[i] + de[j] + 1 > before ) {
       j--; 
      }
      if (j>=0) {
        mm = max(mm, ds[i] + de[j] + 1);
      }
      i++;
    }
    assert(mm > 0);
    cout << mm << endl;
  }
}

