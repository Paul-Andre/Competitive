#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
  string s;
  int n = 0;
  cin>>s;
  n = s.size();
  vector<int> digs;
  for (char c: s){
    digs.push_back(c-'0');
  }
  int lastPos = 0;
  for (int i=0; i<n-1; i++) {
    int x = digs[i];
    int y = digs[i+1];
    if (x + y >= 10) {
      lastPos = i;
    }
  }
  string ans;
  for (int i=0; i<n; i++) {
    if (i != lastPos) {
      cout<<digs[i];
    } else {
      cout<<(digs[i] + digs[i+1]);
        i++;
    }
  }
  cout<<endl;

}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
