#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_fair(ll a){
  ll b = a;
  while(b!= 0){
    //cerr << b <<endl;
    ll dig = b%10;
    b = b/10;
    if (dig != 0 && a % dig != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    while(true){
      if (is_fair(n)) {
        cout<< n<<endl;
        break;
      }
      n++;
    }
  }
}
