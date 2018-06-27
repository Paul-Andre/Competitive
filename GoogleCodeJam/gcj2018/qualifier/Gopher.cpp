#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;

void solve() {
  int a;
  cin >> a;

  int w = ceil(sqrt(a));
  int h = w;


  w = max(3, w);
  h = max(3, h);

  vector<vector<bool> > free(w+1, vector<bool>(h+1, true));

  while(true) {
    int bestX = -100, bestY = -100;
    int bestFree = -1;

    for(int i=2; i<w; i++) {
      for(int j=2; j<h; j++) {
        int numFree = 0;
        for(int ii=-1; ii<=1; ii++) {
          for(int jj=-1; jj<=1; jj++) {
            numFree += (int)(free[i+ii][j+jj]);
          }
        }
        if (numFree > bestFree) {
          bestFree = numFree;
          bestX = i;
          bestY = j;
        }
      }
    }

    cout << bestX <<" "<< bestY <<endl;
    cout.flush();

    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
      return;
    }
    if (x == -1 && y == -1) {
      cerr << "exiting\n";
      exit(0);
    }
    free[x][y] = false;
  }
}


int t;
int main() {
  cin >> t;
  for (int tt=1; tt<=t; tt++) {
    solve();
  }
}
