#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> P(2*n);
    for(int i=0;i<2*n;i++){
      cin>>P[i];
    }
    vector<int> parts;
    int prevBiggest=P[0];
    int acc=1;
    for(int i=1;i<2*n;i++){
      int a=P[i];
      if(a>prevBiggest){
        parts.push_back(acc);
        prevBiggest=a;
        acc=1;
      }else{
        acc++;
      }
    }
    parts.push_back(acc);

    //can[i] -> can get i things in knapsack
    vector<bool> can(n+1,0);
    can[0]=true;
    for(int a:parts){
      for(int i=n;i>=0;i--){
        if(can[i]){
          if(i+a<=n){
            can[i+a]=true;
          }
        }
      }
    }
    if(can[n]){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }
}


