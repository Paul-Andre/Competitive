#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> t;
  for (int i=0; i<n; i++) {
    if (t.size() != 0 && t.back() == '(' && s[i] == ')') {
      t.pop_back();
    }else {
      t.push_back(s[i]);
    }
  }
  set<char> tt;
  for (char c: t) {
    tt.insert(c);
  }
  cout << tt.size() <<endl;
}


