#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin>>T;
  for (int ttt=0; ttt<T; ttt++) {
    int n, m, q;
    cin>>n>>m>>q;
    vector<int> B(m+1);
    for (int i=1; i<=m; i++) {
      cin>>B[i];
    }
    vector<int> A(q+1);
    for (int i=1; i<=q; i++) {
      cin>>A[i];
    }
    sort(B.begin()+1, B.end());

    vector<pair<int,int>> C;
    for (int i=1; i<=q; i++) {
      C.emplace_back(A[i], i);
    }
    for (int i=1; i<=m; i++) {
      if (i<m) {
        C.emplace_back(B[i], -(B[i+1]-B[i]));
      }else{
        C.emplace_back(B[i], 0);
      }
    }
    int first_pos = B[1];
    int last_pos = B.back();

    sort(C.begin(), C.end());

    vector<int> ret(q+1);

    bool beg = true;
    int interval_size = 0;
    bool end = false;
    for (pair<int,int> p : C) {
      if (p.second>0) {
        if (beg) {
          ret[p.second] = first_pos-1;
        } else if(end) {
          ret[p.second] = n-last_pos;
        } else {
          //cout<< "asdfa\n";
          ret[p.second] = interval_size/2;
        }

      } else if (p.second<0) {
        beg = false;
        interval_size = - p.second;
        end = false;
      } else if (p.second==0) {
        beg = false;
        interval_size = 0;
        end = true;
      }
    }
    /* for (int i=0; i<C.size(); i++) { */
    /*   cerr<< C[i].first << "," << C[i].second << "  "; */
    /* } */
    /* cerr <<endl; */
    for (int i=1; i<=q; i++) {
      cout<<ret[i]<<endl;
    }

  }
}
    



