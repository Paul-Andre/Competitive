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



int n, m;
bool A[2001][2001];
int tot[2001];

void solve() {
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m;j++) {
      char c;
      cin >> c;
      A[i][j] = (c == '1');
      tot[j] += A[i][j];
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<m;j++) {
      tot[j] -= A[i][j];
    }
    int cnt = 0;
    for(int j=0; j<m;j++) {
      cnt += (tot[j] != 0);
    }
    for(int j=0; j<m;j++) {
      tot[j] += A[i][j];
    }
    if (cnt == m) {
      cout << "YES\n";
      return;
    }
  }
      cout << "NO\n";
      return;


}

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  solve();
}

