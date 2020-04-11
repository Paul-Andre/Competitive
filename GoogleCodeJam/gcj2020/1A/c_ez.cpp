#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int R, C;

void solve() {
  cin>>R>>C;
  vector<vector<ll>> S(R,vector<ll>(C,0));
  ll run = 0;
  ll tot = 0;
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      ll v;
      cin >> v;
      run+=v;
      S[i][j] = v;
    }
  }
  bool changed = true;
  vector<vector<ll>> cop = S;
  while(changed) {
    changed = false;
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        int self = S[i][j];


  }
  cout << tot << endl;
}


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int T;
  cin >> T;
  for(int i=1; i<=T; i++) {
    cout << "Case #" << i << ":  ";
    solve();
  }
}

