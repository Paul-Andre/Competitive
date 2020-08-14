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
    vector<int> A(n);
    for(int &a:A){
      char c;
      cin>>c;
      a=(c-'0')-1;
    }
    map<int,int> M;
    int current=0;
    ll tot=0;
    M[0]=1;
    for(int a:A){
      current+=a;
      tot+=M[current];
      M[current]++;
    }
    cout<<tot<<endl;
  }

}
