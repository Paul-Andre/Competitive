#include <bits/stdc++.h>
using namespace std;

// It's possible to start with (i,j,k) (1,2,3) and
// end up with only of color 1
bool T[202][202][202];

int main() {
  for (int i=1; i<202; i++) {
    T[i][0][0] = true;
  }
  for (int cnt = 0; cnt < 400; cnt+=1) {
    for (int i=0; i<201; i++) {
      for (int j=0; j<201; j++) {
        int k = cnt-i-j;
        if (k >=0 and k < 201 and T[i][j][k]) {
          if (i) {
            T[i-1][j+1][k+1] = true;
          }
          if (j) {
            T[i+1][j-1][k+1] = true;
          }
          if (k) {
            T[i+1][j+1][k-1] = true;
          }
        }
      }
    }
  }
  int t;
  cin>>t;
  for (int ttt=0; ttt<t; ttt++) {
    int a,b,c;
    cin>>a>>b>>c;
    bool apos = T[a][b][c];
    bool bpos = T[b][a][c];
    bool cpos = T[c][a][b];
    cout <<apos<<" "<<bpos<<" "<<cpos<<endl;
  }
}
