#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
// L = 0, R = 1
bool A[3001];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> k;
  for (int i=0; i<n; i++) {
    char c;
    cin >> c;
    A[i] = (c=='R');
  }
  vector<vector<int>> sol;
  int minSteps = 0;
  int maxSteps = 0;
  sol.emplace_back();
  while(true) {
    bool did = false;
    for (int i=0; i<n-1; i++) {
      if (A[i] == 1 && A[i+1] == 0) {
        A[i] = 0; A[i+1] = 1;
        i++;
        did = true;
        maxSteps ++;
        sol.back().push_back(i);
      }
    }
    if (did) {
      minSteps ++;
      sol.emplace_back();
      if (minSteps > 3000000) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      break;
    }
  }
    assert(sol.back().size() == 0);
    sol.pop_back();
  if (! (k >= minSteps && k <= maxSteps) ) {
    cout << -1 << endl;
  } else {
    vector<vector<int>> actSol;
    int rem = k-minSteps;
    actSol.emplace_back();
    for (int i=0; i<sol.size(); i++) {
      for (int j=0; j<sol[i].size(); j++) {
        actSol.back().push_back(sol[i][j]);
        if (sol[i].size() - j > 1 && rem) {
          actSol.emplace_back();
          rem --;
        }
      }
      actSol.emplace_back();
    }
    assert(actSol.back().size() == 0);
    actSol.pop_back();
    for (auto &a: actSol) {
      cout << a.size() << " ";
      for (auto b: a) {
        cout << b << " ";
      }
      cout <<endl;
    }
  }
}

