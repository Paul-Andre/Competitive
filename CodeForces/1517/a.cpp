#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    if(n%2050){
      cout<<"-1"<<endl;
    }else{
      n/=2050;
      ll tot = 0;
      while(n){
        tot+=(n%10);
        n/=10;
      }
      cout<<tot<<endl;
    }
  }
}




