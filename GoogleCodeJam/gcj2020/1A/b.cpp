#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;

void solve() {
  cin >> N;
  if (N <= 30) {
    for (int i=1; i<=N; i++) {
      cout << i << " 1\n";
    }
    return;
  }
  ll need = N - 30;
  bool p[100] = {};
  int nb = 0;
  for (int i=0; i<=29; i++) {
    if (need& (1ll << i)) {
      p[i] = true;
      nb++;
    }
  }
  bool right = false;
  for (int i=0; i<=29+nb; i++) {
    if (right) {
      if (!p[i]) {
        cout << (i+1) <<  " " << (i+1) << endl;
      } else {
        for (int j=i+1; j>=1; j--) {
          cout << (i+1) << " " << j <<endl;
        }
        right = false;
      }
    } else {
      if (!p[i]) {
        cout << (i+1) <<  " " << 1 << endl;
      } else {
        for (int j=1; j<=i+1; j++) {
          cout << (i+1) << " " << j <<endl;
        }
        right = true;
      }
    }
  }
}


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int T;
  cin >> T;
  for(int i=1; i<=T; i++) {
    cout << "Case #" << i << ":  ";
    solve();
  }
}

