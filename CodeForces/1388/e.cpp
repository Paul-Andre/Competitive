#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Segment{
  int l, r, y;
};

struct Frac{
  ll num;
  ll denom;
  Frac(ll n, ll d) {
    assert(d!=0);
    ll g = __gcd(n, d);
    n/=g;
    d/=g;
    if(d<0){
      n*=-1;
      d*=-1;
    }
    num = n;
    denom = d;
  }
};

bool operator<(Frac a, Frac b){
  return a.num*b.denom < a.denom * b.num;
}


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  cin>>n;
  vector<Segment> A;
  for(int i=0;i<n;i++){
    Segment s;
    cin>>s.l>>s.r>>s.y;
    A.push_back(s);
  }
  vector<pair<Frac,Frac>> B;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j)continue;
      Segment a = A[i];
      Segment b = A[j];
      if(a.y==b.y)continue;
      if(a.y<b.y){
        Segment t = a;
        a=b;
        b=t;
      }
      Frac x(b.r-a.l, a.y-b.y);
      Frac y(b.l-a.r, a.y-b.y);
      B.emplace_back(x,y);
    }
  }
}

