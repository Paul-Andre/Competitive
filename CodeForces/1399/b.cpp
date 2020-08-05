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
    vector<ll> A(n);
    vector<ll> B(n);
    for(int i=0;i<n;i++){
      cin>>A[i];
    }
    for(int i=0;i<n;i++){
      cin>>B[i];
    }
    ll minA=1987654321;
    ll minB=1987654321;
    for(int i=0;i<n;i++){
      minA=min(minA,A[i]);
      minB=min(minB,B[i]);
    }
    ll tot = 0;
    for(int i=0;i<n;i++){
      tot+=max(A[i]-minA, B[i]-minB);
    }
    cout<<tot<<endl;
  }



}
