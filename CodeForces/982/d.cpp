#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

typedef pair<int,int> pii;

pii B[112345];

map<int,int> M;

void ins(int i) {
  if (i != 0) {
    M[i] ++;
  }
}

void rem(int i) {
  M[i] --;
  if (M[i] == 0) {
    M.erase(i);
  }
}

struct range {
  int a,b;
  range *l, *r;
  range(int aa, int bb) {
    a = aa;
    b = bb;
    l = r = nullptr;
    ins (b-a+1);
  }
  void split(int c) {
    if (c < a || c > b) return;
    if (l == nullptr) {
      rem(b-a+1);
      l = new range(a, c-1);
      r = new range(c+1, b);
    }
    else {
      l->split(c);
      r->split(c);
    }
  }
};

int main() {

  cin>>n;
  for (int i=0; i<n; i++) {
    int a;
    cin >> a;
    B[i] = pii(a,i);
  }
  sort(B, B+n);

  int max_loc = 1;
  int max_val = B[n-1].first+1;

  range *root = new range(0, n-1);
  for (int i=n-1; i>=0; i--) {
    pii p = B[i];
    root->split(p.second);
    if (M.size() == 1) {
      for (pii q: M) {
        if (q.second >= max_loc) {
          max_loc = q.second;
          max_val = p.first;
        }
        break;
      }
    }
  }

  for (int i=n-1; i>=0; i--) {
    pii p = B[i];
    if (p.first < max_val) {
      cout << p.first+1 <<endl;
      return 0;
    }
  }

}



