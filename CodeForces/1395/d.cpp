#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n,d;
  ll m;
  cin>>n>>d>>m;
  vector<ll> big;
  vector<ll> small;
  for(int i=0; i<n;i++){
    int a;
    cin>>a;
    if(a>m){
      big.push_back(a);
    }else{
      small.push_back(a);
    }
  }
  sort(big.begin(),big.end());
  sort(small.begin(),small.end());
  /*
  for(int a:big){
    cerr << a<<" ";
  }cerr<<endl;
  for(int a:small){
    cerr << a<<" ";
  }cerr<<endl;
  */

  vector<ll> bigAcc=big;
  for(int i=1; i<bigAcc.size(); i++){
    bigAcc[i]+=bigAcc[i-1];
  }
  vector<ll> smallAcc=small;
  for(int i=1; i<smallAcc.size(); i++){
    smallAcc[i]+=smallAcc[i-1];
  }

  /*
  for(int a:bigAcc){
    cerr << a<<" ";
  }cerr<<endl;
  for(int a:smallAcc){
    cerr << a<<" ";
  }cerr<<endl;
  */

  ll totBig=0;
  ll totSmall=0;
  for(ll a:big){ totBig+=a; }
  for(ll a:small){ totSmall+=a; }
  ll bigAc=0;

  ll best=0;

  for(int numBS=0;numBS<big.size();numBS++){
    ll numBU;

    numBU=(numBS)/d+1;

    if(numBS+numBU>big.size())continue;

    ll smallNeed=(big.size()-numBS-numBU)*d;
    if(smallNeed>small.size()){continue;}

    int smallSac=0;
    if(smallNeed>0){
      smallSac=smallAcc[smallNeed-1];
    }

    ll smallCont = smallAcc.back()-smallSac;

    ll tot=totBig-bigAc + smallCont;

    best=max(tot, best);
    //
    //cerr << numBS << " " << numBU<< " " << smallNeed<< " " << smallCont << " " << (totBig-bigAc) << " " << tot << endl;

    bigAc+=big[numBS];
  }
  cout<<best<<endl;
}
