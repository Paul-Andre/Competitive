#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define cerr if(false) cerr

int join_function(int x, int y) {
  return max(x, y);
}

int default_function() {
  return 0;
}

enum NodeType {
  EMPTY,
  SINGLE,
  MULTIPLE,
};

struct Tree {
  int lower, upper;
  Tree *l, *r;

  NodeType type;
  int position;
  int value;

  Tree(int _lower, int _upper) {
    lower = _lower;
    upper = _upper;
    l = r = NULL;
    type = EMPTY;
    assert(lower <= upper);
  }
  void set(int pos, int val) {
    if (pos < lower || pos > upper) return;
    if (type == EMPTY) {
      position = pos;
      value = val;
      type = SINGLE;
    } else {
      if (type == SINGLE) {
        int mid = (lower + upper)/ 2;
        l = new Tree(lower, mid);
        r = new Tree(mid+1, upper);
        l->set(position, value);
        r->set(position, value);
        value = join_function(l->getAll(), r->getAll());
        type = MULTIPLE;
      }
      assert(type == MULTIPLE);
      l->set(pos, val);
      r->set(pos, val);
      value = join_function(l->getAll(), r->getAll());
    }
  }
  int getAll() {
    if (type == EMPTY) {
      return default_function();
    }
    return value;
  }
  int get(int low, int up) {
    if(low > up)return default_function();
    if (low > upper || up < lower) return default_function();
    if (type == EMPTY) {
      return default_function();
    } else if (type == SINGLE) {
      if (low <= position && position <= up) return value;
      else return default_function();
    } else {
      assert(type == MULTIPLE);
      return join_function(l->get(low, up), r->get(low, up));
    }
  }
};

int main() {
  int t;
  cin>>t;
  for (int ttt=0; ttt<t; ttt++) {
    ll n;
    cin>>n;
    vector<int> A(n);
    for(auto &a:A) cin>>a;

    int ni = -1;
    for (int i=0; i<n; i++) {
      if (A[i] == n) {
        ni = i;
        break;
      }
    }

    // B[i] = length of longest decreasing sequence contained within A[0]:A[i], that starts at the maximum within that range
    vector<int> B(A.size(),0);
    // C[i] = length of longest increasing sequence contained within A[i]:A[A.size()-1], that ends at the maximum within that range
    vector<int> C(A.size(),0);

    for(auto a: A) cerr<<a<<" ";
    cerr<<endl;

    {
      int running_max = -1;

      // tree[l, r] = longest decreasing sequence so far that ends between l and r
      Tree tree(1, n);

      for (int i=0; i<A.size(); i++) {


        int a = A[i];
        bool new_max = (a > running_max) ;

        if (new_max) {
          running_max = a;
          tree = Tree(1,n);
        }
        //cerr<<(a+1)<<" "<<n <<endl;
        int tv = tree.get(a+1, n);
        int val = tv + 1;
        tree.set(a, val);
        B[i] = val;
        if (i>0 && !new_max) {
          B[i] = max(B[i], B[i-1]);
        }
        cerr << B[i] << " ";
      }
      cerr<<endl;
    }
    {
      int running_max = -1;
      // tree[l, r] = longest decreasing sequence so far that ends between l and r
      Tree tree(1, n);

      for (int i=A.size()-1; i>=0; i--) {
        int a = A[i];
        bool new_max = (a > running_max) ;
        if (new_max) {
          running_max = a;
          tree = Tree(1,n);
        }
        int tv = tree.get(a+1, n);
        int val = tv + 1;
        tree.set(a, val);
        C[i] = val;
        if (i<C.size()-1 && !new_max) {
          C[i] = max(C[i], C[i+1]);
        }
      }
      for (int i=0; i<C.size(); i++) {
        cerr << C[i] << " ";
      }
      cerr<<endl;
    }

    int longest = 0;
    for (int i=0; i<A.size()-1; i++) {
      longest = max(longest, B[i]+C[i+1]);
    }
    cout<<(n-longest) <<endl;
  }
}
