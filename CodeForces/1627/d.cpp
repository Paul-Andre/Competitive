#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//#define N 50
#define N 1654321


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  cin>>n;
  vector<int> picked(N, 0);
  for(int i=0; i<n; i++) {
    int x;
    cin>>x;
    picked[x] = 1;
  }

  for (int i=N-1; i>=1; i--) {

    int found_count = 0;
    for (int ii=i*2; ii<N; ii+=i) {
      if (picked[ii]) {
        //cerr << i<< " "<<ii<<" " << found_count<<endl;
        found_count++;
      }
    }

    //cerr << i<< " " << found_count<<endl;

    bool had_gcd_already = false;
    for (int ii=i*2; ii<N; ii+=i) {
      if (picked[ii] == found_count) {
        had_gcd_already = true;
      }
    }

    if (picked[i] || (found_count && !had_gcd_already)) {
      picked[i] = found_count + 1;
    }
  }
  int n_picked = 0;
  for (int i=N-1; i>=1; i--) {
    if (picked[i]) n_picked++;
  }

  cout <<(n_picked - n)<<endl;
  for (int i=0; i<20; i++) {
    cerr << picked[i]<< " ";
  }cerr<<endl;
}
