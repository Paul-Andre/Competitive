#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n;
vector<string> G;
vector<vector<bool>> visA, visB;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void visitB(int,int);
void visitA(int x, int y) {
  if (visA[x][y]) return;
  visA[x][y] = true;
  for (int k=0; k<4; k++) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    if (xx>=0 and xx <2 and yy>=0 and yy<n) {
      visitB(xx,yy);
    }
  }
}

void visitB(int x, int y) {
  if (visB[x][y]) return;
  visB[x][y] = true;
  if (G[x][y] == '<') {
    visitA(x, y-1);
  } else if (G[x][y] == '>') {
    visitA(x, y+1);
  }
}

int main() {
  int t;
  cin>>t;
  for (int ttt=0;ttt<t;ttt++){
    cin>>n;
    {
      string s1,s2;
      cin>>s1;
      cin>>s2;
      G = {s1, s2};
    }
    visA = vector<vector<bool>>(2, vector<bool>(n, false));
    visB = vector<vector<bool>>(2, vector<bool>(n, false));
    visitA(0,0);

    /*(
    for (int i=0; i<2; i++) {
      for (int j=0; j<n; j++) {
        cerr <<visA[i][j];
      }
      cerr<<endl;
    }
    for (int i=0; i<2; i++) {
      for (int j=0; j<n; j++) {
        cerr <<visB[i][j];
      }
      cerr<<endl;
    }
    */

    if (visA[1][n-1] || visB[1][n-1]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }

  }
}

