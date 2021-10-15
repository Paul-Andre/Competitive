#include <bits/stdc++.h>
using namespace std;

int n;
int grid[26][26];

int main() {
  cin>>n;
  for (int i=0; i<n; i++) {
    string s;
    cin>>s;
    for(int j=0; j<n; j++) {
      grid[i][j] += s[j] - '0';
    }
  }
  for (int i=0; i<n; i++) {
    string s;
    cin>>s;
    for(int j=0; j<n; j++) {
      grid[i][j] += s[j] - '0';
      grid[i][j] %=2;
    }
  }
  /*
  for (int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cerr<<grid[i][j];
    }cerr<<endl;
  }
  */

  int best = 0;
  for (int k=0; k<(1<<n); k++) {
    int count = 0;
    for (int i=0; i<n; i++ ) {
      int c0 = 0;
      int c1 = 0;
      for (int j=0; j<n; j++ ) {
        int selj = !!(k & (1<<j));
        int have = (grid[i][j] ^ selj);
        if (have) {
          c1++;
        }else {
          c0++;
        }
      }
      count += max(c0, c1);
    }
    best = max(best, count);
  }
  cout << best <<endl;

}



