#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif

#define wew (-0xffffffff)


ll S;
ll A[100003][2];

ll distance_single[100003][2];
ll distance_double[100003][2];

ll other_values[100003][2];

void solve() {
  cin >> S;
  for (int i=0; i<S; i++) {
    ll a,b,d;
    cin >>d>>a>>b; 
    A[i][0] = d + a;
    A[i][1] = d - b;
  }

  /*
  for (int i=0; i<S; i++) {
    cerr << A[i][0] << " ";
  } cerr <<endl;
  for (int i=0; i<S; i++) {
    cerr << A[i][1] << " ";
  } cerr <<endl;
  */

  other_values[0][0] = other_values[0][1] = wew;
  distance_single[0][0] = distance_single[0][1] = 1;
  distance_double[0][0] = distance_double[0][1] = 1;

  for (int i=1; i<S; i++) {
    for (int j=0; j<2; j++) {
      if (A[i][j] == A[i-1][j]) {
        other_values[i][j] = other_values[i-1][j];
        distance_single[i][j] = distance_single[i-1][j] + 1;
        distance_double[i][j] = distance_double[i-1][j] + 1;
      } else {
        other_values[i][j] = A[i-1][1-j];
        distance_single[i][j] = 1;
        if (other_values[i-1][1-j] == A[i][j]) {
          distance_double[i][j] = distance_double[i-1][1-j] + 1;
        } else {
          distance_double[i][j] = distance_single[i-1][1-j] + 1;
        }
      }
    }
  }

  ll m = 0;
  for (int i=0; i<S; i++) {
    m  = max(m, distance_double[i][0]);
    m  = max(m, distance_double[i][1]);
    m  = max(m, distance_single[i][0]);
    m  = max(m, distance_single[i][1]);
  }

  ll tot = 0;
  for (int i=0; i<S; i++) {
    if (
    m  == ( distance_double[i][0]) ||
    m == ( distance_double[i][1]) ||
    m == ( distance_single[i][0]) || 
    m == ( distance_single[i][1]) ) {
      tot += 1;

    }

  }
  cout << m << " " << tot << endl;
}

int main() {

#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif

  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cout << "Case #"<<t<<": ";
    solve();

  }
}

