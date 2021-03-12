#include <bits/stdc++.h>
using namespace std;

int n,k;

int unlikeliness(string &a, string &b){
  int tot =0;
  for (int i=0; i<k; i++){
    if (a[i]!=b[i]){
      tot+=1;
    }
  }
  return tot;
}

int main(){
  cin>>n>>k;
  vector<string> A(n);
  for(auto&a:A)cin>>a;
  vector<bool> vis(n,false);
  int tot_unl = 0;
  vector<pair<int,int>> ans;

  priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;

  vis[0] = true;
  for (int j=0; j<n; j++){
    if (!vis[j]){
      q.push(make_tuple(unlikeliness(A[0], A[j]), 0, j));
    }
  }

  while(q.size()){
    auto [dist, x, y] = q.top();
    q.pop();
    if (not vis[y]){
      vis[y] = true;
      tot_unl += dist;
      ans.emplace_back(x,y);
      for (int j=0; j<n; j++) {
        if (not vis[j]){
          q.push(make_tuple(unlikeliness(A[y], A[j]), y, j));
        }
      }
    }
  }

  cout << tot_unl<<endl;
  for (auto p : ans){
    cout << p.first << " " << p.second <<endl;
  }
}



  




