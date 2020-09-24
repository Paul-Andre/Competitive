#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mpow(ll b, ll c, ll m){
  assert(c>=0);
  ll acc=1;
  b%=m;
  while(c!=0){
    if(c%2==0){
      c/=2;
      b=(b*b)%m;
    }else{
      c-=1;
      acc=(acc*b)%m;
    }
  }
  acc=(acc+m)%m;
  return acc;
}

ll minv(ll a, ll m){
  cerr << "minv " << a <<" " << m << endl;
  a%=m;
  assert(a!=0);
  return mpow(a, m-2, m);
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  ll n;
  cin>>n;
  vector<ll> A(n);
  for(ll i=0;i<n;i++){
    cin>>A[i];
  }
  if(n==1){
    cout<<"1 1\n"<<(-A[0])<<endl;
    cout<<"1 1\n"<<(0)<<endl;
    cout<<"1 1\n"<<(0)<<endl;
    return 0;
  }
  if(n>=2){
    cout<<"1 1\n"<<(-A[0])<<endl;
    cout<<"2 "<<n<<"\n";
    for(int i=1;i<n;i++){
      cout<< A[i]*(n-1) <<" ";
    }
    cout<<endl;
    cout<<"1 "<<n<<" \n0 ";
    for(int i=1;i<n;i++){
      cout<< -A[i]*n <<" ";
    }
    cout<<endl;
    return 0;
  }
}
