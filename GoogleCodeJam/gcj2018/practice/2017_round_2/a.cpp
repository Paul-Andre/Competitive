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


void solve() {
  int N;
  cin >> N;
  int P;
  cin >> P;
  vector<int> G(P);
  for(int i=0; i<N; i++) {
    int g;
    cin >> g;
    g %= P;
    G[g]++;
  }
  int tot = 0;
  tot += G[0];

  if (P == 2) {
    tot += G[1]/2;
    G[1] -= G[1]/2*2;
    
    if (G[1]) tot ++;

  } else if (P == 3) {
    int h = min(G[1], G[2]);
    tot += h;
    G[1] -= h;
    G[2] -= h;

    tot += G[1]/3;
    G[1] -= G[1]/3*3;

    tot += G[2]/3;
    G[2] -= G[2]/3*3;

    if (G[1] + G[2]) tot ++;

  } else if (P == 4) {
    int g = min(G[1], G[3]);
    tot += g;
    G[1] -= g;
    G[3] -= g;

    if (G[3] == 0) G[3] = G[1];

    int h = min(G[3]/2, G[2]);
    tot += h;
    G[3] -= 2*h;
    G[2] -= h;
    tot += G[3]/4;
    G[3] -= G[3]/4*4;
    tot += G[2]/2;
    G[2] -= G[2]/2*2;
    if (G[3] + G[2]) tot ++;

  }

  cout << tot << endl;
}

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cout << "Case #"<<t<<": ";
    solve();

  }
}

