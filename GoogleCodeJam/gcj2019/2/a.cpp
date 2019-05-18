#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif

struct Frac{
  ll num;
  ll denom;

  Frac(ll a, ll b) {
    assert(b!= 0);
    if (b < 0) {
      b *= -1;
      a *= -1;
    }
    ll g = __gcd(abs(a),abs(b));
    num = a/g;
    denom = b/g;
    if (denom < 0) {
      num *= -1;
      denom *= -1;
    }
  }
};


bool operator<(Frac a, Frac b) {
  return a.num * b.denom < b.num * a.denom;
}

bool operator==(Frac a, Frac b) {
  return a.num * b.denom == b.num * a.denom;
}
bool operator!=(Frac a, Frac b) {
  return a.num * b.denom != b.num * a.denom;
}

void solve() {
  int N;
  cin >> N;
  vector<pll > mol;
  for(int i=0; i<N; i++) {
    ll a, b;
    cin>>a>>b;
    mol.emplace_back(a,b);
  }
  vector<Frac> no;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      ll a = mol[i].first - mol[j].first;
      ll b = mol[i].second - mol[j].second;
      if (a != 0 && b != 0 && a*b < 0) {
        no.emplace_back(a,b);
      }
    }
  }
  if (no.size()  ==  0) {
    cout << 1;
    return;
  }
  sort(no.begin(), no.end());
  vector<Frac> nono;
  nono.push_back(no[0]);
  for(int i=0; i<no.size(); i++) {
    if (no[i] != nono.back()) {
      nono.push_back(no[i]);
    }
  }
  cout << (nono.size() + 1);
}

int main() {
  cerr << __gcd(-6, 10) <<endl;
  int T;
  cin >> T;
  for (int ttt=1; ttt<=T; ttt++) {
    cout << "Case #" << ttt << ": ";
    solve();
    cout << endl;
  }
}
