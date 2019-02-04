#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
bool A[5200][5200];

bool checkSquare(int ii,int  jj,int  ss) {
  for (int i=0; i<ss; i++) {
    for (int j=0; j<ss; j++) {
      int x = i+ii;
      int y = j+jj;
      if (A[ii][jj] != A[x][y]) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i=0; i<n; i++) {
    string s;
    cin >> s;
    for (int j=0; j<s.size(); j++) {
      char c = s[j];
      int ii = -10;
      if ('0' <= c && c <= '9') { ii = c-'0'; }
      if ('A' <= c && c <= 'F') { ii = c-'A' + 10; }
      if ('a' <= c && c <= 'f') { ii = c-'a' + 10; }
      assert(ii!=-10);
      for (int k=0; k<4; k++) {
        A[i][j*4+k] = !!(ii & (1 << (3-k)));
      }
    }
  }
  /*
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cerr << A[i][j];
    }
    cerr << endl;
  }
  */
  int maxss = -1000;
  for (int k=5200; k>=1; k--) {
    if (n%k == 0) {
      int ss = n/k;
      bool good = true;
      for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++) {
          good &= checkSquare(i*ss, j*ss, ss);
        }
      }
      if (good) maxss = max(ss, maxss);
    }
  }
  cout << maxss <<endl;
} 
