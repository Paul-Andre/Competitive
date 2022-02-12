#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
  int n;
  cin>>n;
  n-=2;
  vector<int> A(n);
  { int empty;cin>>empty; }
  for(auto&a:A)cin>>a;
  { int empty;cin>>empty; }
  int numEven =0;
  int numOdd =0;
  int numNonZeroEven =0;
  int numOddGe3 =0;
  bool haveOddGe5 = false;
  for(auto&a:A){
    if(a%2==0){
      numEven++;
      if (a!=0){
        numNonZeroEven++;
      }
    }else{
      numOdd++;
      if (a>=3) {
        numOddGe3++;
      }
      if (a>=5) {
        haveOddGe5=true;
      }
    }
  }
  bool good;
  bool funky = false;
  if (numEven == n) {
    good=true;
  } else if (numNonZeroEven>=1) {
    good=true;
  } else if (numOddGe3>=1) {
    if (numOdd>=2) {
      good=true;
    } else if (haveOddGe5) {
      if (n>=2) {
        good = true;
        funky = true;
      } else {
        good = false;
      }
    } else {
      good = false;
    }
  } else {
    good=false;
  }
  if (!good) {
    cout<<-1<<endl;
  } else {
    ll result = 0;
    for(auto&a:A){
      result+=a + (a%2);
    }
    result/=2;
    if (funky) {
      result+=1;
    }
    cout<<result<<endl;
  }
}








int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
