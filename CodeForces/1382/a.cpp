#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    bool A[1001] = {0};
    bool B[1001] = {0};
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      A[x]=true;
    }
    for(int i=0;i<m;i++){
      int x;
      cin>>x;
      B[x]=true;
    }
    bool found=false;
    for(int i=0;i<1001;i++){
      if(A[i]&&B[i]){
        cout<<"YES\n1 "<<i<<endl;
        found=true;
        break;
      }
    }
    if(!found){
      cout<<"NO\n";
    }
  }
}

