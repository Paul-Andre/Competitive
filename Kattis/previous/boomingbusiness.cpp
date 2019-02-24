#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int h, w;

#define MOD 1000000007

//   [x][max y][current y]
ll T[620][305][305];

int main() {
  T[0][0][0] = 1;
  for (int i=0; i<610; i++) {
    for (int j=0; j<=304; j++) {
      for (int k=0; k<=304; k++) {
        ll t = T[i][j][k];
        { // up
          if (k != 304) {
            int mx = max(j, k+1);
            T[i+1][mx][k+1] += t;
            T[i+1][mx][k+1] %= MOD;
          }
        }
        { // down
          if (k != 0) {
            T[i+1][j][k-1] += t;
            T[i+1][j][k-1] %= MOD;
          }
        }
      }
    }
  }

  for (int i=0; i<10; i++) {
    for (int j=0; j<10; j++) {
      cerr << T[i*2][j][0] << " ";
    }
    cerr <<endl;
  }
  cerr <<endl;

  cin>>h>>w;
  cout << T[(w-1)*2][h-1][0] << endl;
}

