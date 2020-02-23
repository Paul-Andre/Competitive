#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int A[212345];
int T[212345];

map<int, set<int>> C_A;
unordered_map<int, multiset<int>> A_T;

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); 

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> A[i];
  }
  for(int i=0; i<n; i++) {
    cin >> T[i];
  }
  for (int i=0; i<n; i++) {
    A_T[A[i]].insert(T[i]);
  }
  for (auto &p: A_T) {
    C_A[p.second.size()].insert(p.first);
  }

  C_A[1];

  ll tot = 0;
  while(C_A.size() > 1) {
    auto it = C_A.begin();

    if (it->first == 1){
      it ++;
    }

    int c = it->first;
    set<int> &as = it->second;

    assert(c != 1);
    if (as.size() == 0) {
      C_A.erase(it);
      continue;
    }

    auto as_it = as.begin();
    int a = *as_it;

    multiset<int> &ts = A_T[a];
    auto ts_it = ts.begin();
    int smallest_price = *ts_it;
    tot += smallest_price;

    A_T[a].erase(ts_it);
    A_T[a+1].insert(smallest_price);

    C_A[A_T[a].size() + 1].erase(a);
    C_A[A_T[a].size()].insert(a);

    if (A_T[a+1].size() - 1 > 0) {
      C_A[A_T[a+1].size() - 1].erase(a+1);
    }
    C_A[A_T[a+1].size()].insert(a+1);
  }
  cout << tot <<endl;
}

