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
    vector<int> A(n);
    map<int,int> M;
    for(int i=0;i<n;i++){
      cin>>A[i];
      M[A[i]]++;
    }
    int m=0;
    for(auto &p: M){
      m=max(m, p.second);
    }
    int t=0;
    int tot=0;
    for(auto &p: M){
      if(p.second != m){
        t+=p.second;
      }else{
        tot+=1;
      }
    }
    int tt=t/(m-1);
    tot+=tt;
    cout<<(tot-1)<<endl;
  }
}

