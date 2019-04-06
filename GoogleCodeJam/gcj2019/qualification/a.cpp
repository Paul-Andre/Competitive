#include <bits/stdc++.h>
using namespace std;


int main() {
  int T;
  cin >> T;
  for (int ttt=1; ttt <=T; ttt++) {
    string s;
    cin >> s;
    string a, b;
    bool passed = false;
    for (int i=0; i<(int)s.size(); i++) {
      char c = s[i];
      if (c == '4') {
        a.push_back('3');
        b.push_back('1');
        passed = true;
      } else if (passed) {
        a.push_back(c);
        b.push_back('0');
      } else {
        a.push_back(c);
      }
    }
    cout << "Case #" << ttt << ": " << a << " " << b <<endl;
  }
}
