#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> B(n, 0);
    for (int i=0; i<n; i++) {
      int a;
      cin >> a;
      B[((i+a)%n+n)%n] ++;
    }
    bool good = true;
    for (int i=0; i<n; i++) {
      if (B[i] != 1) {
        good = false;
      }
    }
    if (good) {
      cout << "YES\n";
    }else {
      cout << "NO\n";
    }
  }
}
