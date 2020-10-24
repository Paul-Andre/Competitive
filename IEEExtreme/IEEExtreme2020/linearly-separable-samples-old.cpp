#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

bool topSpike(pii a) {
  return a.x == 0 && a.y > 0;
}
bool botSpike(pii a) {
  return a.x == 0 && a.y < 0;
}

int sign(int a) {
  if (a<0) return -1;
  if (a > 0) return 1;
  return 0;
}

struct Pt{
  int x;
  int y;
  Pt() {
    x = 0;
    y = 0;
  }
  Pt(x,y): x(x), y(y) {}
}
  

bool operator<(Pt a, Pt b) {
  if (topSpike(a) && topSpike(b)) return false;
  if (topSpike(a)) return false;
  int sa = sign(a.x);
  int sb = sign(b.x);
  if (sa != sb) return sa < sb;
  if (sa == 0) return false;
  return  (a.y * b.x) < (b.y * a.x);
}

bool operator==(Pt a, Pt b) {
  if (topSpike(a) && topSpike(b)) return true;
  int sa = sign(a.x);
  int sb = sign(b.x);
  if (sa != sb) return false;
  if (sa == 0) return true;
  return  (a.y * b.x) == (b.y * a.x);
}


enum Where {
  FIRST_NEG;
  POS;
  SECOND_TRANS;
  SECOND_NEG;
}

int main() {

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<pair<pii, int>> A;
    bool havePos = false;
    bool haveNeg = false;
    for(int i=0; i<n;i++){
      float x,y,v;
      cin>>x>>y>>v;
      if (v==-1) haveNeg=true;
      if (v==1) havePos=true;
      A.emplace_back(pii(x*100, y*100), v);
    }
    sort(A.begin(), A.end());

    for (int i=0; i<10 && i<n; i++) {
      auto a = A[i];
      cerr << a.first.first << " " << a.first.second << " " << a.second << endl;
    }
    if (A[0].second != -1) {
    for (int i=0; i<n; i++) {
      A.second *= -1;
    }

    if (haveNeg && havePos) {
      Pt lastNeg = A[0].first;
      Pt firstPos;
      Pt lastPos;
      Pt firstNeg = A[0].first;

      Pt prevPt;
      int prevL = -1;

      Where w = FIRST_NEG;

      for(int i=0; i<n; i++) {
        Pt p = A[i].first;
        int l = A[i].second;
        if (w == FIRST_NEG) {
          if (l==-1) {
            lastNeg = p;
          } else {
            firstPos = p;
            w = POS;
          }
        }
        if (w == POS) {
          if (l==1) {
            lastPos = p;
          }else {
            firstNeg = p;
            w = SECOND_TRANS
          }
        }
        if (w == SECOND_TRANS) {
          if (p == firstNeg) {
            if (l == 1) {
              lastPos = p
            }
          } else {
            w = 


        }
        if (w == SECOND_NEG) {
        }
      }
        


  }
}


