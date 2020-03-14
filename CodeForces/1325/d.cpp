#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cnt[100];

int main() {
  ll u, v;
  cin >> u >> v;

  //ll axor = 0;
  ll asum = 0;

  if (u % 2 != v % 2) {
    cout << "-1\n";
    return 0;
  } if (u > v) {
    cout << "-1\n";
    return 0;
  }

  if (u % 2) {
    cnt[0] = 1;
    //axor = 1;
    asum = 1;
  }

  for (ll i=1; i<63; i++) {
    bool uu = u & ( 1ll << i );
    bool vv = v & ( 1ll << i );

    if (uu) {
      cnt[i]++;
      asum += (1ll << i);
    }
    bool as = asum & ( 1ll << i );
    if (as != vv) {
      cnt[i-1ll] += 2;
      asum += (1ll << i);
    }
  }

  /*
  for (ll i=0; i<70; i++) {
    cerr << cnt[i] << " ";
  }
  cerr <<endl;
  return 0;
  */

  ll mm = 0;
  for (ll i=0; i<100; i++) {
    mm = max(mm, cnt[i]);
  }
  cout << mm <<endl;
  for (ll i=0;i<mm; i++) {
    ll p = 0;
    for (ll j=0; j<100; j++) {
      if (cnt[j] > 0) {
        p |= ( 1ll << j);
        cnt[j] --;
      }
    }
    cout << p << " ";
  }
  cout <<endl;
}
