#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

bool char_eq(char a, char b) {
  if (a == '?') return true;
  if (b == '?') return true;
  return a == b;
}

int main() {
  int t;
  cin>>t;
  for (int ttt=0;ttt<t;ttt++){
    string s;
    cin>>s;
    int n = s.size();
    int m = 0;
    for (int i = 1; i*2<=n; i++) {
      int num_valid = 0;
      for (int j=0; j<i; j++) {
        num_valid += char_eq(s[j], s[i+j]);
      }
      if (num_valid == i) {
        m = max(m, i*2);
      }
      for (int j=1; j+2*i-1<n; j++) {
        bool prev_valid = char_eq(s[j-1], s[j-1 + i]);
        bool next_valid = char_eq(s[j+i-1], s[j+2*i-1]);
        num_valid -= prev_valid;
        num_valid += next_valid;
        if (num_valid == i) {
          m = max(m, i*2);
        }
      }
    }
    cout<<(m)<<endl;
  }
}

