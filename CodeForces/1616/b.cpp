#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
  int n;
  cin>>n;
  string s;
  cin>>s;

  if (s[0] == s[1]) {
    cout<<s[0]<<s[1]<<endl;
    return;
  }

  int sol = n-1;
  for(int i=0; i<s.size()-1; i++){
    if(s[i+1]>s[i]){
      sol = i;
      break;
    }
  }
  string ss;
  for (int i=0; i<=sol; i++) {
    ss.push_back(s[i]);
  }
  for (int i=sol; i>=0; i--) {
    ss.push_back(s[i]);
  }
  cout<<ss<<endl;




}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();

  }
}
