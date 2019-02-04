#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  string s;
  cin >>n;
  cin >> s;
  if (n==2) {
    if (s[0] < s[1]) {
      cout << "YES\n";
      cout << "2\n";
      cout << s[0] << " " << s[1] <<endl;
    }else {
      cout << "NO\n";
    }
  } else {
    cout << "YES\n";
    cout << "2\n";
    cout << s[0] << " " << s.substr(1, s.size()) <<endl;
  }


}

int main() {
  int NNN;
  cin >> NNN;
  while(NNN--){
    solve();
  }
} 
