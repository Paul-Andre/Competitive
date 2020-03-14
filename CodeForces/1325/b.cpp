#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); 
  int t;
  cin >>  t;
  while(t--) {
    int n;
    cin >> n;
    unordered_map<int, bool> s;
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      s[x] = true;
    }
    cout<< s.size() <<endl;
  }
}
