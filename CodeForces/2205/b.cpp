#include <bits/stdc++.h>
using namespace std;

bool seive[100001];

typedef long long ll;

int main() {
  /* for (int i=2; i<100001; i++) { */
  /*   for (int j=i*2; j<100001; j+=i) { */

  int t;
  cin>>t;
  for (int ttt=0; ttt<t; ttt++) {
    ll n;
    cin>>n;
    ll m = n;
    ll ret = 1;
    for (ll i=2; i*i<=n; i++) {
      if (m%i == 0) {
        ret *= i;
        while(m%i == 0) {
          m/=i;
        }
      }
    }
    if (m != 1) {
      ret *= m;
      m/=m;
    }
    cout<<ret<<endl;
  }







}
