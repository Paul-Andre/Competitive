#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    if (n <= 30) {
      cout << "NO\n";
    } else if (n == 36) {
      cout << "YES\n";
      cout << "6 10 15 5\n";
      
    }else if (n == 40) {
      cout << "YES\n";
      cout << "6 10 15 9\n";
    }else if (n == 44) {
      cout << "YES\n";
      cout << "6 10 15 13\n";
    }else {
      cout << "YES\n";
      int k = n - 30;
      cout << "6 10 14 " << k <<endl;
    }
  }

}

