#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  for (int ttt=0; ttt<t; ttt++) {
    int n, k;
    cin>>n>>k;
    assert(k==1);
    vector<int> A(n);
    for (int i=0; i<n; i++) {
      cin>>A[i];
    }
    vector<int> P(k);
    for (int i=0; i<k; i++) {
      cin>>P[i];
      P[i]--;
    }
    int p = P[0];
    int x = A[p];

    int current = x;
    int i=0;
    int countBefore = 0;
    int countAfter = 0;
    while(i<=p) {
      if (A[i] != current) {
        current = A[i];
        countBefore++;
      }
      i++;
    }
    while(i<n) {
      if (A[i] != current) {
        current = A[i];
        countAfter++;
      }
      i++;
    }
    if (current != x) countAfter+=1;
    cout<<max(countBefore, countAfter)<<endl;
  }


}

