#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    int n;cin>>n;
    vector<int> P(n);
    for(int &p: P){
      cin>>p;
    }
    for(int i=n-1;i>=0;i--){
      cout<<P[i]<<" ";
    }
    cout<<endl;
  }
}
