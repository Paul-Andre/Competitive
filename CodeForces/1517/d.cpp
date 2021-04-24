#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,K;
// from (i,j) to (i,j+1)
ll A[502][502];
// from (i,j) to (i+1,j)
ll B[502][502];

ll C1[502][502];
ll C2[502][502];

typedef ll Wat[502][502];

Wat *C = &C1;
Wat *Cflip = &C2;

int main(){
  cin>>n>>m>>K;
  for(int i=1; i<=n;i++){
    A[i][0] = LLONG_MAX/2;
    for(int j=1; j<=m-1; j++){
      cin>>A[i][j];
    }
    A[i][m] = LLONG_MAX/2;
  }
  for(int j=1; j<=m; j++) {
    B[0][j] = LLONG_MAX/2;
  }
  for(int i=1; i<=n-1;i++){
    for(int j=1; j<=m; j++){
      cin>>B[i][j];
    }
  }
  for(int j=1; j<=m; j++) {
    B[n][j] = LLONG_MAX/2;
  }

  if(K%2){
    for(int i=1; i<=n;i++){
      for(int j=1; j<=m; j++){
        cout<<"-1 ";
      }
      cout <<endl;
    }
    return 0;
  }

  for(int k=0; k<K/2; k++){
    for(int i=1; i<=n;i++){
      for(int j=1; j<=m; j++){
        (*Cflip)[i][j] = min(
            min((*C)[i][j+1] + A[i][j],
              (*C)[i][j-1] + A[i][j-1]),
            min((*C)[i+1][j] + B[i][j],
              (*C)[i-1][j] + B[i-1][j]));
      }
    }
    {
      auto tmp = C;
      C = Cflip;
      Cflip = tmp;
    }
  }
  for(int i=1; i<=n;i++){
    for(int j=1; j<=m; j++){
      cout<<(*C)[i][j]*2 << " ";
    }
    cout <<endl;
  }
}




