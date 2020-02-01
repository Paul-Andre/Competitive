#include <bits/stdc++.h>
using namespace std;

int divceil(int a, int b) {
  return (a + b -1)/b;
}

int main() {
  int T;
  cin >> T;
  for (int iii=0; iii<T; iii++) {
    int n,d;
    cin >> n >> d;
    bool good = false;
    for (int x=0; x<50000; x++) {
      if (divceil(d, x+1) + x <= n) {
        good = true;
      }
    }
    if (good) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
