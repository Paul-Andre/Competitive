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




void solve() {
  int C;
  cin >>C;
  vector<int> B(C);
  for(int i=0; i<C; i++) {
    cin>>B[i];
  }
  if (B[0] == 0 || B[C-1] == 0) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  int j=0;
  vector<int> P(C);
  for(int i=0; i<C;i++) {
    for(int k=0; k<B[i]; k++) {
      P[j]=i;
      j++;
    }
  }
  int maxDiff = 0;
  for (int i=0; i<C;i++) {
    maxDiff = max(maxDiff, abs(P[i] - i));
  }
  int R = maxDiff+1;
  cout << R<<endl;
  vector<vector<char> > draw(C, vector<char>(R, '.'));
  for (int i=0; i<C; i++) {
    int k = P[i] - i;
    if (k>0) {
      for (int j=0; j<k; j++) {
        draw[i+j][j] = '\\';
      }
    } else if (k<0) {
      k = -k;
      for (int j=0; j<k; j++) {
        draw[i-j][j] = '/';
      }
    }
  }
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      cout << draw[j][i];
    }
    cout << '\n';
  }
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

