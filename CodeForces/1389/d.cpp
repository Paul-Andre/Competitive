#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    ll n,k;
    cin>>n>>k;
    ll l1,r1, l2,r2;
    cin>>l1>>r1>>l2>>r2;

    ll gap;
    ll single;
    ll have;

    if (r1 < l2) {
      gap = l2-r1;
      single = r2-l1;
      have = 0;
    } else if (r2 < l1) {
      gap = l1 - r2;
      single = r1-l2;
      have = 0;
    } else {
      gap = 0;
      ll l = max(l1,l2);
      ll r = min(r1,r2);
      have = r-l;
      ll poss = max(r1,r2)-min(l1,l2);
      single = poss-have;
    }

    ll need = k - have*n;
    if (need <= 0) {
      cout << 0 << endl;
      continue;
    }

    ll tot = 0;

    assert(gap <= single);

    ll cycle = gap+single;
    ll cn = need/single;
    if (cn >= n) {
      need -= single*n;
      tot += cycle*n;
      tot += (need)*2;
    } else {
      need -= single*cn;
      tot += cycle*cn;

      ll opt1 = gap+need;
      ll opt2 = need*2;

      tot += min(opt1, opt2);
    }

    cout << tot <<endl;
  }
}

