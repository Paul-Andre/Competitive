#include <bits/stdc++.h>
using namespace std;

void solve(){
  int x, y;
  string s;
  cin>>x>>y>>s;
  int n = s.size();
  vector<int> Tc(n,1000*100*20);
  vector<int> Tj(n,1000*100*20);
  if (s[0] == 'C'){
    Tc[0] = 0;
  }
  if (s[0] == 'J'){
    Tj[0] = 0;
  }
  if (s[0] == '?'){
    Tc[0] = 0;
    Tj[0] = 0;
  }
  for (int i=1; i<n; i++){
    char c= s[i];
    if (c == 'J'){
      Tj[i] = min(Tc[i-1] + x, Tj[i-1]);
    }
    if (c == 'C'){
      Tc[i] = min(Tc[i-1], Tj[i-1] + y);
    }
    if (c == '?'){
      Tj[i] = min(Tc[i-1] + x, Tj[i-1]);
      Tc[i] = min(Tc[i-1], Tj[i-1] + y);
    }
  }
  /*
  for(auto &a:Tc)cerr<<a<<" ";
  cerr<<endl;
  for(auto &a:Tj)cerr<<a<<" ";
  cerr<<endl;
  */
  cout << min(Tj[n-1], Tc[n-1]);

}



int main(){
  int T;
  cin>>T;
  for(int ttt=1; ttt<=T; ttt++){
    cout << "Case #"<<ttt<<": ";
    solve();
    cout <<endl;
  }
}
