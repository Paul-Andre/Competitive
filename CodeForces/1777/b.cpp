#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int t;
  cin>>t;
  for(int ttt; ttt<t; ttt++){
    ll n;
    cin>>n;
    ll tot = n*(n-1)%MOD;
    for (ll i=1; i<=n; i+=1){
      tot*=i;
      tot%=MOD;
    }
    cout<<tot<<endl;
  }
}


