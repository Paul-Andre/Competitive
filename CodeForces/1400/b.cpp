#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int p,f;
    cin>>p>>f;
    int cs,cw;
    cin>>cs>>cw;
    int s,w;
    cin>>s>>w;
    if(s > w){
      int tmp=s;
      s=w;
      w=tmp;

      tmp=cs;
      cs=cw;
      cw=tmp;
    }
    if(f > p){
      int tmp=f;
      f=p;
      p=tmp;
    }
    int best=0;
    for(int ps=0;ps<=cs;ps++){
      if(ps*s > p) break;
      int fs = min(cs-ps, f/s);
      int prem=p-ps*s;
      int frem=f-fs*s;
      int pwp=prem/w;
      int fwp=frem/w;
      int tot=min(pwp+fwp,cw)+ps+fs;
      best=max(best,tot);
    }
    cout<<best<<endl;
  }
}
