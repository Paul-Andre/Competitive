#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> A(m);

    for(auto &a:A)cin>>a;

    vector<bool> B(n+1, false);
    B[0] = false;
    for (int i=1; i<=n; i++) {
      bool canWin = false;
      for (int k:A) {
        if (i-k >= 0) {
          if (!B[i-k]) {
            canWin = true;
          }
        }
      }
      B[i] = canWin;
    }
    if (B[n]) {
      cout<<"Stan wins\n";
    }else {
      cout<<"Ollie wins\n";
    }
  }
}
      








