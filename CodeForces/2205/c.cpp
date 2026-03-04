#include <bits/stdc++.h>
using namespace std;

bool seive[100001];

typedef long long ll;

int main() {

  int t;
  cin>>t;
  for (int ttt=0; ttt<t; ttt++) {
    ll n;
    cin>>n;
    vector<pair<int, vector<int>>> A;
    for (int i=0; i<n; i++) {
      int l;
      cin >> l;
      vector<int> a(l);
      for (auto &b: a) cin>>b;
      A.emplace_back(i, move(a));
    }

    vector<pair<int, vector<int>>> original_A = A;
    for (int i =0; i<A.size(); i++) {
      vector<int> B; 
      set<int> seen;
      for (int j=A[i].second.size()-1; j>=0; j--) {
        int a = A[i].second[j];
        if (seen.count(a)) continue;
        B.push_back(a);
        seen.insert(a);
      }
      reverse(B.begin(), B.end());
      A[i].second = B;
    }


    vector<int> ret;

    while(A.size()) {

      // Better to do by sorting multiple times, or even better, doing an algorithm kinda ressembling radix sort.
      sort(A.begin(), A.end(), [](const pair<int, vector<int>> &ap, const pair<int, vector<int>> &bp) {
          const auto &a = ap.second;
          const auto &b = bp.second;
          for (int i =0; i<a.size() && i<b.size(); i++) {
            int aa = a[a.size()-1-i];
            int bb = b[b.size()-1-i];
            if (aa == bb) continue;
            return (bb > aa);
          }
          return b.size() > a.size();
        });

      /* for (int i=0; i<A.size(); i++) { */
      /*   for (int j=0; j<A[i].second.size(); j++) { */
      /*     cerr << A[i].second[j] << " "; */
      /*   } */
      /*   cerr << "\n"; */
      /* } */
      /* cerr << "\n"; */

      set<int> to_remove;
      for (int i = A[0].second.size()-1; i>=0; i--) {
        int a = A[0].second[i];
        if (to_remove.count(a)) continue;
        ret.push_back(a);
        to_remove.insert(a);
      }

      vector<pair<int, vector<int>>> new_A;
      for (int i=1; i<A.size(); i++) {
        const vector<int> &AA = A[i].second; 
        vector<int> BB;
        for (int j=0; j<AA.size(); j++) {
          int a = AA[j];
          if (! to_remove.count(a)) {
            BB.push_back(a);
          }
        }
        new_A.emplace_back(A[i].first, move(BB));
      }
      
      A = move(new_A);
    }
    for (int i=0; i<ret.size(); i++) {
      cout << ret[i] << " ";
    }
    cout << "\n";
  }
}
