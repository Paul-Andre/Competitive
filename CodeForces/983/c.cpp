#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int oo = (ll)(-1u >> 1);

int n;
int q;

typedef int8_t Elevator[4];

int enc (Elevator a) {
  return a[0] + a[1]*10 + a[2]*100+ a[3]*1000;
}

void dec (int a, Elevator &e) {
  for (int i=0; i<4; i++) {
    e[i] = a%10;
    a /=10;
  }
}

unordered_map<int, int> M;
unordered_map<int, int> MM;

int main() {
  cin >> n;
  M[0];

  int prev = 1;
  for (int p=0; p<n; p++) {
    int a,b;
    cin>>a>>b;
    MM.clear();
    for (int i=1; i<=9; i++) {
      int justTime = abs(a - i) + abs(i - prev);
      for (auto p: M) {
        Elevator e;
        dec(p.first, e);
        Elevator ne;
        int extra = 0;
        for (int j =0; j<4; j++) {
          if (e[j] <= max(a, max(prev, i)) && e[j] >= min(a, min(prev, i))) {
            extra ++;
            ne[j] = 0;
          } else {
            ne[j] = e[j];
          }
        }
        sort(ne, ne+4);
        if (MM.count(enc(ne)) == 0) {
          MM[enc(ne)] = p.second + justTime + extra;
        }else {
          MM[enc(ne)] = min(MM[enc(ne)], p.second + justTime + extra);
        }

      }
    }
    M.clear();
    for (auto p: MM) {
      Elevator e;
      dec(p.first, e);
      int zcnt = 0;
      for (int i=0; i<4; i++) {
        if (e[i] == 0) zcnt ++;
      }
      if (zcnt!=0) {
        sort(e, e+4);
        e[0] = b;
        sort(e, e+4);
        auto ne = e;
        if (M.count(enc(ne)) == 0) {
          M[enc(ne)] = p.second + 1;
        }else {
          M[enc(ne)] = min(M[enc(ne)], p.second +1 );
        }
      }
    }
    prev = a;
    /*
    cerr << "wew : ";
    for (auto p: M) {
      cerr << p.first << " " << p.second <<"; ";
    }
    cerr << endl;
    */
  }
  int best = oo;
  for (int a=1; a<=9; a++) {
    MM.clear();
    for (int i=1; i<=9; i++) {
      int justTime = abs(a - i) + abs(i - prev);
      for (auto p: M) {
        Elevator e;
        dec(p.first, e);
        Elevator ne;
          int extra = 0;
        for (int j =0; j<4; j++) {
          if (e[j] <= max(a, max(prev, i)) && e[j] >= min(a, min(prev, i))) {
            extra ++;
            ne[j] = 0;
          } else {
            ne[j] = e[j];
          }
        }
        sort(ne, ne+4);
        if (MM.count(enc(ne)) == 0) {
          MM[enc(ne)] = p.second + justTime + extra;
        }else {
          MM[enc(ne)] = min(MM[enc(ne)], p.second + justTime + extra);
        }
      }
    }
    best = min(best, MM[0]);
  }
  cout << best <<endl;
}
