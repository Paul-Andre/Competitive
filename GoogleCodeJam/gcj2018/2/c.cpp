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


int N;
int G[300][300];
int RowHave[300][300];
int ColHave[300][300];


void solve() {
  cin>>N;
  for(int i=0; i<300; i++) {
    for (int j=0; j<300; j++) {
      G[i][j] = RowHave[i][j] = ColHave[i][j] = 0;
    }
  }

  for(int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      int k;
      cin >> k;
      if (k >0) {
        G[i][j] = k;
      }else {
        G[i][j] = N-k;
      }
    }
  }
  /*
  for(int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        cerr << G[i][j] << " ";
    }
  cerr <<endl;
  }
  */

  for(int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      RowHave[i][G[i][j]] ++;
      ColHave[j][G[i][j]] ++;
    }
  }
  int mod = 0;

  for(int i=0; i<N; i++) {
    int m  = 0;
    for (int j=0; j<N; j++) {
      m = max(m,RowHave[i][G[i][j]] );
    }
    for (int j=0; j<N; j++) {
      bool change = false;
      if (RowHave[i][G[i][j]] >= 2 && ColHave[j][G[i][j]] >= 2 && RowHave[i][G[i][j]] == m) {
        change = true;
        mod ++;
        cerr <<"change "<< i << " "<< j << G[i][j] << endl;
        RowHave[i][G[i][j]] --;
        ColHave[j][G[i][j]] --;
        G[i][j] = 0;
      }
    }
  }

  for(int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (G[i][j] == 0) continue;
      assert(RowHave[i][G[i][j]] < 2 || ColHave[j][G[i][j]] < 2);

      if (RowHave[i][G[i][j]] >= 2) {
        mod ++;
        cerr <<"change "<< i << " "<< j <<endl;
        RowHave[i][G[i][j]] --;
        ColHave[j][G[i][j]] --;
        G[i][j] = 0;
      } else if (ColHave[j][G[i][j]] >= 2) {
        mod ++;
        cerr <<"change "<< i << " "<< j <<endl;
        RowHave[i][G[i][j]] --;
        ColHave[j][G[i][j]] --;
        G[i][j] = 0;
      }
    }
  }

  cout << mod <<endl;

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

