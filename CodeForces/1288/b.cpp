#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
  int T;
  cin >> T;
  for (int iii=0; iii<T; iii++) {
    ll a,b;
    cin >> a >> b;

    ll tot =0;
    ll aaa = 1;
    for (int i=0; i<11; i++) {
      aaa *= 10;
      ll k = aaa - 1;
      if (k <= b) {
        tot += a;
      }
    }
    cout << tot <<endl;
  }
}
