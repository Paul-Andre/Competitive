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
    char c=s[n-1];
    for(int i=0;i<n;i++){
      cout<<c;
    }cout<<endl;
  }
}
