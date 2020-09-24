#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Tree {
  int l, r;
  ll val[2][2]; // [0][0] = begin pos, end pos [1][1] = begin neg, end neg
  Tree *a, *b;

  void update(int i, ll v) {
    if (i>=l && i<=r) {
      if (r==l) {
        val[0][0]=v;
        val[1][1]=-v;
        val[0][1] = -(1ll<<60);
        val[1][0] = -(1ll<<60);
      } else {
        int mid = (l+r)/2;
        if (i<=mid) {
          a->update(i, v);
        }else {
          b->update(i,v);
        }
        update();
      }
    }
  }


  void update() {
    for (int i=0;i<2;i++) {
      for (int j=0;j<2;j++) {
        ll best = -(1ll<<60);
        best = max(best, a->val[i][j]);
        best = max(best, b->val[i][j]);
        best = max(best, a->val[i][0] + b->val[1][j]);
        best = max(best, a->val[i][1] + b->val[0][j]);
        val[i][j]=best;
      }
    }
  }

  void debug() {
    if (l==r) {
      cerr << val[0][0];
    } else {
      cerr << "(";
      a->debug();
      cerr << " ";
      b->debug();
      cerr << " [";
      cerr << val[0][0] << ",";
      cerr << val[0][1] << ",";
      cerr << val[1][0] << ",";
      cerr << val[1][1] << "]";
      cerr << ")";
    }
  }




  Tree(vector<int> &ar, int ll, int rr) {
    l=ll;
    r=rr;
    if (r==l) {
      val[0][0]=ar[l];
      val[1][1]=-ar[l];
      val[0][1] = -(1ll<<60);
      val[1][0] = -(1ll<<60);
    }else{
      int mid = (l+r)/2;
      a=new Tree(ar,l,mid);
      b=new Tree(ar,mid+1,r);
      update();
    }
  }

};


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    int n,q;
    cin>>n>>q;
    vector<int> A(n);
    for(auto&a:A)cin>>a;


    Tree *t = new Tree(A, 0, A.size()-1);

    //t->debug(); cerr<<endl;
    cout<<max(t->val[0][1], t->val[0][0])<<endl;

    for (int i=0; i<q; i++) {
      int l,r;
      cin>>l>>r;
      l--;r--;
      int ar=A[r], al=A[l];
      A[l]=ar;
      A[r]=al;
      t->update(l, ar);
      t->update(r, al);

     //t->debug(); cerr<<endl;
      cout<<max(t->val[0][1], t->val[0][0])<<endl;
    }
  }
}
