#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int q;
ll A[5001][5001];
ll M[5001][5001];

int main() {
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> A[1][1+i];
    M[1][1+i] = A[1][1+i];
  }
  for(int i=2; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      A[i][j] = A[i-1][j] ^ A[i-1][j+1];
      M[i][j] = max(A[i][j], max(M[i-1][j], M[i-1][j+1]));
    }
  }
  /*
    cerr << endl;
    cerr << endl;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cerr << M[i][j] << " ";
    }
    cerr << endl;
  }
  */

  cin >>q;
  for (int i=0; i<q; i++) {
    int l,r;
    cin >> l>>r;
    cout << M[r-l+1][l] <<endl;
  }

}
