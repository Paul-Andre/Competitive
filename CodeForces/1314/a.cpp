#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int A[212345];
int T[212345];

map<int, set<int>> C_A;
unordered_map<int, multiset<int>> A_T;

void print() {
  return;
  cerr << "C_A: ";
  for (auto &p : C_A) {
    cerr << p.first << ": {";
    for (auto &pp : p.second) {
      cerr << pp << " ";
    }
    cerr << "}  ";
  }
  cerr << "\n";

  cerr << "A_T: ";
  for (auto &p : A_T) {
    cerr << p.first << ": {";
    for (auto &pp : p.second) {
      cerr << pp << " ";
    }
    cerr << "}  ";
  }
  cerr << "\n";
  cerr << "\n";


}

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
  print();

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
      print();
      continue;
    }

    auto as_it = as.begin();
    int a = *as_it;

    multiset<int> &ts = A_T[a];

      if (ts.size() != c) {
        cerr << ts.size() << " " << c <<endl;
      }
      assert(ts.size() == c);

    auto ts_it = ts.begin();
    while(ts.size() > 1) {

      //int wow = 1; // ts.size() - 1;
      int wow =  ts.size() - 1;
      int smallest_price = *ts_it;
      tot += (ll)smallest_price * (ll)wow;


      auto ts_iiii = ts_it;
      ts_iiii ++;
      A_T[a].erase(ts_it);
      A_T[a+wow].insert(smallest_price);

      C_A[A_T[a].size() + 1].erase(a);
      C_A[A_T[a].size()].insert(a);

      if (A_T[a+wow].size() - 1 > 0) {
        C_A[A_T[a+wow].size() - 1].erase(a+wow);
      }
      C_A[A_T[a+wow].size()].insert(a+wow);

      if (C_A[A_T[a+wow].size() - 1].size() == 0) {
        C_A.erase(A_T[a+wow].size() - 1);
      }
      if (C_A[A_T[a].size() + 1].size() == 0) {
        C_A.erase(A_T[a].size() + 1);
      }
      ts_it = ts_iiii;
      print();
    }
  }
  cout << tot <<endl;
}
