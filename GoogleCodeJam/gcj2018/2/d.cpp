#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif

typedef vector<vector<bool> > vvc;

int C,R;

bool vis[200][200];

int cnt = 0;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

void count_rec(vvc &grid, int i, int j) {
  grid[i][j] = false;
  cnt ++;
  for (int k=0;k<4; k++) {
    int ii = i + dx[k];
    int jj = j + dy[k];
    if (ii >= 0 && ii<R && jj>=0 && jj<C && grid[ii][jj]) {
      count_rec(grid, ii, jj);
    }
  }
}

int max_cnt = 1;

void count(vvc grid) {
  for (int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      if (grid[i][j]) {
        cnt = 0;
        count_rec(grid, i, j);
        max_cnt = max(max_cnt, cnt);
      }
    }
  }
}

void solve() {
  cin >> R >> C;
  max_cnt = 1;

  vector<bool> has(16, false);

  vector<vector<bool>> grid(R,vector<bool>(C));
  for (int i=0; i<R; i++) {
    for(int  j=0; j<C; j++) {
      char g;
      cin >> g;
      grid[i][j] = (g=='W');
      if(grid[i][j]){
        has[0] = true;
      }else {
        has[15] = true;
      }
    }
  }
  for (int i=0; i<R-1; i++) {
    for(int  j=0; j<C; j++) {
      has[ grid[i][j] | grid[i+1][j]<<1 | grid[i][j]<<2 | grid[i+1][j]<<3 ] = true;
    }
  }
  for (int i=0; i<R; i++) {
    for(int  j=0; j<C-1; j++) {
      has[ grid[i][j] | grid[i][j]<<1 | grid[i][j+1]<<2 | grid[i][j+1]<<3 ] = true;
    }
  }
  for (int i=0; i<R-1; i++) {
    for(int  j=0; j<C-1; j++) {
      has[ grid[i][j] | grid[i+1][j]<<1 | grid[i][j+1]<<2 | grid[i+1][j+1]<<3 ] = true;
    }
  }

  /*
  for (int i=0; i<16; i++) {
    cerr << has[i] <<" ";
  }
  cerr <<endl;
  */
  

  for (int k=0; k<16; k++) {
    for (int x=0; x<=R; x++) {
      for (int y=0; y<=C; y++) {

        vector<vector<bool>> gg(R,vector<bool>(C));
        for (int i=0; i<R; i++) {
          for(int j=0; j<C; j++) {
            int kk = ((i>=x)<<0) | ((j>=y)<<1);
            gg[i][j] = (grid[i][j] != !((k>>kk)&1));
          }
        }
        if (has[k]) count(gg);
        //cerr << " " << max_cnt << " "<< k <<endl;
      }
    }
  }

  cout << max_cnt << endl;

}

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cout << "Case #"<<t<<": ";
    solve();

  }
}

