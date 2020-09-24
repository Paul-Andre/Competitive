#include <bits/stdc++.h>
using namespace std;

#define M 998244353ll

typedef long long ll;

ll mpow(ll b, ll c, ll m=M){
  assert(c>=0);
  b%=m;

  ll acc=1;

  while(c!=0){
    if(c%2 == 0){
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

ll minv(ll a, ll m=M){
  //cerr << "minv " << a <<" " << m << endl;
  a%=m;
  assert(a!=0);
  return mpow(a, m-2, m);
}

int main() {
  /*
  cerr << mpow(2, M-2, M)<<endl;
  cerr << ((2ll * minv(2,M))%M) <<endl;
  cerr << ((minv(2))) <<endl;
  */
  int n, k;
  cin>>n>>k;
  vector<pair<int,bool>> P;
  for(int i=0; i<n; i++){
    int l,r;
    cin>>l>>r;
    P.emplace_back(l, 0);
    P.emplace_back(r, 1);
  }
  sort(P.begin(), P.end());

  ll coeff = 1;

  ll current = 0;
  ll tot=0;

  for(int i=0;i<P.size();i++){
    //int p=P[i].first;
    bool right=P[i].second;

    if (!right) {
      current++;
    }else{
      current--;
    }

    if (current == k) {
      coeff = 1;
    } else if (current > k){
      if (!right) {
        coeff *= (current-1);
        coeff %= M;
        coeff *= minv(current-1-(k-1));
        coeff %= M;
        //cerr << "sdfasdf " << (current -1) << " " << (current -1-(k-1))<<endl;
      } else {
        coeff *= minv(current);
        coeff %= M;
        coeff *= current-(k-1);
        coeff %= M;
      }
    } else if (current < k) {
      coeff = 0;
    }
    //cerr << "coeff = " << coeff <<endl;
    if (!right) {
      tot+=coeff;
      tot%=M;
    }
  }
  cout << tot<<endl;
}
