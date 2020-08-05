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
    for(int i=0;i<n;i++){
      cin>>A[i];
    }
    sort(A.begin(), A.end());
    int good=true;
    for(int i=0;i<n-1;i++){
      int d = A[i+1]-A[i];
      if(d>1){
        good=false;
        break;
      }
    }
    if(good){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }

}

