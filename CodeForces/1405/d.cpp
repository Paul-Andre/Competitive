#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a,b,da,db;
vector<vector<int>> G;
vector<bool> vis;
int longestGlobal;

int findBob(int i){
  vis[i]=true;
  if(i==b)return 1;
  for(int j=0;j<G[i].size();j++){
    int u=G[i][j];
    if(!vis[u]){
      int f = findBob(u);
      if (f>0) {
        return f+1;
      }
    }
  }
  return 0;
}


int findLongest(int i){
  vis[i]=true;
  int longest=0;
  int secondLongest=0;
  for(int j=0;j<G[i].size();j++){
    int u=G[i][j];
    if(vis[u])continue;
    int l=findLongest(u);
    if(l>longest){
      secondLongest=longest;
      longest=l;
    }else if(l>secondLongest){
      secondLongest=l;
    }
  }
  longestGlobal=max(longestGlobal, longest+secondLongest+1);
  return longest+1;
}


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    cin>>n>>a>>b>>da>>db;
    G=vector<vector<int>>(n+1);
    vis=vector<bool>(n+1,false);
    for(int i=0; i<n-1; i++){
      int x,y;
      cin>>x>>y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    if(db<2*da+1){
      cout<<"Alice\n";
      continue;
    }
    int dist=findBob(a)-1;
    vis=vector<bool>(n+1,false);

    cerr<<"dist " << dist<<endl;
    if(dist<=da){
      cout<<"Alice\n";
      continue;
    }
    longestGlobal=0;
    findLongest(1);
    cerr<<"longest " << longestGlobal<<endl;
    if(longestGlobal>=2*da+2){
      cout<<"Bob\n";
    }else{
      cout<<"Alice\n";
    }
  }
}
