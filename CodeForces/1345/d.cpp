#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
vector<vector<bool>> A;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
void visit(int i,int j,vector<vector<bool>> &vis) {
  if (vis[i][j]) return;
  vis[i][j] = true;
  for (int k=0; k<4; k++) {
    int x = i+dx[k];
    int y = j+dy[k];
    if (x >=0 && x < n && y>=0 && y<m && A[x][y] && !vis[x][y]) {
      visit(x,y,vis);
    }
  }
}


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n>> m;
  A = vector<vector<bool>>(n, vector<bool>(m, false));
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      char c;
      cin >> c;
      A[i][j] = (c=='#');
    }
  }

  bool good = true;
  for (int i=0; i<n; i++) {
    bool in = false;
    bool passed = false;
    for (int j=0; j<m; j++) {
      if (A[i][j] && !in && passed) {
        good = false;
      }
      if (A[i][j]) {
        in = true;
      }
      if (!A[i][j] && in) {
        in = false;
        passed = true;
      }
    }
  }

  for (int j=0; j<m; j++) {
    bool in = false;
    bool passed = false;
    for (int i=0; i<n; i++) {
      if (A[i][j] && !in && passed) {
        good = false;
      }
      if (A[i][j]) {
        in = true;
      }
      if (!A[i][j] && in) {
        in = false;
        passed = true;
      }
    }
  }

  vector<bool> X(n, false);
  vector<bool> Y(m, false);

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (A[i][j]) {
        X[i] = true;
        Y[j] = true;
      }
    }
  }
  vector<bool> XX = X;
  vector<bool> YY = Y;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (!X[i] && !Y[j]) {
        XX[i] = true;
        YY[j] = true;
      }
    }
  }

  for (int i=0; i<n; i++) {
    if (!XX[i]) {
      good = false;
    }
  }

  for (int j=0; j<m; j++) {
    if (!YY[j]) {
      good = false;
    }
  }


  if(!good) {
    cout << "-1\n";
    return 0;
  } else {
    int tot = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (A[i][j] && !vis[i][j]) {
          visit(i,j,vis);
          tot ++;
    
        }
      }
    }
    cout << tot <<endl;
  }
}
