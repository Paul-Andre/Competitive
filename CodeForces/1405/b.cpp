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
    for(auto&a:A){
      cin>>a;
    }
    int i=0, j=1;
    while(i<n && j<n){
      if (i>=j) {
        j++; continue;
      }
      int &a=A[i];
      int &b=A[j];
      if (a <= 0) {
        i++; continue;
      }
      if (b >= 0) {
        j++; continue;
      }
      int rem=min(a, -b);
      a-=rem;
      b+=rem;
    }
    /*
    for(int a: A){
      cerr<<a<<" ";
    }cerr<<endl;
    */

    ll coins=0;
    for(int a: A){
      if (a<0) {
        coins-=a;
      }
    }
    cout<<coins<<endl;
  }
}
