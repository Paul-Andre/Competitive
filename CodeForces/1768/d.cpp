#include <bits/stdc++.h>
using namespace std;


int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>P(n+1,0);
    for (int i=1; i<=n; i++){
      int p;
      cin>>p;
      P[i] = p;
    }
    vector<bool> vis(n+1, 0);
    bool have = false;
    long long tot = 0;
    for (int i=1; i<=n; i++) {
      if (not vis[i] and P[i]!=i ){
        int j = i;
        vector<int> cyc;
        while(true){
          vis[j] = true;
          cyc.push_back(j);
          int jj = P[j];
          tot+=1;
          if (jj == i){
            tot-=1;
            break;
          }
          j=jj;
        }
        sort(cyc.begin(), cyc.end());
        for (int i=0; i<cyc.size()-1; i++) {
          if (cyc[i+1]==cyc[i]+1){
            have = true;
          }
        }
      }
    }
    // cerr <<tot<<" " <<have<<endl;
    cout<<tot+(1-2*have)<<endl;
  }
}

