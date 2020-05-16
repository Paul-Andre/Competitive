#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ss(ll a) {
  return (a*(a+1))/2;
}

pair<ll,pair<ll,ll>> solveBrute(ll l, ll r) {

  for (ll i=1; i<998765432100000; i++) {
    if (r > l && r >= i) {
      r -= i;
    } else if (l >= i) {
      l -= i;
    } else {
      // cout << (i-1) << " " << l << " " << r << endl;
      return make_pair((i-1),make_pair(l,r));
    }
  }
}

void solveGood(ll l, ll r);

void solve() {
  ll l,r;
  cin >> l >>r;
  solveGood(l, r);
}

void solveGood(ll l, ll r) {
  ll og_l = l;
  ll og_r = r;

  ll rem = max(l-r, r-l);

  ll cnt = 0;
  if (rem > 0) {
    ll a = 0;
    ll b = 2987654321;
    while(a<b-1){
      ll c = (a + b)/2;
      ll cc = ss(c);
      if (cc <= rem) {
        a = c;
      }else{
        b = c;
      }
    }
    cnt = a;
    if (l > r) {
      l -= ss(cnt);
    } else {
      r -= ss(cnt);
    }
  }

  //cerr << "first " << cnt << " " << l << " " << r << endl;

  ll rS;
  ll lS;
  bool swapped = false;
  if (r > l) {
    ll tmp = r;
    r = l;
    l = tmp;
    swapped = true;
  }
  lS = cnt+1;
  rS = cnt+2;
  {
    ll a = -1;
    ll b = 1987654321;
    while(a<b-1){
      ll c = (a + b)/2;
      ll cc1 = lS*(c+1) + c*(c+1);
      ll cc2 = rS*(c+1) + c*(c+1);
      if (cc1 <= l && cc2 <= r) {
        a = c;
      }else{
        b = c;
      }
    }

    if (lS*(a+2) + (a+2)*(a+1) <= l){
      cnt = lS-1+(a+1)*2+1;
      l -= lS*(a+2) + (a+2)*(a+1);
      r -= rS*(a+1) + a*(a+1);
    } else {
      cnt = lS-1+(a+1)*2;
      l -= lS*(a+1) + a*(a+1);
      r -= rS*(a+1) + a*(a+1);
    }
  }
  if (swapped) {
    ll tmp = r;
    r = l;
    l = tmp;
  }
  cout << cnt << " " << l << " " << r << endl;
  /*
  cout << "      ";
  */
  
  
  /*
  if (solveBrute(og_l, og_r) != make_pair(cnt, make_pair(l,r))) {
    cerr << "BAADDDD\n";
    exit(-1);
  }
  */
  

}


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  //
  
  /*
  for (int i=0; i<1000; i++) {
    for (int j=0; j<1000; j++) {
      solveGood(i,j);
    }}
  */
  

  int T;
  cin >> T;
  for(int i=1; i<=T; i++) {
    cout << "Case #" << i << ":  ";
    solve();
  }
}

