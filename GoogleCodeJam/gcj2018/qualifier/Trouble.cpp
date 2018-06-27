#include <bits/stdc++.h>
using namespace std;


void solve() {
  int n;
  cin >> n;
  vector<int> a;
  vector<int> b;
  bool bb = false;
  for (int i=0; i<n ;i++) {
    int v;
    cin >> v;
    if (bb) {
      b.push_back(v);
    } else {
      a.push_back(v);
    }
    bb = !bb;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  bb = false;
  int prev = -100;
  int ai = 0;
  int bi = 0;
  for (int i=0; i<n ;i++) {
    int v;
    if (bb) {
      v = b[bi];
      bi ++;
    } else {
      v = a[ai];
      ai ++;
    }
    bb = !bb;

    //cout << v << " ";
    if (v < prev) {
      cout << i-1 << endl;
      return;
    }
    prev = v;
  }
  cout << "OK" << endl;
  return;
}

int t;
int main() {
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cout << "Case #"<<tt <<": ";
    solve();
  }
}

