#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin>>k;
  for (int kk=0; kk<k; kk++) {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &aa: a) cin>>aa;
    vector<bool> seen(n+1, false);
    seen[0] = true;
    int smallest_bad = n+1;
    for (int i = 0; i<n; i++ ) {
      if (!seen[a[i]-1]) {
        smallest_bad = min (smallest_bad, a[i]);
        //cerr << smallest_bad << " adsfa " << endl;
      }
      seen[a[i]] = true;
    }
    cout << (n+1 - smallest_bad) <<endl;
  }
}



