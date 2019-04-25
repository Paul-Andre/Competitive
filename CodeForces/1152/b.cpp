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

bool isPow(int a) {
  int b = 1 ;
  while(b < 11234567){
    if (a == b ) return true;
    b = b<< 1;
  }
  return false;
}

int whichPow(int a) {
  int b = 1 ;
  int i = 0;
  while(b < 112345678){
    if (a < b ) return i;
    b = b<< 1;
    i++;
  }
  return false;
}

bool isGood(int a) {
  int b = 1 ;
  while(b < 112345678){
    //cerr << (b-1) <<endl;
    if (a == (b-1) ) return true;
    b = b<< 1;
  }
  return false;
}

int main() {
  int x;
  cin >> x;
  int cnt = 0;
  vector<int> h;
  cerr << bitset<32>(x) <<endl;
  while(true) {
    if (isGood(x)) break;
    int wp = whichPow(x);
    h.push_back(wp);
    x = x ^ ((1 << whichPow(x))-1);
    cnt ++;
    cerr <<  bitset<32>(x) <<endl;
    if (isGood(x)) break;
    x += 1;
    cnt ++;
    cerr <<   bitset<32>(x) <<endl;
  }
  cout << cnt << endl;
  for (int a: h) {
    cout << a << " ";
  }
  cout <<endl;

}

