#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    bool good=true;

    for(int i=0; i<k; i++){
      char what = '?';
      for(int j=i;j<n;j+=k){
        if (what=='?') {
          what=s[j];
        }else if(s[j]!='?' && what!=s[j]){
          good=false;
          goto finish;
        }
      }
      for(int j=i;j<n;j+=k){
        s[j]=what;
      }
    }
    {
    int have=0;
    int questions=0;
    for(int i=0; i<k; i++){
      if(s[i]=='?'){
        questions++;
      }else if (s[i]=='1'){
        have++;
      }
    }
    if(have > k/2 || have+questions<k/2){
      good=false;
    }
    }


finish:
    if(good){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }
}
