#include <bits/stdc++.h>
using namespace std;


void solve() {
  string s;
  cin >> s;
  int current = 0;
  for (int i=0; i<s.size(); i++) {
    int c = s[i] - '0';
    while (c > current) {
      cout << "(";
      current ++;
    }
    while (c < current) {
      cout << ")";
      current --;
    }
    cout << c;
  }
    while (0 < current) {
      cout << ")";
      current --;
    }
    cout << "\n";

}



int main() {
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cout << "Case #" << i << ":  ";
    solve();
  }
}

