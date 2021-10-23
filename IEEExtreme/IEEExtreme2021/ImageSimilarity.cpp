#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--) {
    int wa, ha;
    cin>>wa>>ha;
    vector<string> a;
    for(int i=0; i<wa; i++) {
      string s;
      cin>>s;
      a.push_back(s);
    }
    int wb, hb;
    cin>>wb>>hb;
    vector<string> b;
    for(int i=0; i<wb; i++) {
      string s;
      cin>>s;
      b.push_back(s);
    }

    auto flip = [&]() {
      for (int i=0; i<wa/2; i++ ) {
        auto tmp = a[i];
        a[i] = a[wa-1-i];
        a[wa-1-i] = tmp;
      }
    };

    auto flipDiag = [&]() {
      vector<string> aa(ha, string(wa, '.'));
      for (int i=0; i<wa; i++) {
        for (int j=0; j<ha; j++) {
          aa[j][i] = a[i][j];
        }
      }
      a = aa;
      int tmp = wa;
      wa = ha;
      ha = tmp;
    };

    auto rotate = [&]() {
      flipDiag();
      flip();
    };

    int best = 0;

    auto compare = [&]() {
      /*
          for (int ii=0; ii<wa; ii++) {
            cerr << a[ii] <<endl;
          }
          cerr << "asdfffffffffffffffff" << endl;
          */

      for (int i=-30; i<31; i++) {
        for (int j=-30; j<31; j++) {
          int cnt = 0;
          for (int ii=0; ii<wa; ii++) {
            for (int jj=0; jj<ha; jj++) {
              int x = ii+i;
              int y = jj+j;
              if (x>=0 && y>=0 && x<wb && y<hb) {
                if (a[ii][jj] == '#' && b[x][y] == '#') {
                  cnt ++;
                }
              }
            }
          }
          best = max(best, cnt);
        }
      }
    };

    compare();
    rotate();

    compare();
    rotate();

    compare();
    rotate();

    compare();
    rotate();

    flip();

    compare();
    rotate();

    compare();
    rotate();

    compare();
    rotate();

    compare();
    rotate();

    cout <<best <<endl;
  }
}

