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
    int a = n/4;
    if (n%4!=0){
      a++;
    }
    int m = n-a;
    for(int i=0;i<m;i++){
      cout <<'9';
    }
    for(int i=0;i<a;i++){
      cout <<'8';
    }
    cout <<endl;
  }
}

