#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin>>n;
    vector<ll> A(n);
    for(int i=0;i<n;i++){
      cin>>A[i];
    }
    sort(A.begin(),A.end());
    ll best=0;
    for(ll a: A){
      best+=(a-1);
    }
    for(ll c=2;c<100000;c++){
      ll tot=0;
      ll acc=1;
      for(ll a: A){
        tot+=abs(a-acc);
        acc*=c;
        if(tot >= best)break;
      }
      if(tot<best){
        best=tot;
      }
    }
    cout<<best<<endl;
}
