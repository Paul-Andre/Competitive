#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, a,b,k;

#define MOD 1000000009

ll exp(ll base, ll exp) {
    ll ac = 1;
    while(exp != 0) {
        if ( exp%2==0) {
            base = base*base;
            base %= MOD;
            exp /= 2;
        }
        else {
            ac *= base;
            ac %= MOD;
            exp --;
        }
    }
    ac %= MOD;
    ac += MOD;
    ac %= MOD;
    return ac;
}


ll inv(ll a) {
    //cerr << "inverseing " << a << '\n';
    return exp(a, MOD-2);
}

ll S[100010];

int main() {

  cin>>n>>a>>b>>k;


  ll inva = inv(a);
  ll aib = (inva * b) % MOD;

  ll aibacc = 1;

  ll sa = exp(a, n);

  ll chunk = 0;

  for (int i=0; i<k; i++) {
    char c;
    cin >> c;
    if (c == '+') {
      chunk += sa;
    } else {
      chunk -= sa;
    }
    chunk %= MOD;
    chunk += MOD;
    chunk %= MOD;

    aibacc *= aib;
    sa *= aib;
    aibacc %= MOD;
    sa %= MOD;
  }
  aibacc += MOD;
  aibacc %= MOD;

  //cerr << chunk << endl;

  ll m = (n+1)/k;

  ll kk;
  if (aibacc != 1) {
    kk = ((1 - exp(aibacc, m))%MOD)*inv(1 - aibacc);
  }else {
    kk = m;
  }
  kk %= MOD;

  ll ret = chunk*kk;

  ret %= MOD;
  ret += MOD;
  ret %= MOD;
  cout << ret <<endl;

}



