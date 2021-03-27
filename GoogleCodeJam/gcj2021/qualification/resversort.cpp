#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin>>n;
  vector<int> A(n);
  for(auto &a: A)cin>>a;
  int tot = 0;
  for(int i=0; i<n-1; i++){
    int best_j = i;
    for(int j=i; j<n; j++){
      if (A[j] < A[best_j]) {
        best_j=j;
      }
    }
    int s = best_j-i+1;
    tot+=s;
    for(int k=0; k< s/2; k++){
      int tmp = A[i+k] ;
      A[i+k]= A[best_j-k];
      A[best_j-k]=tmp;
    }
  //for(auto &a: A)cerr<<a<<" ";cerr << ";\n";
  }

  //for(auto &a: A)cerr<<a<<" ";cerr << ";\n";

  cout<<tot;
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
