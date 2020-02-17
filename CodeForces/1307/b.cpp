#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL A[112345];

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); 
  int t;
  cin >> t;
  for(int iii=0; iii<t; iii++) {
    LL n,x;
    cin >> n >> x;
    for (int i=0;i<n; i++) {
      cin >> A[i];
    }
    sort(A, A+n);
    LL aa = A[n-1];
    LL d = x / aa;
    if (x % aa == 0) {
      cout << x / aa << endl;
      continue;
    } else if (d > 0) {
      cout << d + 1 << endl;
    } else {
      bool found = false;
      for (int i=0; i<n; i++) {
        if (A[i] == x) {
          cout << 1 <<endl;
          found = true;
          break;
        }
      }
      if (!found) {
        cout << 2 <<endl;
      }
    }
  }
}
