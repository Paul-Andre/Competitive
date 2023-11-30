#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> operator+(const vector<ll> &a, const vector<ll> &b) {
  assert(a.size() == b.size());
  vector<ll> c(a.size());
  for (ll i=0; i<a.size(); i++) {
    c[i] = a[i] + b[i];
  }
  return c;
}
vector<ll> operator-(const vector<ll> &a, const vector<ll> &b) {
  assert(a.size() == b.size());
  vector<ll> c(a.size());
  for (ll i=0; i<a.size(); i++) {
    c[i] = a[i] - b[i];
  }
  return c;
}

int main() {
  int n,q;
  cin>>n>>q;
  vector<ll> A(n);
  for (auto &a: A) cin>>a;

  for (int qq=0; qq<q; qq++) {
    ll k;
    cin>>k;

    ll remained = k;
    ll result = 0;
    vector<ll> B(A);
    for (int i = 60; i>=0; i--) {
      ll target = 1ll << i;
      ll need = 0;
      
      for (int j=0; j<n; j++) {
        ll b = B[j];
        if (b & target) {

        } else {
          ll truncated = b & (target-1);
          ll add = target - truncated;
          need += add;
          //cerr << i<< " " <<j<< " " << add <<endl;
        }
        if (need > remained) {
          break;
        }
      }
      if (remained >= need) {
        //cerr << i << " " << need << endl;
        remained -= need;
        result += target;
        for (int j=0; j<n; j++) {

          ll b = B[j];
          if (b & target) {

          } else {
            ll truncated = b & (target-1);
            ll add = target - truncated;
            B[j] += add;
          }

        }
      }

    }

    cout<<result<<endl;
  }
}

