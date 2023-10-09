#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 998244353

ll powww(ll base, ll exp) {
  ll c = 1;
  while(exp > 0) {
    //cerr <<base<<" "<<exp<<" "<<c<<endl;
    if (exp%2) {
      c *= base;
      c %= MOD;
      exp-=1;
    } else {
      base = base*base;
      base %= MOD;
      exp/=2;
    }
  }
  // cerr <<base<<" "<<exp<<" "<<c<<endl;
  return c;
}

ll inverse(ll a) {
  ll ret = powww(a, (ll)MOD-2);
  // cerr << a << " " << ret<<endl;
  // assert( (ret * a % MOD  + MOD)%MOD == 1);
  return ret;
}

int main() {

  ll n, m;
  cin>>n>>m;
  string s;
  cin>>s;

  
  vector<bool> toggles;

  for (char c: s) {
    toggles.push_back(c == '?');
  }

  ll prod = 1;
  for (ll i=1; i<n-1; i++) {
    if (toggles[i]) {
      prod*=i;
      prod%=MOD;
    }
  }

  if (toggles[0]) {
    cout<<0<<endl;
  }else{
    cout<<prod<<endl;
  }

  for (int ttt=0; ttt<m; ttt++) {
    ll i;
    char c;
    cin>>i>>c;

    i-=1;

    bool is_on= c=='?';

    if (toggles[i] == is_on) {
    }else if (toggles[i] == false and is_on == true) {
      toggles[i] = true;
      if (i!=0){
        prod *= i;
        prod%=MOD;
      }
    }else{
      toggles[i] = false;
      if (i!=0){
        prod *= inverse(i);
        prod%=MOD;
      }
    }

    if (toggles[0]) {
      cout<<0<<endl;
    }else{
      cout<<prod<<endl;
    }
  }
}
