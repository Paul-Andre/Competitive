#include <bits/stdc++.h>
using namespace std;

int N;
int A[100][100];

void solve() {
  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> A[i][j];
    }
  }
  int trace = 0; 
  for (int i=0; i<N; i++) {
    trace += A[i][i];
  }
  cout << trace << " ";
  int rep_rows = 0;
  for (int i=0; i<N; i++) {
    unordered_map<int,int> m;
    for (int j=0; j<N; j++) {
      int a = A[i][j];
      if (m[a]) {
        rep_rows ++;
        break;
      }
      m[a] ++;
    }
  }
  cout << rep_rows << " ";
  int rep_cols = 0;
  for (int i=0; i<N; i++) {
    unordered_map<int,int> m;
    for (int j=0; j<N; j++) {
      int a = A[j][i];
      if (m[a]) {
        rep_cols ++;
        break;
      }
      m[a] ++;
    }
  }
  cout << rep_cols << "\n";
}



int main() {
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cout << "Case #" << i << ":  ";
    solve();
  }
}

