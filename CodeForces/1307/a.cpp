#include <bits/stdc++.h>
using namespace std;

int A[200];

int main() {
  int t;
  cin >> t;
  for(int iii=0; iii<t; iii++) {
    int n,d;
    cin >> n >> d;
    for (int i=0;i<n; i++) {
      cin >> A[i];
    }
    for (int i=1; i<n; i++) {
      while (d >= i && A[i] != 0) {
        A[0] +=1;
        A[i]-=1;
        d-=i;
      }
    }
    cout << A[0] <<endl;
  }
}
