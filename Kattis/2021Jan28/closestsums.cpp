#include <bits/stdc++.h>
using namespace std;

int main(){
  int iii = 0;
  int n;
  while( cin>>n) {
    iii++;
    cout << "Case "<<(iii)<<":\n";
    vector<int> a(n);
    for(auto &aa: a) cin>>aa;
    int m;
    cin>>m;
    for (int i=0; i<m; i++) {
      int b;
      cin>>b;
      int closest = a[0]+a[1];
      for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
          int c= a[i]+a[j];
          if (abs(c-b) < abs(closest-b)){
            closest = c;
          }
        }
      }
    cout << "Closest sum to "<<(b)<<" is "<<closest<<".\n";
    }
  }
}







