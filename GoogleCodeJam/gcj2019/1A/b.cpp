#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif

// 7 18
#define P 7
#define PP 18

int d[] = {5,7,9,11,13,16,17};

void solve() {
  vector<int> h(P);
  for (int i=0; i<P; i++) {
    int k = d[i];
    for (int i=0; i<PP; i++) {
      cout << k << " ";
    }
    cout <<endl;
    int acc = 0; 
    for (int i=0; i<PP; i++) {
      int a;
      cin >>a;
      acc +=a;
    }
    acc %= k;
    h[i] = acc;
  }
  for (int i=0; i<11234567; i++) {
    bool g = true;
    for (int j=0; j<P; j++) {
      int k = d[j];
      if (i%k != h[j]) g = false;
    }
    if (g) {
      cout << i <<endl;
      return;
    }
  }
  cout << "We failed" << endl;
}

int main() {
  int T, N, M;
  cin >> T >> N >> M;
  for (int ttt=1; ttt<=T; ttt++) {
    solve();
    int res;
    cin >> res;
    if (res == -1) exit(1);
  }
}
