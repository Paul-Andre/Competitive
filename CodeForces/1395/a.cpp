#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int r,g,b,w;
    cin>>r>>g>>b>>w;
    int rr=r,gg=g,bb=b,ww=w;
    r%=2;
    g%=2;
    b%=2;
    w%=2;
    if(r+g+b+w==0 || r+g+b+w==1 || r+g+b+w==4 || (r+g+b+w==3 && rr>0&&gg>0&&bb>0)) {
      cout<<"Yes\n"; 

    } else {
      cout<<"No\n";
    }
  }
}
