#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<char> vals;

struct Monoid {
  char val;
  int pos;
};

Monoid operator^(const Monoid &a, const Monoid &b) {
  if (a.val <= b.val) {
    return a;
  }
  return b;
}
Monoid empty(int i){
  Monoid ret;
  ret.val = "?";
  ret.pos = -1;
}

Monoid singleton(int i) {
  Monoid ret;
  ret.val = vals[i];
  ret.pos = i;
}

struct SegmentTree {
  int a, b;
  SegmentTree *l, *r;
  Monoid value;
  SegmentTree (int a, int b):a(a), b(b) {
    if (a == b) {
      value = singleton(a);
    } else {
      int c = (a+b)/2;
      l = new SegmentTree(a, c);
      r = new SegmentTree(c+1, b);
      value = l->value ^ r->value;
    }
  }
  void update(int i) {
    if ( i>=a && i<=b) {
      if (a == b) {
        value = singleton(a);
      } else {
        l->update(i);
        r->update(i);
        value = l->value ^ r->value;
      }
    } else {
      return;
    }
  }
  Monoid query(int aa, int bb) {
    assert(aa <= bb);
    if ( aa>= a && bb<= b) {
      return value;
    }
    if (aa > b || bb < a) {
      return empty();
    }
    return l->query(aa, bb) ^ r->query(aa, bb);
  }
};
void solve() {
  int n;
  cin>>n;
  string s,t;
  cin>>s>>t;

  

}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    solve();
  }
}
