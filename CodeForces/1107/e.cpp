#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
string S;
ll A[200];
ll B[200];
int m=0;



int main() {
  cin >>n;
  cin >> S;
  for(int i=0; i<n; i++) {
    cin >>A[i];
  }

  {
  int i=0
  while(i < n) {
    char current = S[0];
    while(i < n && S[i] == current) {
      B[m]++;
      i++;
    }
    m++
  }
  }
  if (m%2 == 0) {
    m ++;
    B[m-1] = 0;
  }
} 
