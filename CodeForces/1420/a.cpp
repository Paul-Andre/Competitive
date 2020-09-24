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
    for(auto &a: A){
      cin>>a;
    }
    bool disordered=true;
    for(int i=1;i<n;i++){
      int a= A[i-1];
      int b = A[i];
      if (a <= b) disordered=false;
    }
    if (disordered){
      cout<<"NO"<<endl;
    }else {
      cout<<"YES"<<endl;
    }
  }
}
