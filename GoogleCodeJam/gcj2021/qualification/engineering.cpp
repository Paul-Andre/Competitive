#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n, c;
  cin>>n>>c;
  vector<int> A(n);

  if (c<n-1 || c > (n+1)*n/2 -1) {
    cout << "IMPOSSIBLE";
    return;
  }

  int rem_c = c-n+1;

  for (int i=0; i<n; i++) {
    A[i]= i+1;
  }

  for(int i=n-2; i>=0; i--){
    int max_s = n-i;
    int s = min(rem_c, max_s-1)+1;

    rem_c-=s-1;

    int best_j=i+s-1;

    for(int k=0; k< s/2; k++){
      int tmp = A[i+k] ;
      A[i+k]= A[best_j-k];
      A[best_j-k]=tmp;
    }
  }

  for(auto &a: A)cout<<a<<" ";

}



int main(){
  int T;
  cin>>T;
  for(int ttt=1; ttt<=T; ttt++){
    cout << "Case #"<<ttt<<": ";
    solve();
    cout <<endl;
  }
}
