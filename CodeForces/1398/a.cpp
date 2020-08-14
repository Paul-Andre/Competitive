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
    vector<pair<int,int>> A(n);
    for(int i=0;i<n;i++){
      cin>>A[i].first;
      A[i].second=i+1;
    }
    sort(A.begin(),A.end());
    if(A[0].first+A[1].first>A.back().first){
      cout<<"-1\n";
    }else{
      vector<int> res={A[0].second, A[1].second, A.back().second};
      sort(res.begin(), res.end());
      cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
    }
  }
}
