#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  ll n;
  cin>>n;
  ll r1,r2,r3;
  cin>>r1>>r2>>r3;
  ll d;
  cin>>d;
  vector<int> A(n);
  for(int i=0; i<n;i++){
    cin>>A[i];
  }
  if(r3<r1)r1=r3;
  if(r2<r1)r1=r2;
  vector<vector<ll>> T(n,vector<ll>(2,-1));
  {
    ll a = A[0];
    ll single =  r1*a + r3;
    ll dub = min(r1*a+r1, r2) + r1;
    T[0][0]=single;
    T[0][1]=dub+d*2;
  }
  for(int i=1;i<n;i++){
    ll a = A[i];
    ll single =  r1*a + r3;
    ll dub = min(r1*a+r1, r2) + r1;
    T[i][0]=min(T[i-1][1]+dub+d, min(T[i-1][0], T[i-1][1]) + single + d);
    T[i][1]=T[i-1][0]+dub+d*3;
  }
  ll tot;
  {
    ll a = A[n-1];
    ll single =  r1*a + r3;
    //ll dub = min(r1*a+r1, r2) + r1;
    tot=min(T[n-2][1]+single, min(T[n-1][1], T[n-1][0]));
  }
  cout<<tot<<endl;
}
