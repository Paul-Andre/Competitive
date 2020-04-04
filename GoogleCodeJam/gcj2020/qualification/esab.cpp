#include <bits/stdc++.h>
using namespace std;
int B; // 10 20 100
void solve() {
  bool have[200] = {};
  int i = 0;
  int curr = 1;
  int diffCurr = -1;
  int sameCurr = -1;

  while (true) {
    int a, b;
    cout << curr << endl;
    cin >> a;
    cout << (B+1-curr) << endl;
    cin >> b;
    have[curr] = a;
    have[B+1-curr] = b;
    if (a == b) {
      sameCurr = curr;
    } else {
      diffCurr = curr;
    }
    if (curr == B/2) {
      for (int i=1; i<=B; i++) {
        cout << have[i];
      }
      cout << endl;
      char rep;
      cin >> rep;
      return;
    }
    i += 2;
    curr ++;
    if (i%10 == 0) {
      if (diffCurr == -1 || sameCurr == -1) {
        int dummy;
        cout << 1 << endl;
        cin >> dummy;
      }
      if (sameCurr != -1) {
        int a;
        cout << sameCurr << endl;
        cin >> a;
        if (a != have[sameCurr]) {
          for (int i=1; i<=B; i++) {
            have[i] = !have[i];
          }
        }
      }
      if (diffCurr != -1) {
        int a;
        cout << diffCurr << endl;
        cin >> a;
        if (a != have[diffCurr]) {
          for (int i=1; i<=B/2; i++) {
            bool tmp = have[i];
            have[i] = have[B+1-i];
            have[B+1-i] = tmp;
          }
        }
      }
      i+=2;
    }
  }



}

int main() {
  int n;
  cin >> n;
  cin >> B;
  for(int i=1; i<=n; i++) {
    solve();
  }
}

