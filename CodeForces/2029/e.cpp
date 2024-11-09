#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> divisor(412345, 0);
  for (int i=2; i<412345; i++) {
    if (divisor[i]!=0) continue;
    for (int ii=i; ii<412345; ii+=i) {
      if (divisor[ii] == 0) {
        divisor[ii] = i;
      }
    }
  }
  vector<bool> prime(412345, false);
  for (int i=2; i<412345; i++) {
    prime[i] = divisor[i] == i;
  }

  int t;
  cin>>t;
  for (int ttt=0; ttt<t;ttt++) {
    int n; 
    cin>>n;
    vector<int> A(n);
    for(auto&a:A) cin>>a;
    int np = 0;
    int p = -1;
    for (auto a: A) {
      np+=prime[a];
      if (prime[a]) {
        p = a;
      }
    }
    if (np > 1) {
      cout<<-1<<endl;
    } else if (np == 0) {
      cout<<2<<endl;
    } else {
      bool good = true;
      for (auto a: A) {
        if (a!=p and a/divisor[a]<p) {
          good = false;
          break;
        }
      }
      if (good) {
        cout<<p<<endl;
      }else {
        cout<<-1<<endl;
      }
    }
  }
}

