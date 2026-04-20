#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int t;
  cin>>t;

  for (int ttt=0; ttt<t; ttt++) {
    ll p_, q_;
    cin>>p_>>q_;
    ll p = p_;
    ll q = q_;

    ll ans_n = -1;
    ll ans_m = -1;

    for (ll n=1; n<=17321; n++) {

      ll tot_sticks = p + 2*q;

      ll part = tot_sticks-n;
      if (part < 0) {
        continue;
      }
      if(part % (2*n+1) != 0) {
        continue;
      }
      ll m = part / (2*n+1);
      if (m<n) {
        continue;
      }

      ll min_unit = m-n;
      if (p < min_unit) {
        continue;
      }

      ans_n = n;
      ans_m = m;
    }
    if (ans_n == -1) {
      cout<<"-1"<<endl;
    }else {
      cout<< ans_n <<" "<< ans_m <<endl;
    }
  }

}
