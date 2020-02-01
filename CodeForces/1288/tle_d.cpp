#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

#define MOD 1000000007


int A[300001][10];
int n, m;

// if a <= b => -1, if a >= b => 1, if a == b => 2, if inconclusive => 0
int compare(vector<int> &a, vector<int> &b) {
  bool all_a_bigger = true;
  bool all_b_bigger = true;
  for (int i=0; i<m; i++) {
    if (a[i] < b[i]) all_a_bigger = false;
    if (b[i] < a[i]) all_b_bigger = false;
  }
  if (all_a_bigger && !all_b_bigger) return 1;
  if (all_b_bigger && !all_a_bigger) return -1;
  if (all_b_bigger && all_a_bigger) return 2;
  return 0;
}

vector<int> mix(int a[], int b[]) {
  vector<int> ret;
  for (int i=0; i<m; i++) {
    ret.push_back(max(a[i], b[i]));
  }
  return ret;
}

int main() {
  cin >> n >> m;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> A[i][j];
    }
  }

  vector<pii> pareto;
  pareto.emplace_back(0,0);

  for (int i=0; i<n; i++) {
    for (int j=0; j<(int)pareto.size(); j++) {
      pii pp = pareto[j];
      vector<int> have = mix(A[pp.first], A[pp.second]);

      auto asdf = [&](int x, int y) {
        vector<int> m = mix(A[x], A[y]);
        bool found = false;
        for (int jj=0; jj<(int)pareto.size(); jj++) {
          pii ppp = pareto[jj];
          vector<int> havep = mix(A[ppp.first], A[ppp.second]);
          int c = compare(m, havep);
          if (c == -1) {
            //cerr << x << " " << y << " is within " << ppp.first << " " << ppp.second <<endl;
            found = true;
            break;
          } else if (c == 1) {
            //cerr << x << " " << y << " is without " << ppp.first << " " << ppp.second <<endl;
            found = true;
            pareto[jj] = pii(x, y);
            break; 
          } else if (c == 2) {
            found = true;
            break;
          }
        }
        if (!found) {
            //cerr << x << " " << y << " is new on the block\n";
          pareto.push_back(pii(x, y));
        }
      };

      asdf(pp.first, i);
      asdf(pp.second, i);
    }

  }

  int best = -1;
  int best_i = -1;
  for (int i=0; i<pareto.size(); i++) {
    pii pp = pareto[i];
    vector<int> have = mix(A[pp.first], A[pp.second]);
    int val = 1123456789;
    for (int j=0; j<m; j++) {
      val = min(have[j], val);
    }
    if (val > best) {
      best= val;
      best_i = i;
    }
    cerr << "pareto " << pareto[i].first << " " << pareto[i].second << endl;
  }
  cout << pareto[best_i].first + 1 << " " << pareto[best_i].second + 1 <<endl;
}
