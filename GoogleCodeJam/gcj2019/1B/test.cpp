#include <bits/stdc++.h>
using namespace std;


int main() {
  map<int, int> mm;
  mm[23] = 1;
  auto it = mm.begin();
  cout << it->first << " " << it->second <<endl;
  it --;
  it --;
  it --;
  it --;
  it --;
  cout << it->first << " " << it->second <<endl;
}
