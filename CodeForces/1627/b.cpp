#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n,m;
  cin>>n>>m;
  vector<int> dists;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      int maxDist = 
        max (
            max (
              abs(i-0) + abs(j-0),
              abs(i-n+1) + abs(j-0)
              ),
            max (
              abs(i-0) + abs(j-m+1),
              abs(i-n+1) + abs(j-m+1)
              )
            );
      dists.push_back(maxDist);
    }
  }
  sort(dists.begin(), dists.end());
  for (int a : dists) {
    cout<<a<<" ";
  }
  cout<<endl;
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
