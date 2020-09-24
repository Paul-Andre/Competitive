#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    int n,q;
    cin>>n>>q;
    vector<int> A(n);
    for(auto&a:A)cin>>a;

    assert(q==0);
    /* */

    vector<ll> B(n+1,0); //start at position >=i with positive
    vector<ll> C(n+1,0); //start at position >=i with negative

    for(int i=n-1;i>=0;i--){
      B[i]=max(B[i+1], A[i] + C[i+1]);
      C[i]=max(C[i+1], - A[i] + B[i+1]);
    }
    /*
    for(int a:B){
      cerr<<a<<" ";
    }cerr<<endl;
    for(int a:C){
      cerr<<a<<" ";
    }cerr<<endl;
    */

    cout<<B[0]<<endl;
  }
}
