#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const ll inv100 = 570000004;


ll mpow(ll b, ll c, ll m=MOD){
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

ll minv(ll a, ll m=MOD){
  //cerr << "minv " << a <<" " << m << endl;
  a%=m;
  assert(a!=0);
  return mpow(a, m-2, m);
}



void solve(){
    ll n,m,rb,cb,rd,cd,p;
    cin>>n>>m>>rb>>cb>>rd>>cd>>p;
    ll r = rb;
    ll c = cb;
    ll dr=1;
    ll dc=1;

    {
        ll rr=r+dr;
        ll cc=c+dc;
        if (rr<1 or rr>n) {
            dr*=-1;
        }
        if (cc<1 or cc>m) {
            dc*=-1;
        }
    }

    ll initDr = dr;
    ll initDc = dc;

    ll constN = 0;
    ll multN = 1;

    while(true) {
        if (r==rd || c==cd){
            // mult += (1-p)
            multN *= (100-p);
            multN %= MOD;
            multN *= inv100;
            multN %= MOD;
        }

        constN += multN;
        constN %= MOD;

        r = r+dr;
        c = c+dc;
        {
            ll rr=r+dr;
            ll cc=c+dc;
            if (rr<1 or rr>n) {
                dr*=-1;
            }
            if (cc<1 or cc>m) {
                dc*=-1;
            }
        }
        if (r == rb && c==cb && dr==initDr && dc==initDc){
            break;
        }
    }

    // x = a + bx
    // x = a/(1-b)


    ll ii = (1-multN);
    ii%=MOD;
    ii+=MOD;
    ii%=MOD;
    ll iii = minv(ii);

    ll ans = constN * iii;
    ans %= MOD;
    ans+=MOD;
    ans%=MOD;
    cout<<ans<<endl;
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int ttt;
    cin>>ttt;
    while(ttt--){
        solve();
    }
}
