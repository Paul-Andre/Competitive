
/*

int main() {
  cin >> n>> h;
  for (int i=0; i<10; i++) {
    cout << i << " " << cal(i) <<endl;
  }
}
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cctype>
#include <cassert>
#include <bitset>
#include <ctime>

using namespace std;

#define pau system("pause")
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define clr(a, x) memset(a, x, sizeof(a))

const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
tree<pli, null_type, greater<pli>, rb_tree_tag, tree_order_statistics_node_update> T;
*/

ll n, h;
ll cal(ll k) {
    if (h < k) {
        return (h + k - 1) * (k - h) / 2 + k * (k + 1) / 2;
    } else {
        return k * (k + 1) / 2;
    }
}
bool ok(ll k) {
    return cal(k) <= n;
}
int main() {
    scanf("%lld%lld", &n, &h);
    ll s = 1, e = 2e9, mi, k;
    while (s <= e) {
        mi = s + e >> 1;
        if (ok(mi)) s = (k = mi) + 1;
        else e = mi - 1;
    }
    ll ans = 0;
    if (k < h) {
        n -= cal(k);
        ans = k;
        if (n) ++ans;
    } else if (k == h) {
        n -= cal(k);
        ans = k;
        if (n) {
            if (n <= k) ++ans;
            else ans += 2;
        }
    } else {
        n -= cal(k);
        ans = k + k - h;
        if (n) {
            if (n <= k) ++ans;
            else ans += 2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
