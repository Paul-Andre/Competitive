#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
    

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  cin>>n;
  vector<ll> A(n);
  vector<ll> B(n);
  for(auto&a:A)cin>>a;
  for(auto&a:B)cin>>a;

  ll init=0;
  for(int i=0;i<n;i++){
    init+=A[i]*B[i];
  }

  ll best = init;
  for(int i=0; i<n; i++){
    ll current=init;
    int l=i;
    int r=i;
    for(; l>=0 && r<n; l--, r++){
      current-=A[l]*B[l];
      current-=A[r]*B[r];
      current+=A[l]*B[r];
      current+=A[r]*B[l];
      best=max(best, current);
    }
  }
  for(int i=0; i<n; i++){
    ll current=init;
    int l=i;
    int r=i+1;
    for(; l>=0 && r<n; l--, r++){
      current-=A[l]*B[l];
      current-=A[r]*B[r];
      current+=A[l]*B[r];
      current+=A[r]*B[l];
      best=max(best, current);
    }
  }
  cout<<best<<endl;
}
