#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll A[254321];
ll C[254321];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n; 
  ll tot = 0;
  for (int i=0; i<n; i++) {
    cin >> A[i+1];
    tot += A[i+1];
    C[i+1] = tot;
  }
  tot = 0;
  ll cnt = 0;
  map<ll, ll> prev;
  for (int i=n; i>=0; i--) {
    ll v = C[i];
    if (prev.count(v)) {
      cnt = min(cnt + 1, prev[v] - i);
      //cerr << "yes " << endl;
    } else {
      cnt += 1;
    }
    prev[v] = i;
    //cerr << cnt-1 << endl;
    tot += (cnt-1);
  }
  cout << tot << endl;
}

