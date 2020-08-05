#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    n=s.size();
    int fresh=1;
    vector<int> A[2];
    vector<int> ans;
    for(int i=0;i<n;i++){
      int a=s[i]=='1';
      int q;
      if(A[a].size()!=0){
        q=A[a].back();
        A[a].pop_back();
      }else{
        q=fresh;
        fresh++;
      }
      ans.push_back(q);
      A[1-a].push_back(q);
    }
    cout<<(fresh-1)<<endl;
    for(int x: ans){
      cout<<x<<" ";
    }
    cout<<endl;
  }
}

