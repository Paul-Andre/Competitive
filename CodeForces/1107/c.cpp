#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
ll A[212345];

int main() {
string s;
  cin >> n >> k;
  for (int i=0; i<n; i++) {
    cin >> A[i];
  }
  cin >> s;
  ll sum = 0;
  int i=0;
  while(i < n) {
    //cerr << i << " " <<sum << endl;
    char current = s[i];
    vector<int> v;
    v.push_back(A[i]);
    i++;
    while(i < n && s[i] == current) {
      v.push_back(A[i]);
      i++;
    }
    sort(v.begin(), v.end());
    for (int j=0; j<k && j < (int)v.size(); j++) {
      sum += v[v.size() - 1 - j];
    }
  }
  cout << sum <<endl;
} 
