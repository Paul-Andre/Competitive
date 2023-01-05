#include <bits/stdc++.h>
using namespace std;


int main() {
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    vector<int>P(n+1);
    vector<int>Q(n+1);
    for (int i=1; i<=n; i++){
      int p;
      cin>>p;
      P[i] = p;
      Q[p] = i;
    }

    int cnt = 1;
    int p = 1;
    int i = Q[p];
    while(true){
      int pp = p+1;
      if (pp>n) {
        break;
      }
      int ii = Q[pp];
      if (ii >= i) {
        cnt+=1;
        p = pp;
        i = ii;
        continue;
      } else {
        break;
      }
    }
    int to_move = n-cnt;
    int ops = to_move/k + !!(to_move%k);
    cout<<ops<<endl;
  }
}

