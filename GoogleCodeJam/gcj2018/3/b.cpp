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
  int L, U;
  cin>>L>>U;

  cout << L <<endl;
  //clique
  cout << 1 << " " <<  2 << endl;
  cout << 1 << " " <<  3 << endl;
  cout << 1 << " " <<  4 << endl;
  cout << 2 << " " <<  3 << endl;
  cout << 2 << " " <<  4 << endl;
  cout << 3 << " " <<  4 << endl;


  cout << 1 << " " <<  5 << endl;
  cout << 2 << " " <<  6 << endl;
  cout << 3 << " " <<  7 << endl;
  cout << 4 << " " <<  8 << endl;

  cout << 6 << " " <<  5 << endl;
  cout << 7 << " " <<  6 << endl;
  cout << 8 << " " <<  7 << endl;
  cout << 6 << " " <<  8 << endl;
  cout << 5 << " " <<  8 << endl;



  cout << 7 << " " <<  6 << endl;
  cout << 5 << " " <<  8 << endl;
  cout << 7 << " " <<  8 << endl;

  for (int i=9; i<=L; i++) {
    cout << i << " " << i-1 <<endl;
    cout << i << " " << i-2 <<endl;
  }

  cout << L << " " << 5 << endl;
  cout << L << " " << 6 << endl;
  cout << L-1 << " " << 5 << endl;

  cout << flush;

  int N;
  cin >> N;

  vector<vector<int>> G(N);
  for(int i=0; i<N; i++) {
    int x,y;
    cin>>x>>y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  vector<int> equiv(N, -1);

  for (int i=0; i<

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

