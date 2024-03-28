#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool A[112345];

bool isBinDec(ll a){
  assert(a>=0);
  while(a){
    ll q = a/10;
    ll r = a%10;
    if (r!=0 and r!=1) {
      return false;
    }
    a = q;
  }
  return true;
}

// 0b101 -> 101
ll binToBinDec(ll a) {
  ll ret = 0;
  ll mult = 1;
  while(a){
    ll q = a/2;
    ll r = a%2;
    ret += r*mult;
    mult*=10;
    a = q;
  }
  return ret;
}

int main() {
  cerr<<binToBinDec(4)<< " " <<binToBinDec(10) <<endl;
  for (ll i =0; i<112345; i++) {
    if (isBinDec(i) or A[i]) {
      for (ll j=1; j<1<<6; j++) {
        ll k = i*binToBinDec(j);
        if (k<112345){
          A[k] = true;
        }
      }
    }
  }
  int t;
  cin>>t;
  for (int ttt=0; ttt<t; ttt++) {
    int n;
    cin>>n;
    if (A[n]) {
      cout<<("YES");
    }else {
      cout<<("NO");
    }
    cout<<endl;
  }
}
