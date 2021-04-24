#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 998244353

ll brute(vector<ll> A){
  ll n = A.size();
  ll tot = 0;
  for(int k=0; k<(1<<n); k++){
    ll sum =0;
    vector<int> C;
    vector<int> P;
    for(int i=0; i<n; i++){
      if(k&(1<<i)){
        sum+=A[i];
        P.push_back(i);
      } else {
        sum-=A[i];
        C.push_back(i);
      }
    }
    bool good = true;
    if(sum<=0){
      good = false;
    }
    for(int i=1; i<(signed)C.size()-1; i++){
      if (C[i]-C[i-1] > C[i+1] - C[i]) {
        good=false;
      }
    }
    for(int i=1; i<(signed)P.size()-1; i++){
      if (P[i]-P[i-1] < P[i+1] - P[i]) {
        good=false;
      }
    }
    tot+=good;
  }
  return tot;
}

// solve the CCCCCPCPCPCPPPP part of the
// (P/C)CCCCCPCPCPCPPPP(P/C) case
// margin is the sum of what's on the ends
ll subsolve(vector<ll> A, ll margin){
  ll n = A.size();
  ll sum=0;
  for(int i=1; i<n-1; i++){
    sum+=A[i];
  }
  vector<ll> alterSum(n);
  for(int i=1; i<n-1; i++){
    if (i%2){
      alterSum[i] = alterSum[i-1]-A[i];
    } else{
      alterSum[i] = alterSum[i-1]+A[i];
    }
  }
  vector<ll> running(n);
  for(int i=1; i<n-1; i++){
    running[i] =running[i-1] + A[i];
  }





ll solve(vector<ll> A){
  ll n = A.size();
  ll sum=0;
  for(auto&a:A)sum+=a;

  vector<ll> forward(n,0);
  forward[0]=A[0];
  for(int i=1; i<n; i++){
    forward[i]=forward[i-1]+A[i];
  }

  ll tot = 0;

  ll running = -sum;
  for(int i=0;i<n;i++){
    running+=2*A[i];
    if(running>0){
      tot+=1;
    }
  }

  tot+=subsolve(A, A[0] + A.back());
  tot+=subsolve(A, A[0] - A.back());
  tot+=subsolve(A, -A[0] + A.back());
  tot+=subsolve(A, -A[0] - A.back());
  tot%=MOD;
  // CCCCC
  if(-sum > 0){
    tot-=-sum;
  }
  // PCCCC
  if(A[0]-sum > 0){
    tot-=A[0]-sum;
  }
  // PPPPC
  if(sum-A.back() > 0){
    tot-=sum-A.back();
  }
  // PPPPP
  if(sum > 0){
    tot-=sum;
  }
  // exactly PPCC (n=4)
  if(n==4 && A[0]+A[1]-A[2]-A[3]>0){
    tot-= A[0]+A[1]-A[2]-A[3];
  }
  tot%=MOD;
  tot+=MOD;
  tot%=MOD;
  return tot;
}


int main(){
  int t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    vector<ll> A(n);
    for(auto&a:A)cin>>a;
    ll res = solve(A);
    assert(res == brute(A));

    cout<<res<<endl;
  }
}




