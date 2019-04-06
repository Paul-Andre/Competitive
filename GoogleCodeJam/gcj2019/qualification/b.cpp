#include <bits/stdc++.h>
using namespace std;


int main() {
  int T;
  cin >> T;
  for (int ttt=1; ttt<=T; ttt++) {
    int N;
    string P;
    cin >> N >> P;
    cout << "Case #" << ttt << ": ";
    for (char c: P) {
      if (c == 'E') cout << 'S';
      else cout << 'E';
    }
    cout << endl;
  }
}
    
