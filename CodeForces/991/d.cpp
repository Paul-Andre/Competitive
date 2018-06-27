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

int M[1000][4];
string top;
string bot;

void solve() {
  cin >> top;
  cin >> bot;
  N  = top.size();
  for (int i=0; i<=N; i++) {
    for (int j=0; j<4; j++) {
      M[i][j] = -100000000;
    }
  }

  M[0][3] = 0;

  for (int i=1; i<=N; i++) {
    bool t = top[i-1] == 'X';
    bool b = bot[i-1] == 'X';
    int tb = t + 2*b;
    if (tb == 0) {
      M[i][3] = max(M[i-1][2], M[i-1][1])+1;
    }
    if ((tb & 1) == 0) {
      M[i][tb + 1] = M[i-1][0] + 1;
    }
    if ((tb & 2) == 0) {
      M[i][tb + 2] = M[i-1][0] + 1;
    }
    M[i][tb] = max(M[i][tb], M[i-1][3]);
    M[i][1] = max(M[i][1], M[i][0]);
    M[i][2] = max(M[i][2], M[i][0]);
    M[i][3] = max(M[i][2], M[i][3]);
    M[i][3] = max(M[i][1], M[i][3]);
  }

  cout << M[N][3] << endl;

}

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  solve();
}

