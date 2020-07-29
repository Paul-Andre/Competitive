#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k,z;

int A[112345];

// B[x][y] = best score when at position x having went left y times and having went right last
int B[112345][6];

// B[x][y] = best score when at position x having went left y times and having went left last
int C[112345][6];


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  

  int t;
  cin>>t;
  while(t--){
    cin>>n>>k>>z;
    for(int i=1; i<=n; i++) {
      cin>>A[i];
    }

    for (int i=0; i<=n+1; i++) {
      for (int j=0; j<=5; j++) {
        B[i][j] = 0;
        C[i][j] = 0;
      }
    }

    for (int i=1; i<=n; i++) {
      B[i][0] = B[i-1][0] + A[i];
    }
    for (int j=1; j<=5; j++) {
      for (int i=1; i<=n-1; i++) {
        C[i][j] = B[i+1][j-1] + A[i];
      }
      for (int i=2; i<=n; i++) {
        B[i][j] = max(C[i-1][j] + A[i], B[i-1][j] + A[i]);
      }
    }
    int best = 0;
    for (int j=0; j<=5; j++) {
      for (int i=1; i<=n; i++) {
        //cerr << C[i][j] << "/" << B[i][j] << " ";
        if (i + j*2 - 1 == k && j <= z) {
          best = max(best, C[i][j]);
          best = max(best, B[i][j]);
        }
      }
      //cerr << endl;
    }
    cout << best <<endl;
    
  }
}

