#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define cerr if(false)cerr
#endif
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;
  for (ll ttt=0; ttt<t; ttt++) {
    ll n;
    cin>>n;
    vector<ll> A(n);
    for(auto &x: A) cin>>x;

    vector<ll> lowest_index(n+1, -1);
    vector<ll> highest_index(n+1, -1);
    for (ll i=0; i<n; i++) {
      if (lowest_index[A[i]] == -1){
        lowest_index[A[i]] = i;
      }
      highest_index[A[i]] = i;
    }

    // ranges required to be covered at time t
    // (containing all i for A[i] <= t)
    vector<ll> required_left(n+1, -1);
    vector<ll> required_right(n+1, -1);
    {
      ll i = 1;
      required_left[i] = lowest_index[i];
      required_right[i] = highest_index[i];

    }

    for (ll i=2; i<=n; i++) {
      if (lowest_index[i] == -1) {
        required_left[i] = required_left[i-1];
      } else {
        if (required_left[i-1] == -1) {
          required_left[i] = lowest_index[i];
        } else {
          required_left[i] = min(required_left[i-1], lowest_index[i]);
        }
      }

      if (highest_index[i] == -1) {
        required_right[i] = required_right[i-1];
      } else {
        required_right[i] = max(required_right[i-1], highest_index[i]);
      }
    }
    for (ll i=n; i>=0; i--) {
      cerr<< i<<": "<<required_left[i] << " " << required_right[i]<<endl;
    }

    // At time t, the range of position at which the left side of conquered range can be placed,
    // so that the required ranges for all times >= t can be conquered
    vector<ll> possible_starts_left(n+1, -1);
    vector<ll> possible_starts_right(n+1, -1);
    possible_starts_left[n]=0;
    possible_starts_right[n]=0;

    bool impossible = false;
    for (ll i=n-1; i>=1; i--) {
      if (required_right[i] == -1) {
        assert(required_left[i]==-1);

        possible_starts_left[i] = possible_starts_left[i+1];
        possible_starts_right[i] = min(possible_starts_right[i+1]+1, n-1);

        continue;
      }
      ll length = required_right[i] - required_left[i] + 1;
      if (length > i) {
        impossible = true;
        break;
      }
      ll cur_starts_left = max(0ll, required_right[i]-i+1);
      ll cur_starts_right = min(required_left[i], n-i);

      assert(possible_starts_left[i+1] >= cur_starts_left-1);
      assert(possible_starts_right[i+1] <= cur_starts_right);

      cur_starts_left = max(cur_starts_left, possible_starts_left[i+1]);
      cur_starts_right = min(cur_starts_right, possible_starts_right[i+1]+1);

      possible_starts_left[i] = cur_starts_left;
      possible_starts_right[i] = cur_starts_right;
    }

    for (ll i=n; i>=0; i--) {
      cerr<< i<<": "<<possible_starts_left[i] << " " << possible_starts_right[i]<<endl;
    }
    if (impossible) {
      cout<<0<<endl;
    }else {
      cout<<(possible_starts_right[1]-possible_starts_left[1]+1)<<endl;
    }
  }
}





