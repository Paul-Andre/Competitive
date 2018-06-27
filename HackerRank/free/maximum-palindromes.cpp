#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

#define MOD 1000000007

ll pow(ll base, ll power, ll mod = MOD) {
  ll acc = 1;
  while(power != 0) {
    if (power % 2 == 0) {
      power/=2;
      base = (base*base) % mod;
    } else {
      power --;
      acc = acc * base % mod;
    }
  }
  acc += mod;
  acc %= mod;
  return acc;
}

ll inverse(ll n, ll mod = MOD) {
  return pow(n, mod - 2, mod);
}

#define M 100005
ll fact[M];
ll inv_fact[M];

void precompute() {
  fact[0] = 1;
  inv_fact[0] = 1;
  for (int i=1; i<M; i++) {
    fact[i] = fact[i-1]*i % MOD;
    inv_fact[i] = inverse(fact[i]);
  }

  /*
  for(int i=0; i<20; i++) {
    cerr << fact[i] <<" ";
  } cerr <<endl;
  for(int i=0; i<20; i++) {
    cerr << inv_fact[i] <<" ";
  } cerr <<endl;
  for(int i=0; i<20; i++) {
    cerr << inv_fact[i]*fact[i]%MOD <<" ";
  } cerr <<endl;
  */
}

ll cumul[M][26];

void init() {
  string s;
  cin >> s;
  for(int i=1; i<=s.size(); i++) {
    for (int j=0; j<26; j++) {
      cumul[i][j] = cumul[i-1][j];
    }
    int c = s[i-1]-'a';
    cumul[i][c] ++;
  }

  /*
  for (int j=0; j<26; j++) {
    for(int i=1; i<=s.size(); i++) {
      cerr << cumul[i][j] << " ";
    }
    cerr <<endl;
  }
  */
}

ll tot[26];

void query() {
  int l, r;
  cin >> l >> r;
  for (int j=0; j<26; j++) {
    tot[j] = cumul[r][j] - cumul[l-1][j];
  }
  /*
  for (int j=0; j<26; j++) {
    cerr << tot[j] << endl;
  }
  */

  ll numOdd = 0;
  ll tt = 0;
  for (int i=0; i<26; i++) {
    numOdd += tot[i]%2;
    tot[i] -= tot[i]%2;
    tot[i] /= 2;
    tt += tot[i];
  }
  if (numOdd == 0) numOdd = 1;

  ll res = fact[tt];
  for (int i=0; i<26; i++) {
    res *= inv_fact[tot[i]];
    res %=  MOD;
  }

  res = res * numOdd % MOD;
  res += MOD;
  res %= MOD;
  cout << res <<endl;
}


int main() {
  precompute();
  init();
  int q;
  cin >> q;
  while(q--) query();
}
