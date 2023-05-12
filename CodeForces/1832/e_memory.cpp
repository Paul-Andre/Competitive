#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll n, a1, x, y, m, K;
/* ll A[254321]; */
/* ll B[254321]; */
/* ll A_sum_down[254321]; */
/* ll B_min_up[254321]; */
/* ll B_sum_up[254321]; */
 
ll A[17654321];
ll B[6][17654321];
 
#define MOD 998244353
 
int main(){
  cin>>n>>a1>>x>>y>>m>>K;
  
  A[1] = a1;
  for (int i=2; i<=n; i++){
    A[i] = (A[i-1]*x + y)%m;
  }
  /* cerr <<"A: "; */
  /* for (int i=1; i<=n; i++){ */
  /*   cerr <<A[i]<<" "; */
  /* } */
  /* cerr<<endl; */
 
  n+=1;
 
  for (int i=1; i<=n; i++) {
    B[0][i] = B[0][i-1] + A[i];
    B[0][i]%=MOD;
  }
  for (int k=1; k<=K; k++) {
    for (int i=1; i<=n; i++) {
      B[k][i] = B[k][i-1] + B[k-1][i-1];
      B[k][i]%=MOD;
    }
  }
 
  /* for (int k=0; k<=K; k++) { */
  /*   cerr <<"B["<<k<<"]: "; */
  /*   for (int i=1; i<=n; i++){ */
  /*     cerr <<B[k][i]<<" "; */
  /*   } */
  /*   cerr<<endl; */
  /* } */
 
  ll out = 0;
  for(int i=1; i<=n; i++) {
    out ^= (B[K][i] * (i-1));
  }
  cout<<out<<endl;
 
}
