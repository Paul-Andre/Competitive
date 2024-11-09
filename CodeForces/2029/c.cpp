#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  for (int ttt=0; ttt<t;ttt++) {
    int n;
    cin>>n;
    vector<int> A(n+1);
    A[0] = 0;
    for (int i=1; i<=n; i++) cin>>A[i];
    vector<int> maxFromLeft(n+1,0);
    maxFromLeft[0] = 0;
    int x = 0;
    for (int i=1; i<=n; i++) {
      int ai = A[i];
      if (ai>x) {
        x+=1;
      }else if (ai==x) {
      } else {
        x-=1;
      }
      maxFromLeft[i] = max(maxFromLeft[i-1], x);
    }

    // binary search
    int l = 0;
    int r = 300002;
    while(l+1<r) {
      int m = (l+r)/2;

      bool good = false;
      // trying to get at least m
      // iterating from the end
      int currentTarget = m;
      for (int i = n; i>=1; i--) {
        if (maxFromLeft[i-1]>= currentTarget) {
          good = true;
        }
        int ai = A[i];
        if (currentTarget > ai) {
          currentTarget += 1;
        } else if(currentTarget <= ai) {
          currentTarget -= 1;
        }
      }
      if (good) {
        l=m;
      } else {
        r = m;
      }
    }
    cout<<l<<endl;
  }
}

