#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll A, B, C, T;

int main() {

  cin>>n>>A>>B>>C>>T;

  ll tot =  0;

  for (ll i=0; i<n; i++) {
    ll t;
    cin >> t;
    if (C-B>0) {
      tot += A;
      tot += (T - t) *(C-B);
    }
    else {
      tot += A;
    }
  }

  cout << tot <<endl;
}



