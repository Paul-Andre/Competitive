#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  cout<<x<<" "<<y<<endl;
  cout<<1<<" "<<y<<endl;
  bool left=true;
  auto f=[x,y](int i, int j){
    if(!(i==x && j==y || i==1 && j==y)){
      cout<<i<<" "<<j<<endl;
    }
  };
  for(int i=1;i<=n;i++){
    if (left) {
      for(int j=1;j<=m;j++){
        f(i,j);
      }
      left=false;
    }else{
      for(int j=m;j>=1;j--){
        f(i,j);
      }
      left=true;
    }
  }
}
