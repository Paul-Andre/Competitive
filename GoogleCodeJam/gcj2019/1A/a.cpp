#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif



void solve() {
  int N;
  cin >> N;

  unordered_map<string, int> suf;
  unordered_map<int, unordered_set<string>> perSize;
  int maxS = 0;
  for (int i=0; i<N; i++) {
    string w;
    cin >> w;
    for (int j=0; j<w.size(); j++) {
      string ss = w.substr(j);
      suf[ss] ++;
      perSize[ss.size()].insert(ss);
      maxS = max(maxS, int(ss.size()));
    }
  }
  int tot = 0;
  for (int s = maxS; s>= 0; s--) {
    for (auto &w : perSize[s]) {
      //cerr << "adsfa " <<w << endl;
      int cnt = suf[w];
      if (cnt >= 2) {
        tot += 2;
        for (int j=0; j<w.size(); j++) {
          string ss = w.substr(j);
          suf[ss] -= 2;
        }
      }
    }
  }
  cout << tot;
}

int main() {
  int T;
  cin >> T;
  for (int ttt=1; ttt<=T; ttt++) {
    cout << "Case #" << ttt << ": ";
    solve();
    cout << endl;
  }
}
