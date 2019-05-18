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


ll A;
ll B;

bool ss(pll a, pll b) {
  return a.first*A + a.second*B < b.first*A + b.second*A;
}

bool operator<(Frac a, Frac b) {
  return a.num * b.denom < b.num * a.denom;
}

bool operator==(Frac a, Frac b) {
  return a.num * b.denom == b.num * a.denom;
}
bool operator!=(Frac a, Frac b) {
  return a.num * b.denom != b.num * a.denom;
}

bool lt(pll a, pll b) {
  if (b.second == 0) return true;
  return a.first * b.second < b.first * a.second;
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
  for (int x=1; x<500; x++) {
    for (int y=1; y<500; y++) {
      A = x;
      B = y;
      vector<pll> mmm;
      for (int i=0; i<mol.size();i++) {
        mmm.push_back(mol[mol.size() -1 - i]);
      }
      sort(mmm.begin(), mmm.end(), ss);
      if (mmm == mol) {
        cout << x << " " << y;
        return;
      }
    }
  }
  cout << "IMPOSSIBLE";
}



void solve2() {
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
    A = B = 1;
    vector<pll> mmm = mol;
    sort(mmm.begin(), mmm.end(), ss);
    if (mmm == mol) {
      cout << "1 1";
      return;
    } else {
      cout << "IMPOSSIBLE";
      return;
    }
  }
  sort(no.begin(), no.end());
  vector<Frac> nono;
  nono.push_back(no[0]);
  for(int i=0; i<no.size(); i++) {
    if (no[i] != nono.back()) {
      nono.push_back(no[i]);
    }
  }

  vector<pll > pos;
  pos.push_back(pll(0,1));
  for(int i=0; i<nono.size(); i++) {
    pos.push_back(pll(nono[i].denom, -nono[i].num));
  }
  pos.push_back(pll(1,0));

  for(int i=0; i<pos.size()-1; i++) {
    ll a1 = pos[i].first;
    ll a2 = pos[i].second;
    ll b1 = pos[i+1].first;
    ll b2 = pos[i+1].second;
    Frac rat(1,1);
    if (b2==0) {
      rat= Frac(2*a1, a2);
    } else {
      rat = Frac(a1*b2+b1*a2, 2*a2*b2);
    }
    A = rat.num;
    B = rat.denom;

    vector<pll> mmm = mol;
    sort(mmm.begin(), mmm.end(), ss);
    bool good = true;
    for (int i=0; i<N-1; i
    if (mmm == mol) {

      for (int x=1; x<500; x++) {
        for (int y=1; y<500; y++) {
          if (lt(pll(a1,a2), pll(x,y)) && lt(pll(x,y), pll(b1,b2))) {
            cout << x << " " << y;
            return;
          }
        }
      }
      assert(false);
    }
    /*
      for (int x=1; x<500; x++) {
        for (int y=1; y<500; y++) {
          A = x;
          B = y;
          vector<pll> mmm;
          for (int i=0; i<mol.size();i++) {
            mmm.push_back(mol[mol.size() -1 - i]);
          }
          sort(mmm.begin(), mmm.end(), ss);
          if (mmm == mol) {
            cout << x << " " << y;
            return;
          }
        }
      }
    }
    */

  }
  cout << "IMPOSSIBLE";
  return;
}

int main() {
  int T;
  cin >> T;
  for (int ttt=1; ttt<=T; ttt++) {
    cout << "Case #" << ttt << ": ";
    solve2();
    cout << endl;
  }
}
