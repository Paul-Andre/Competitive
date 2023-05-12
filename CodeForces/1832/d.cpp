#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, q;
ll A[254321];
ll B[254321];
ll A_sum_down[254321];
ll B_min_up[254321];
ll B_sum_up[254321];

int main(){
  cin>>n>>q;

  for (int i=0; i<n; i++) {
    cin>>A[i];
  }
  sort(A, A+n);
  for (int i=0; i<n; i++) {
    B[i] = A[i]-i;
  }
  A_sum_down[n-1]= A[n-1];
  for (int i=n-2; i>=0; i--) {
    A_sum_down[i]= A_sum_down[i+1] + A[i];
  }

  B_min_up[0]= B[0];
  B_sum_up[0]= B[0];
  for (int i=1; i<n; i++) {
    B_min_up[i] = min(B_min_up[i-1], B[i]);
    B_sum_up[i] = B_sum_up[i-1] + B[i];
  }

  for(int qqq=0; qqq<q; qqq++){
    ll k;
    cin>>k;

    int to_sub;

    if (k <= n) {
      to_sub = k;
    } else {
      if (k%2 == n%2) {
        to_sub = n;
      } else {
        to_sub = n-1;
      }
    }

    ll min_from_B = B_min_up[to_sub-1]+k;
    ll sum_from_B = B_sum_up[to_sub-1]+k*to_sub;

    ll min_all;
    ll sum_all;
    if (to_sub < n) {
      ll min_from_A = A[to_sub];
      ll sum_from_A = A_sum_down[to_sub];

      min_all = min(min_from_B, min_from_A);
      sum_all = sum_from_B + sum_from_A;
    } else {
      min_all = min_from_B;
      sum_all = sum_from_B;
    }

    assert((k-to_sub)%2 == 0);
    ll pops = (k-to_sub)/2;

    ll to_equalize = sum_all - min_all*n;

    if (to_equalize >= pops) {
      cout << min_all << " ";
    } else {
      ll more = pops-to_equalize;
      if (more % n == 0) {
        cout << min_all - (more/n) << " ";
      } else {
        cout << min_all - (more/n) - 1 << " ";
      }
    }
  }
  cout <<endl;
}
