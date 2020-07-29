#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  //ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    ll l,r;
    cin>>l>>r;
    ll rr;
    if(r%2){
      rr = r-1;
    }else{
      rr=r;
    }
    ll la = rr/2;
    if (la < l) {
      cout << "-1 -1\n";
    }else{
      cout << la << " " << rr << endl;
    }
  }
}

