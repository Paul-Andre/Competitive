#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL tot[26][26];
LL before[26];

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); 
  string s;
  cin >> s;
  int n = s.size();
  for (int i=0; i<n; i++) {
    char c = s[i];
    int cc = c - 'a';
    for (int j=0; j<26; j++) {
      tot[j][cc] += before[j];
    }
    before[cc]+=1;
  }
  LL m = 0;
  for(int i=0; i<26; i++) {
    for(int j=0; j<26; j++) {
      m = max(m, tot[i][j]);
    }
  }
  for(int i=0; i<26; i++) {
      m = max(m, before[i]);
  }
    cout << m <<endl;
}
