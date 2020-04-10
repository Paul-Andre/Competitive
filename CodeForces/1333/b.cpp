#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int n;
int A[154321];
int B[154321];

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;
  while(t--) {
    cin >> n;
    for (int i=0; i<n; i++) {
      cin >> A[i];
    }
    for (int i=0; i<n; i++) {
      cin >> B[i];
    }
    bool good = true;
    bool up = false;
    bool down = false;
    for (int i=0; i<n; i++) {
      int diff = B[i]-A[i];
      if (!(diff < 0 && down || diff > 0 && up || diff == 0)) {
        good= false;
        break;
      }
      if (A[i] == 1) {
        up = true;
      } else if (A[i] == -1) {
        down = true;
      }
    }
    if (good) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}




