#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int m,n;
ll grid[1123][1123];
bool vis[1123][1123];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool visit(int i, int j, ll ladder) {
  if (vis[i][j]) {
    return false;
  } 
  vis[i][j] = true;
  if (i == m-1 && j==n-1) return true;
  for (int k=0; k<4; k++) {
    int x = i+dx[k];
    int y = j+dy[k];
    if (x>=0 && x<m && y>=0 && y<n && !vis[x][y] && grid[x][y]-grid[i][j]<=ladder) {
      bool result = visit(x,y, ladder);
      if (result) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  cin>>m>>n;
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      cin>>grid[i][j];
    }
  }
  ll a = 0;
  ll b = 1000000001;

  while(a<b) {
    //cerr << a<<" " << b <<endl;
    ll c = (a+b)/2;
    memset(vis, 0, sizeof(vis));
    bool good = visit(0,0, c);
    if (good) {
      a = a;
      b = c;
    }else {
      a = c+1;
      b = b;
    }
  }
  cout << a <<endl;
}


