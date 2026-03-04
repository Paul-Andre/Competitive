#include <bits/stdc++.h>
using namespace std;

typedef long long ll;




int main() {
  int t;
  cin>>t;
  for (int ttt=0; ttt<t; ttt++) {
    ll n;
    cin>>n;
    vector<int> A(n);
    for(auto &a:A) cin>>a;

    int ni = -1;
    for (int i=0; i<n; i++) {
      if (A[i] == n) {
        ni = i;
        break;
      }
    }

    // B[i] = length of longest decreasing sequence contained within A[0]:A[i], that starts at the maximum within that range
    vector<int> B(A.size(),0);
    // C[i] = length of longest increasing sequence contained within A[i]:A[A.size()-1], that ends at the maximum within that range
    vector<int> C(A.size(),0);

    for(auto a: A) cerr<<a<<" ";
    cerr<<endl;

    {
      int running_max = -1;

      // D[i] = the length of the longest valid decreasing sequence that ends at value i
      map<int,int> D;

      for (int i=0; i<A.size(); i++) {


        int a = A[i];
        //cerr<<(a+1)<<" "<<n <<endl;
        int tv = tree.get(a+1, n);
        int val = tv + 1;
        tree.set(a, val);
        B[i] = val;
        if (i>0) {
          B[i] = max(B[i], B[i-1]);
        }
        cerr << B[i] << " ";
      }
      cerr<<endl;
    }
    {
      // tree[l, r] = longest decreasing sequence so far that ends between l and r
      Tree tree(1, n);

      for (int i=A.size()-1; i>=0; i--) {
        int a = A[i];
        int tv = tree.get(a+1, n);
        int val = tv + 1;
        tree.set(a, val);
        C[i] = val;
        if (i<C.size()-1) {
          C[i] = max(C[i], C[i+1]);
        }
        cerr << C[i] << " ";
      }
      cerr<<endl;
    }

    int longest = 0;
    for (int i=0; i<A.size()-1; i++) {
      longest = max(longest, B[i]+C[i+1]);
    }
    return longest;
}
  }
}
