#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> G;
vector<bool> vis;
vector<ll> P;
vector<ll> PP;
vector<ll> H;
vector<ll> HH;

bool solve(int i){
  vis[i] = true;
  ll child_happy = 0;
  PP[i] = P[i];
  for(int j=0; j<G[i].size(); j++) {
    int u = G[i][j];
    if (vis[u]) continue;
    if(!solve(u)){
      return false;
    }
    child_happy+= HH[u];
    PP[i] += PP[u];
  }
  ll a2 = PP[i]+H[i];
  if (a2%2!=0){
    return false;
  }
  if (a2/2 > PP[i]){
    return false;
  }
  HH[i] = a2/2;
  if (HH[i] < child_happy){
    return false;
  }
  return true;
}



int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    G = vector<vector<int>>(n+1);
    vis = vector<bool>(n+1,false);
    P = vector<ll>(n+1,0);
    PP = vector<ll>(n+1,0);
    H = vector<ll>(n+1,0);
    HH = vector<ll>(n+1,0);

    for(int i=1; i<=n; i++) {
      cin>>P[i];
    }
    for(int i=1; i<=n; i++) {
      cin>>H[i];
    }
    for(int i=0; i<n-1; i++) {
      int x,y;
      cin>>x>>y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    if(solve(1)){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }

  }
}

