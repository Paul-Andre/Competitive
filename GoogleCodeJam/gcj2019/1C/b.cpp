#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif

#define FOR(r) for (ll r=0; r<=100; r++)

char get(int i) {
  cout << i <<endl;
  char c;
  cin >> c;
  if (c == 'N') exit(0);
  return c;
}

char dd(vector<char> &A, int k, int j) {
  map<char, int> m;
  m['A'] = 0;
  m['B'] = 0;
  m['C'] = 0;
  m['D'] = 0;
  m['E'] = 0;
  for (int i=0; i<119; i++) {
    if (A[i] != '\0') {
      char c = get(  i*5 + j);
      A[i] = c;
      m[c]++;
    }
  }
  for (auto &p: m) {
    if (p.second == k) {
      for (auto &v: A) {
        if (v != p.first) {
          v = '\0';
        }
      }
      return p.first;
    }
  }
  assert(false);
}

void solve() {
  vector<char> A(119, 'X');
  char a = dd(A, 23, 1);
  char b = dd(A, 5, 2);
  char c = dd(A, 1, 3);
  char d = 'Z', e = 'Z';
  for (int i=0; i<119; i++) {
    if (A[i] != '\0') {
      d = get(i*5 + 5);
      e = get(i*5 + 4);
    }
  }
  cout << a<<b<<c<<d<<e<<endl;
}

int main() {
  int T, F;
  cin >> T >> F;
  for (int ttt=1; ttt<=T; ttt++) {
    solve();
    char res;
    cin >> res;
    if (res == 'N') exit(0);
  }
}
