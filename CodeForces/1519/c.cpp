#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool compareVec(const vector<ll> &a,
const vector<ll> &b){
  return a.size()>b.size();
}
    

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<vector<ll>> unis(n);
    {
      vector<ll> U(n);
      vector<ll> S(n);
      for(auto&a:U)cin>>a;
      for(auto&a:S)cin>>a;
      for(int i=0; i<n; i++){
        ll u=U[i];
        ll s=S[i];
        unis[u-1].push_back(s);
      }
    }

    sort(unis.begin(), unis.end(), compareVec);

    vector<vector<ll>> running(n);

    for(int j=0; j<unis.size();j++){
      auto&a=unis[j];
      sort(a.begin(), a.end());
      running[j].push_back(0);
      for(int i=0; i<unis[j].size(); i++) {
        running[j].push_back(running[j].back()+unis[j][i]);
      }
    }
    for(int i=1; i<=n; i++){
      ll tot=0;
      for(int j=0; j<running.size(); j++){
        ll s =running[j].size()-1;
        if(s<i){
          break;
        }
        tot+=running[j].back()-running[j][s%i];
      }
      cout<<tot<<" ";
    }
    cout <<endl;
  }

}
