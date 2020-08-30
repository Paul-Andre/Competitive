#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    int n;
    cin>>n;
    map<char, int> m;
    for(int i=0;i<n;i++){
      string s;
      cin>>s;
      for(char c: s){
        m[c]++;
      }
    }
    bool good=true;
    for(pair<const char,int> &p: m){
      if (p.second%n!=0){
        good=false;
        break;
      }
    }
    if(good){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }
}
