#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll n) {
  return (n*(n+1)/2 * 3 - n);
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);

    cerr << f(30000) <<endl;
  /*
    ll asdf = 0;
    for (int i=0; i<10; i++) {
      asdf += f(i);
      cerr << asdf << " ";
    }
    cerr <<endl;
    */

  int t;
  cin >> t;
  while(t--){
    ll n;
    cin >>n;

    int tot = 0;
    while(n >= 2) {
      ll a = 1 ,b = 100000;
      while(a<b-1){
        ll c = (a+b)/2;
        ll fc = f(c);
        if (fc <= n) {
          a = c;
        } else if (fc > n) {
          b = c;
        }
      }
      tot += 1;
      n-=f(a);
    }
    cout << tot <<endl;
  }
}
