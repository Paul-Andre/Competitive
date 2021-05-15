#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll M3[1123456];
ll M2[1123456];

void pre(){
  M2[2] = 1;
  for(int i=3; i<1123456; i++) {
    M2[i] = 1;
    M3[i] = 1;
    if (i%2==0) {
      M2[i] = max(M2[i], 1 + (M2[i/2-1]));
    }
    for(int j=3; j*j<=i; j++){
      if (i%j==0) {
        {
          ll k = j;
          M3[i] = max(M3[i], 1 + (M2[i/k-1]));
          M2[i] = max(M2[i], 1 + (M2[i/k-1]));
        }
        {
          ll k = i/j;
          M3[i] = max(M3[i], 1 + (M2[i/k-1]));
          M2[i] = max(M2[i], 1 + (M2[i/k-1]));
        }
      }
    }
  }
}

void solve(){
  int n;
  cin>>n;
  cout<<M3[n];
}

int main(){
  pre();
  int T;
  cin>>T;
  for(int ttt=1; ttt<=T; ttt++){
    cout << "Case #"<<ttt<<": ";
    solve();
    cout <<endl;
  }
}
