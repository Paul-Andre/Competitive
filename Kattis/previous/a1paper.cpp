#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll haves[50];

double tape = 0;

double getTape(ll a) {
  return exp2(- (a * 2 -1) / 4.);
}

bool get(ll a, ll need) {
  if (a == 49) return false;
  while(haves[a] < need*2 && get(a+1, (need*2 - haves[a])) ) {
  }
  if (haves[a] < need*2) return false;
  haves[a] -= need*2;
  haves[a-1] += need;
  tape += getTape(a)*need;
  return true;
}


int main() {
  ll n;
  cin >> n;
  for (int i=2; i<=n; i++) {
    cin >> haves[i];
  }
  while(haves[1] != 1 && get(2, 1) ) {
  }
  if (haves[1] != 1) {
    cout << "impossible\n";
    return 0;
  }
  cout.precision(20);
  cout << tape <<endl;

}




