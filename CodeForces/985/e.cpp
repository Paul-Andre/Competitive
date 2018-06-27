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


int n,k,d;
int a[512345];
int b[512345];
bool c[512345];

void solve() {
  cin>>n>>k>>d;
  for(ll i=0; i<n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);


  {
    int i=0;
    int j=0;
    while(j<n && i<=j){
      if (a[j] - a[i] <= d) {
        b[i] = j;
        j++;
      } else {
        i++;
        b[i] = b[i-1];
      }
    }
    j=n-1;
    i++;
    while(i<n){
      b[i] = j;
      i++;
    }

  }

  /*
  for(int i=0; i<n; i++) {
    cerr << b[i] << " ";
  }
  cerr <<endl;
  */

  int j = 0;

  {
    int i = 0;
      while(j<n && j<=b[i]){
        if ((j-i+1)>=k) {
          c[j] = true;
        }
          j++;
      }
  }
  for (int i=1; i<n; i++) {
    if (c[i-1]) {
      while(j<n && j<=b[i]){
        if ((j-i+1)>=k) {
          c[j] = true;
        }
          j++;
      }
    }
  }
  /*
  for(int i=0; i<n; i++) {
    cerr << c[i] << " ";
  }
  cerr <<endl;
  */

  if (c[n-1]) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}

