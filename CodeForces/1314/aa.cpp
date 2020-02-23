#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int A[212345];
int T[212345];

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); 

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> A[i];
  }
  for(int i=0; i<n; i++) {
    cin >> T[i];
  }
  vector<pair<int,int>> v;
  for (int i=0; i<n; i++) {
    v.emplace_back(A[i], T[i]);
  }
  sort(v.begin(), v.end());
  ll tot =0;
  int cur = 0;
  set<int> running;
  int rr =0;

  for (int i=0; i<n; i++) {
    int a = v[i].first;
    int t = v[i].second;



  cout << tot <<endl;
}
