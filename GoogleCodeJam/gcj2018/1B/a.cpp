#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;


typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif



ll N, L;

ll get(ll c) {
  return (c*1000 / N + 5) /10;
}


pll need(ll c) {

  ll cur =  (c*1000 / N);

  ll want = cur;

  if (cur%10 == 5) {
    want += 10;
  }
  else {
    while(want%10 != 5) {
      want += 1;
    }
  }

  ll diff = want*N - (c)*1000;

  return pll(-diff, c);
}


void solve() {

  cin >> N>>L;

  std::priority_queue<pll > heap;

  ll got = 0;
  
  ll rem = N;

  for (int i=0; i<L; i++) {
    ll c;
    cin >> c;
    rem -= c;
    got += get(c);
    heap.push(need(c));
  }

  while(rem != 0) {
    pll n;
    if (need(0) >= heap.top()) {
      n = need(0);
    } else {
      n = heap.top();
      heap.pop();
    }

    got -= get(n.second);
    got += get(n.second+1);
    rem --;

    heap.push(need(n.second + 1));
  }
  cout << got <<endl;
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cout << "Case #"<<t<<": ";
    solve();

  }
}

