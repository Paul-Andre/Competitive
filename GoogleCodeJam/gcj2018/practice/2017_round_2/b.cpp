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




void solve() {
  int N;
  int C;
  int M;
  cin>>N>>C>>M;
  int want_first = 0;
  vector<int> P(M);
  vector<int> B(M);
  vector<int> s(2);
  for(int i=0; i<M;i++) {
    cin >> P[i]>> B[i];
    if (P[i] == 1)want_first++;
    s[B[i]]++;
  }
  if (C != 2) {
    cout << "wew\n";
    return;
  }
  int need = max(max(want_first, (M+1)/2), max(s[0],s[1]));

  cout << need <<endl;
}

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cout << "Case #"<<t<<": ";
    solve();

  }
}

