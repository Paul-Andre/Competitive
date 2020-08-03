#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> b(n);
    vector<bool> seen(n+2,false);
    for(int i=0;i<n;i++){
      int a;
      cin>>a;
      b[i]=a;
      seen[a]=true;
    }
    int filler=0;
    for(int i=1;i<=n+1;i++){
      if(!seen[i]){
        filler=i;
        break;
      }
    }
    assert(filler!=0);
    map<int,int> v;
    for(int i=0;i<n;i++){
      v[b[i]]++;
    }
    int f = n-y;
    int r = f+x;
    int z = y-x;
    int biggest = 0;
    bool bad=false;
    for(auto &p: v){
      if(v.second - r > z/2){
        bad=true;
      }
    }
    if(v.size() == 2 && (n-r)%2==1){
      bad=true;
    }
    if(bad){
      cout<<"NO\n";
      continue;
    }

  }
}

