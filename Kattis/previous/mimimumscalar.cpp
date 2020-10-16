#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int kk;
  cin>>kk;
  for(int k=1; k<=kk; k++){
    int n;
    cin>>n;
    vector<ll> A(n);
    vector<ll> B(n);
    for(auto &a:A)cin>>a;
    for(auto &a:B)cin>>a;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll tot =0;
    for(int i=0;i<A.size();i++){
      tot += A[i] * B[A.size()-1-i];
    }
    cout << "Case #"<<k<<": "<<tot<<endl;
  }
}


