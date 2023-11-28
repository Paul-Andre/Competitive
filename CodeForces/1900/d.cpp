#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int t;
  cin>>t;
  for (int ttt=0; ttt<t;ttt++) {
    int n;
    cin>>n;
    vector<ll> A(n);
    for (auto &a: A) cin>>a;
    vector<ll> line_count(100001, 0);
    vector<ll> line_pos(100001, 0);
    sort(A.begin(), A.end());

    for (int i=0; i<A.size(); i++) {
      ll a = A[i];
      line_count[a]+=1;
      line_pos[a]=i;
    }

    vector<ll> line_num_gcd(100001, 0);

    for (int i=100000; i>0; i--) {
      // 1. Get all the triplets such that i is a divisor of f
      ll tot = 0;
      ll acc_left = 0;
      for (int j=i; j< 100001; j+=i) {
        for (int k=0; k<line_count[j]; k++) {
          ll acc_right = n - 1 - line_pos[j] + line_count[j] - 1 - k;
          tot += acc_right * acc_left;

          acc_left+=1;
        }
      }

      // 2. Subtract all the triplets that occur with an f > i
      for (int j=2*i; j< 100001; j+=i) {
        tot-=line_num_gcd[j];
      }
      line_num_gcd[i] = tot;
    }

    ll tot = 0;
    for (int i=100000; i>0; i--) {
      tot+= i*line_num_gcd[i];
    }
    cout<<(tot)<<endl;
  }
}
