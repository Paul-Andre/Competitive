#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int join_function(int x, int y) {
  return max(x, y);
}

int default_function() {
  return 0;
}

struct Tree {
  int lower, upper;
  Tree *l, *r;
  int value;
  Tree(int _lower, int _upper) {
    lower = _lower;
    upper = _upper;
    if (lower == upper) {
      value = default_function();
      return;
    }
    assert(lower < upper);
    int mid = (lower + upper)/ 2;
    l = new Tree(lower, mid);
    r = new Tree(mid+1, upper);
    value = join_function(l->value, r->value);
  }
  void set(int pos, int val) {
    if (pos < lower || pos > upper) return;
    if (lower == upper && lower == pos) {
      value = val;
      return;
    }
    l->set(pos, val);
    r->set(pos, val);
    value = join_function(l->value, r->value);
  }
  int get(int low, int up) {
    if(low > up)return default_function();
    if (low > upper || up < lower) return default_function();
    if (low <= lower && upper <= up) return value;
    assert(lower != upper);
    return join_function(l->get(low, up), r->get(low, up));
  }
};

int calc(const vector<int> &A, int n) {

    // B[i] = length of longest decreasing sequence contained within A[0]:A[i]
    vector<int> B(A.size(),0);
    // C[i] = length of longest increasing sequence contained within A[i]:A[A.size()-1]
    vector<int> C(A.size(),0);

    for(auto a: A) cerr<<a<<" ";
    cerr<<endl;

    {
      // tree[l, r] = longest decreasing sequence so far that ends between l and r
      Tree tree(1, n);

      for (int i=0; i<A.size(); i++) {
        int a = A[i];
        //cerr<<(a+1)<<" "<<n <<endl;
        int tv = tree.get(a+1, n);
        int val = tv + 1;
        tree.set(a, val);
        B[i] = val;
        if (i>0) {
          B[i] = max(B[i], B[i-1]);
        }
        cerr << B[i] << " ";
      }
      cerr<<endl;
    }
    {
      // tree[l, r] = longest decreasing sequence so far that ends between l and r
      Tree tree(1, n);

      for (int i=A.size()-1; i>=0; i--) {
        int a = A[i];
        int tv = tree.get(a+1, n);
        int val = tv + 1;
        tree.set(a, val);
        C[i] = val;
        if (i<C.size()-1) {
          C[i] = max(C[i], C[i+1]);
        }
        cerr << C[i] << " ";
      }
      cerr<<endl;
    }

    int longest = 0;
    for (int i=0; i<A.size()-1; i++) {
      longest = max(longest, B[i]+C[i+1]);
    }
    return longest;
}


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
    int biggest_left = -1;
    int biggest_left_i = ni;
    for (int i=ni-1; i>=0; i--) {
      if (A[i] > biggest_left) {
        biggest_left = A[i];
        biggest_left_i = i;
      }
    }
    int biggest_right = -1;
    int biggest_right_i = ni;
    for (int i=ni+1; i<n; i++) {
      if (A[i] > biggest_right) {
        biggest_right = A[i];
        biggest_right_i = i;
      }
    }
    vector A1(A.begin() + biggest_left_i, A.begin() + ni + 1);
    vector A2(A.begin() + ni, A.begin() + biggest_right_i + 1);
    
    int ret = min(n - calc(A1, n), n-calc(A2, n));
    cout <<ret<<endl;
  }
}
