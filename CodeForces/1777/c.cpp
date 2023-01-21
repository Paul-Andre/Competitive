#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007

vector<int> divisors[112345];

int main() {
  for (int i=1; i<112345; i++){
    for (int j=i; j<112345; j+=i){
      divisors[j].push_back(i);
    }
  }
  /* int ml=0; */
  /* for (auto &v: divisors){ */
  /*   ml= max(ml, int(v.size())); */
  /* } */
  /* cerr<<ml<<endl; // prints 144 */

  int t;
  cin>>t;
  for(int ttt=0; ttt<t; ttt++){
    int n,m;
    cin>>n>>m;
    vector<int> A(n);
    for(auto&a:A)cin>>a;

    sort(A.begin(), A.end());

    vector<int> cover(112345, 0);
    int has = 0;
    int l=0, r = -1;
    int best = 112345;
    
    while(r<n){
      if (has < m) {
        r+=1;
        if (r>=n) break;
        for (auto d: divisors[A[r]]){
          if (d<=m){
            if (cover[d]==0){
              has+=1;
            }
            cover[d]+=1;
          }
        }
      } else {
        best = min(best, A[r]-A[l]);
        if (best == 0) {
          break;
        }
        for (auto d: divisors[A[l]]){
          if (d<=m){
            cover[d]-=1;
            if (cover[d]==0){
              has-=1;
            }
          }
        }
        l+=1;
      }
    }
    if (best == 112345){
      best = -1;
    }
    cout<<best<<endl;
  }
}


