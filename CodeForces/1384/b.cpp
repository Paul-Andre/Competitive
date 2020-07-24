#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,k,l;

ll tide(ll t) {
  t %= (2*k);
  if (t <= k) return t;
  return 2*k - t;
}



ll D[312345];
int main() {
  int t;
  cin>>t;
  while(t--) {
    cin>>n>>k>>l;
    for (ll i=0; i<n; i++) {
      cin>>D[i+1];
    }

    int rockP = 0;
    ll rockT = 0;
    int prevRockP = -1;
    int currP = 0;
    ll currT = 0;
    bool goingDown = false;

    bool possible = true;
    while(currP != n+1) {
      
      cerr << currP << " " << currT <<endl;
      if (currP != 0 && D[currP] + k <= l) {
        rockP = currP;
        rockT = currT;
      }
      if (D[currP+1] + tide(currT+1) <= l) {
        currP++;
        currT++;
        if (currT % (2*k) == 0) goingDown = false;
        if (currT % (2*k) == k) goingDown = true;
      } else {
        if (D[currP+1] > l) {
          possible = false;
          break;
        }
        if (goingDown) {
          ll diff = D[currP+1] + tide(currT+1) - l;
          currP++;
          currT += diff;
          if (currT % (2*k) == k) goingDown = false;
        } else {
          if (rockP == prevRockP) {
            possible = false;
            break;
          }
          prevRockP = rockP;
          currP = rockP;
          currT = rockT;
          if (currT % k != 0) {
            currT = (currT/k + 1)*k;
          }
          if (currT % (2*k) != k) {
            currT += k;
          }
        }
      }
    }
    if (possible) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }







  // ios_base::sync_with_stdio(false); cin.tie(NULL);
}

