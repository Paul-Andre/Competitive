#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<int> p(n);
  for(auto&a:p)cin>>a;
  vector<vector<int>> saved;
  int k = 1;
  while(p.size()) {
    saved.push_back(p);
    vector<int> np;
    for(int i=0; i<p.size();i++){
      if(p[i]>k){
        np.push_back(p[i]);
      }
    }
    p=np;
    k++;
  }
  /*
  for(auto&a:saved){
    for(auto&a:a){
      cout<<a<<" ";
    }
    cout<<endl;
  }
  */
  
  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++) {
      cout<<saved[i-j][j]<<" ";
    }
    cout<<endl;
  }
}




