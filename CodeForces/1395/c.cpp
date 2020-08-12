#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<int> A(n);
  vector<int> B(m);
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  for(int i=0;i<m;i++){
    cin>>B[i];
  }
  vector<vector<int>> C(n,B);
  int result = 0;
  for(int k=8;k>=0;k--){
    bool canBlock=true;
    bool has=false;
    for(int i=0;i<n;i++){
      if((A[i]&(1<<k))==0)continue;
      has=true;
      bool canBlockInner=false;
      for(int j=0;j<C[i].size();j++){
        if((C[i][j]&(1<<k))==0){
          canBlockInner=true;
          break;
        }
      }
      if(!canBlockInner){canBlock=false;}
    }
    if(has && canBlock){
      //filter
      for(int i=0;i<n;i++){
        if((A[i]&(1<<k))==0)continue;
        vector<int> newV;
        for(int j=0;j<C[i].size();j++){
          if((C[i][j]&(1<<k))==0){
            newV.push_back(C[i][j]);
          }
        }
        C[i]=newV;
      }
    }
    if(has && !(canBlock)){
      result|=1<<k;
    }
  }
  cout<<result<<endl;
}
