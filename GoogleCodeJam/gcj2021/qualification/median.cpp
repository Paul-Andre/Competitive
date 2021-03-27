#include <bits/stdc++.h>
using namespace std;
int t,n,q;
vector<int> have;

int locate(int x, int a, int b){
  int s = b-a+1;
  int inc = (s-2)/3;
  int u,v;
  if((s-2)%3 == 0){
    u = a + inc;
    v = u +  1 + inc;
  }
  else if((s-2)%3 == 1){
    u = a + inc + 1;
    v = u +  1 + inc;
  }
  else { // ((s-2)%3 == 2){
    u = a + inc + 1;
    v = u + 2 + inc;
  }
  cout<<have[u]<<" " << have[v]<<" "<< x <<endl;
  int y;
  cin>>y;
  int na;
  int nb;
  if (y == have[u]) {
    na = a;
    nb = u-1;
  } else if (y == x) {
    na = u+1;
    nb = v-1;
  }else { // y == have[v]
    na = v+1;
    nb = b;
  }
  if (na>nb) {
    return na;
  }
  if (na==nb) {
    if (nb<have.size()-1) nb+=1;
    else na-=1;
  }
  return locate(x, na, nb);
}

void solve(){

  cout<<"1 2 3"<<endl;
  int a;
  cin>>a;
  if(a ==1){
    have = {2, 1, 3};
  }
  if(a ==2){
    have = {1, 2, 3};
  }
  if(a ==3){
    have = {1, 3, 2};
  }
  for(int i=4; i<=n; i++){
    int pos = locate(i, 0, have.size()-1);
    have.insert(have.begin()+pos, i);
  }
  for(auto&a:have)cout<<a<<" ";

  cout<<endl;
  cin>>a;

}

int main(){
  cin>>t>>n>>q;
  for(int i=0; i<t; i++){
    solve();
  }
}


