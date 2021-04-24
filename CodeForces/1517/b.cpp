#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int t;
  cin>>t;
  while(t--){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll, pair<ll,ll>>> sorted;
    vector<vector<ll>> b(n, vector<ll>(m));
    for(int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        ll a;
        cin>>a;
        b[i][j] = a;
        sorted.push_back(make_pair(a, make_pair(i, j)));
      }
    }
    sort(sorted.begin(), sorted.end());

    vector<vector<ll>> out(n, vector<ll>(m, 0));

    for(int i=1; i<=m; i++) {
      ll x = sorted[i-1].second.first;
      ll y = sorted[i-1].second.second;
      out[x][y] = i;
    }
    for(int i=0; i<n; i++) {
      vector<bool> c(m+1, false);
      for (int j=0; j<m; j++) {
        if (out[i][j]){
          c[out[i][j]] = true;
        }
      }
      
      int k=1;
      for (int j=0; j<m; j++) {
        while(c[k]){
          k++;
        }
        if(out[i][j]) continue;
        out[i][j] = k;
        k++;
      }
    }


    for(int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        //cerr<<out[i][j]<<" ";
      }
      //cerr<<endl;
    }
    for(int i=0; i<n; i++) {
      vector<ll> length(m+1, 0);
      for (int j=0; j<m; j++) {
        length[out[i][j]] = b[i][j];
      }
      for (int j=1; j<=m; j++) {
        cout<<length[j]<<" ";
      }
      cout<<endl;
    }
  }
}




