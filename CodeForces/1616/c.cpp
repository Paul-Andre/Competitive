#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
  int n;
  cin>>n;
  vector<int> A(n);
  for(auto &a:A)cin>>a;
  int best = n-2;
  if (n==1){
    best= 0;
  }
  for(int u=0; u<n; u++) {
    for(int v=u+1; v<n; v++) {
      int n_changed = 0;
      for(int w=0; w<n; w++) {
        int a = A[u];
        int b = A[v];
        int c = A[w];
        if ((v-u)*c != (w-u)*(b-a) + (v-u)*a) {
          n_changed++;
        }
      }
      best = min(best, n_changed);
    }
  }
  cout<<best<<endl;
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
