#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int m = 0;
    for(int i=n-1; i>=0; i--) {
      if (s[i] == ')') {
        m++;
      }else{
        break;
      }
    }
    if (m > n/2) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
