#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T[201][201][201];

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int Rn,Gn,Bn;
  cin>>Rn>>Gn>>Bn;
  vector<int> R(Rn);
  vector<int> G(Gn);
  vector<int> B(Bn);
  for(int &a:R){
    cin>>a;
  }
  for(int &a:G){
    cin>>a;
  }
  for(int &a:B){
    cin>>a;
  }
  sort(R.begin(),R.end(), greater <int>());
  sort(G.begin(),G.end(), greater <int>());
  sort(B.begin(),B.end(), greater <int>());
  ll tot=0;
  for(int i=0;i<R.size()+1;i++){
    for(int j=0;j<G.size()+1;j++){
      for(int k=0;k<B.size()+1;k++){
        ll rg=0,rb=0,gb=0;
        if(i>=1&&j>=1){
          rg=T[i-1][j-1][k]+R[i-1]*G[j-1];
        }
        if(i>=1&&k>=1){
          rb=T[i-1][j][k-1]+R[i-1]*B[k-1];
        }
        if(j>=1&&k>=1){
          gb=T[i][j-1][k-1]+G[j-1]*B[k-1];
        }
        T[i][j][k]=max(max(rg,rb),gb);
        tot=max(tot,T[i][j][k]);
      }
    }
  }
  cout<<tot<<endl;
}
