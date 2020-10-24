#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cb, cp;
    cin>>n>>cb>>cp;
    int totb = 0;
    int totp = 0;
    for (int i=0; i<n; i++) {
      int b, p;
      cin>>b>>p;
      totb += b;
      totp += p;
    }
    cout << ((totb+9)/10)*cb + ((totp+9)/10)*cp << endl;
}
