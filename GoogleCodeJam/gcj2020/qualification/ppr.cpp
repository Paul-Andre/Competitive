#include <bits/stdc++.h>
using namespace std;

struct Half {
  int time;
  bool open;
  int id;
};

bool operator<(Half &a, Half &b) {
  if (a.time == b.time) {
    if (a.open == b.open) {
      return a.id < b.id;
    }
    return a.open < b.open;
  }
  return a.time < b.time;
}

void solve() {
  int N;
  cin >> N;
  vector<Half> halfs;
  for (int i=0; i<N; i++) {
    int a, b;
    cin >> a >> b;
    Half A = {a, 1, i};
    Half B = {b, 0, i};
    halfs.push_back(A);
    halfs.push_back(B);
  }
  sort(halfs.begin(), halfs.end());
  vector<char> result(N, '_');
  bool CA = true;
  bool JA = true;
  for(int i=0; i<N*2; i++) {
    Half &h = halfs[i];
    if (h.open) {
      if (CA) {
        result[h.id] = 'C';
        CA = false;
      } else if (JA) {
        result[h.id] = 'J';
        JA = false;
      } else {
        cout << "IMPOSSIBLE\n";
        return;
      }
    } else {
      if (result[h.id] == 'C') {
        CA = true;
      } else if (result[h.id] == 'J') {
        JA = true;
      } else {
        assert(false);
      }
    }
  }
  for (char c: result) {
    cout << c;
  }cout << endl;



}



int main() {
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cout << "Case #" << i << ":  ";
    solve();
  }
}

