#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    int n;
    cin>>n;
    vector<int> A(n);
    for(auto &a:A){
      ll x;
      cin>>x;
      if (x == 0) {
        a=-1;
      }else{
        for(int k=0;k<32;k++){
          if(x&(1<<k)){
            a=k;
          }
        }
      }
    }
    /*
    for(int a: A){
      cerr<<a<<" ";
    }cerr<<endl;
    */

    ll tot=0;
    map<int,ll> seen;
    for(int a: A){
      tot+=seen[a];
      seen[a]++;
    }
    cout<<tot<<endl;
  }
}
