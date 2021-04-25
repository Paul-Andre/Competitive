#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,a,b;
  cin>>n>>a>>b;
  vector<int> U(21,0);
  for(int i=1; i<=n; i++) {
    cin>>U[i];
  }
  for(int i=1; i<400; i++){
    vector<int> V(max(i, n)+1, 0);
    for(int i=1; i<=n; i++){
      V[i] = U[i];
    }
    V[i]-=1;
    for(int j=i; j>=0; j--){
      if(V[j] < 0) {
        if(j-a>=1){
          V[j-a] += V[j];
        }
        if(j-b>=1){
          V[j-b] += V[j];
        }
        V[j]=0;
      }
    }
    bool good = true;
    for(int i=1; i<=n; i++){
      if(V[i] > 0){
        good=false;
      }
    }
    if(good){
      cout<<i;
      return;
    }
  }
  cout<<"IMPOSSIBLE";
}



int main(){
  int T;
  cin>>T;
  for(int ttt=1; ttt<=T; ttt++){
    cout << "Case #"<<ttt<<": ";
    solve();
    cout <<endl;
  }
}
