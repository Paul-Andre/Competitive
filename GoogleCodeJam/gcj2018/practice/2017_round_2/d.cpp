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
  vector<vector<char>> grid(104,vector<char>(104, '#'));
  vector<vector<vector<int>>> grid(104,vector<vector<int> >(104, vector<int>()));
  int C,R;
  for (int i=0; i<R; i++) {
    for(int  j=0; j<C; j++) {
      cin >> grid[i+1][j+1];
    }
  }
  int t = 1;
  for (int i=0; i<104; i++) {
    for(int j=0; j<104; j++) {
      if (grid[i][j] == 'T') {
        


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

