#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif


ll n,k,l;
ll m;
ll a[112345];

void solve() {
  cin>>n>>k>>l;
  m = n*k;
  for(ll i=0; i<m; i++) {
    cin >> a[i];
  }
  sort(a, a+m);

  int maxmin =0;
  for(int i=0; i<m; i++) {
    if (a[i] - a[0] <= l) maxmin = i;
  }
  if (maxmin < n-1) {
    cout  << "0\n";
    return;
  }
  ll tot = 0;
  //cerr << "v :";
  for (int i=0; i<n; i++) {
    int v = min(i*k, maxmin - n+1 + i);
    //cerr << v << " ";
      tot += a[v];
  }
  //cerr << endl;

  cout << tot <<endl;
  return;


}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}

