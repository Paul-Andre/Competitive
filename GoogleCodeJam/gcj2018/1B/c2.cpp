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


int M;
int R[101][2];
int G[101];
int GG[101];
vector<int> pre;

bool binarySearch(ll d) {
  for (int i=0; i<101; i++) {
    GG[i] = G[i];
  }

  

void solve() {
  cin >> M;
  for (int i=1; i<=M; i++) {
    cin >> R[i][0] >> R[i][1];
  }
  for (int i=1; i<=M; i++) {
    cin >> G[i];
  }

  int tot = 0;

  while(trav(1)) {
    tot += 1;
  }
  cout << tot <<endl;

}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cout << "Case #"<<t<<": ";
    solve();

  }
}

