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


int M;
int R[101][2];
ll G[101];
ll take[101];
vector<int> pre;
vector<int> done;

ll scronch = 1000000000;

bool trav(int i) {
  //LOG(i);
  for (int j=0; j<pre.size(); j++) {
    //cerr << pre[j] << " ";
    if (pre[j] == i) {
      return false;
    }
  }
  //cerr << endl;
  pre.push_back(i);
  if (G[i] >= scronch) {
    G[i] -= scronch;
    done.push_back(i);
    pre.pop_back();
    return true;
  }
  else if (trav(R[i][0]) && trav(R[i][1])) {
    pre.pop_back();
    return true;
  }
  pre.pop_back();
  return false;
}


void solve() {
  cin >> M;
  for (int i=1; i<=M; i++) {
    cin >> R[i][0] >> R[i][1];
  }
  for (int i=1; i<=M; i++) {
    cin >> G[i];
  }

  ll tot = 0;
  scronch = 1000000000;

  while(scronch != 0) {
    done.clear();
    while(trav(1)) {
      tot += scronch;
      done.clear();
    }
    for (int i=0; i<done.size(); i++) {
      G[done[i]] += scronch;
    }
    scronch /= 2;
  }
  cout << tot <<endl;
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cout << "Case #"<<t<<": ";
    solve();

  }
}

