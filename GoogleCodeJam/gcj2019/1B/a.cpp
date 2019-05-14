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

typedef pair<int,int> pii;

int P,Q;

int get(vector<pii> &v) {
  int acc = 0;
  int best = 0;
  int best_j = 0;
  for (int i=0; i<v.size(); i++) {
    int u = v[i].second;
    int j = v[i].first;
    acc += u;
    if (acc > best) {
      best = acc;
      best_j = j;
    }
  }
  return best_j;
}


void solve() {
  cin >> P >> Q;
  vector<pii> X;
  vector<pii> Y;

  for (int i=0; i<P; i++) {
    int x,y;
    char c;
    cin>>x>>y>>c;
    if (c == 'N') {
      Y.push_back(pii(y+1, 1));
    } else if (c == 'S') {
      Y.push_back(pii(y, -1));
    } else if (c == 'E') {
      X.push_back(pii(x+1, 1));
    } else if (c == 'W') {
      X.push_back(pii(x, -1));
    }
  }

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());

  cout << get(X) << " " << get(Y);

}

int main() {
  int T;
  cin >> T;
  for (int ttt=1; ttt<=T; ttt++) {
    cout << "Case #" << ttt << ": ";
    solve();
    cout << endl;
  }
}
