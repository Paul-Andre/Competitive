#include <bits/stdc++.h>
using namespace std;

int cnt (string a, string s) {
  int j = 0;
  int i = 0;
  int cnt = 0;
  for (; i<s.size(); i++) {
    if (a[j] == s[i]) cnt++;
    j++;
    j%=a.size();
  }
  return cnt;
}

int main() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  vector<pair<int, string>> v = 
  { {cnt("ABC", s), "Adrian"}, 
   {cnt("BABC", s), "Bruno"}, 
   {cnt("CCAABB", s), "Goran"}};

  sort(v.begin(), v.end());
  int best = v[2].first;
  cout << best <<endl;
  for (int i=0; i<n ;i++) {
    if (v[i].first == best) {
      cout << v[i].second << endl;
    }
  }
}

