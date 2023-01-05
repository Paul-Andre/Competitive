#include <bits/stdc++.h>
using namespace std;


int main() {
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    vector<int>P(n);
    for(auto&a:P)cin>>a;
    map<int, int> m;
    for (int i=n-1; i>=0; i--) {
      int p = P[i];
      auto it = m.lower_bound(p);
      if (it!=m.end()) {
        m[p] = it->second+1;
      } else {
        m[p] = 1;
      }
    }
    for (auto &kv: m){
      cerr<<kv.first<<":"<<kv.second<<" ";
    }cerr <<endl;
    /* int best = 1; */
    /* for (auto &kv: m){ */
    /*   best = max(best, kv.second); */
    /* } */
    int best = m[1];
    int to_move = n-best;
    int ops = to_move/k + !!(to_move%k);
    cout<<ops<<endl;
  }
}

