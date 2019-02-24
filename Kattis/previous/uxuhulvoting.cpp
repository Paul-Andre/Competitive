#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int preferences[100][8];

int T[101][8];

void solve() {
  cin >> M;
  for (int i=0; i<M; i++) {
    for (int j=0; j<8; j++) {
      cin >> preferences[i][j];
      preferences[i][j] --;
    }
  }
  for (int i=100; i>=0; i--) {
    for (int j=0; j<8; j++) {
      T[i][j] = j;
    }
  }
  for (int i=M-1; i>=0; i--) {
    for (int j=0; j<8; j++) {
      int bestV = -1;
      int bestPreference = 1000;
      for (int k=0; k<3; k++) {
        int v = T[i+1][j ^ (1 << k)];
        if (preferences[i][v] < bestPreference) {
          bestPreference = preferences[i][v];
          bestV = v;
        }
      }
      assert(bestV != -1);
      T[i][j] = bestV;
    }
  }
  for (int k=2; k>=0; k--) {
    cout << ((T[0][0] & (1 << k))?("Y"):("N"));
  }
  cout <<endl;
}


int main() {
  cin>>N;
  while(N--){
    solve();
  }
}

