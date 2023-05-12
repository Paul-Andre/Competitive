#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, a1, x, y, m, K;

ll A[17654321];
//ll B[7][17654321];

#define MOD 998244353

int main(){
  cin>>n>>a1>>x>>y>>m>>K;
  
  A[1] = a1;
  for (int i=2; i<=n; i++){
    A[i] = (A[i-1]*x + y)%m;
  }

  n+=1;

  for (int i=1; i<=n; i++) {
    A[i] = A[i-1] + A[i];
    A[i]%=MOD;
  }

  for (int k=1; k<=K; k++) {
    for (int i=1; i<=n; i++) {
      A[i] = A[i-1] + A[i];
      A[i]%=MOD;
    }

  }

  n -=1;
  ll out = 0;
  for(int i=1; i<=n - (K-1); i++) {
    out ^= (A[i] * (i + (K-1)));
  }
  cout<<out<<endl;

}
