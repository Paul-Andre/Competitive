#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

#define MOD 1000000007


int A[300001][8];
int n, m;


int main() {
  // Hahaha lol
  ios_base :: sync_with_stdio(false); cin.tie(NULL); 

  cin >> n >> m;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> A[i][j];
    }
  }

  int a = -1;
  int b = 1001001001;
  int besti = -1;
  int bestj = -1;
  while (a + 1 != b) {
    int c = (a+b)/2;
    bool found = false;

    int map[256] = {0};
    for (int i=0; i<n; i++) {
      int huh = 0;
      for (int k=0; k<m; k++) {
        if (A[i][k] >= c) {
          huh |= (1 << k);
        }
      }
      map[huh] = i+1;
    }

    for (int i=0; i<256; i++) {
      for (int j=i; j<256; j++) {
        if (map[i] == 0 || map[j] == 0) continue;
        int huh = i | j;
        if (huh == (1 << m) - 1) {
          besti = map[i];
          bestj = map[j];
          found = true;
        }
      }
    }
    if (found) {
      a = c;
    } else {
      b = c;
    }
  }
  cout << besti << " " << bestj <<endl;
}
