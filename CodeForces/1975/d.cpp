#include <bits/stdc++.h>
using namespace std;


int t;
int n;
int a,b;
vector<vector<int>> T;

vector<bool> vis;
vector<int> path;
int get_dist(int x) {
  if (vis[x]){
    return 0;
  }
  vis[x] = true;
  if (x == b){
    path.push_back(x);
    return 1;
  }
  for (int i=0; i<T[x].size(); i++) {
    int y = T[x][i];
    int r = get_dist(y);
    if (r) {
      path.push_back(x);
      return r+1;
    }
  }
  return 0;
}

int get_height(int x) {
  if (vis[x]){
    return 0;
  }
  vis[x] = true;
  int h = 1;
  for (int i=0; i<T[x].size(); i++) {
    int y = T[x][i];
    int r = get_height(y);
    h = max(h, r+1);
  }
  return h;
}


int main(){
  cin>>t;
  for (int ttt=0; ttt<t; ttt++) {
    cin>>n;
    T = vector<vector<int>>(n, vector<int>(0));
    cin>>a>>b;
    a-=1;
      b-=1;
    for (int i=0; i<n-1; i++) {
      int x,y;
      cin>>x>>y;
      x-=1;
      y-=1;
      T[x].push_back(y);
      T[y].push_back(x);
    }
    vis = vector<bool>(n, false);
    path = vector<int>();
    get_dist(a);

    for (auto a: path){
      //cerr<<a<<" ";
    }
    //cerr<<endl;


    int middle_pos = path.size()/2;
    int middle = path[middle_pos];

    vis = vector<bool>(n, false);
    int height = get_height(middle)-1;

    cout<<(n-1)*2-height+middle_pos<<endl;
  }

}

