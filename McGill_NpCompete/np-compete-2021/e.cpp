#include <bits/stdc++.h>
using namespace std;

int A[112345];
int Less[112345];
int Greater[112345];

int main() {
  int n; 
  cin>>n;
  for(int i=0; i< n;i++) {
    cin>>A[i];
  }
  Less[0] = A[0];
  for (int i=1; i<n; i++) {
    Less[i] = max(Less[i-1], A[i]);
  }
  Greater[n-1] = A[n-1];
  for (int i=n-2; i>=0; i--) {
    Greater[i] = min(Greater[i+1], A[i]);
  }
  int tot = 0;
  /*
  for (int i=0; i<n; i++) {
    cerr << A[i] << " ";
  }cerr<<endl;
  for (int i=0; i<n; i++) {
    cerr << Less[i] << " ";
  }cerr<<endl;
  for (int i=0; i<n; i++) {
    cerr << Greater[i] << " ";
  }cerr<<endl;
  */


  for (int i=1; i< n-1; i++) {
    if (Less[i-1] <= A[i] && Greater[i+1] > A[i]) {
      tot++;
    }
  }
  if (Greater[1] > A[0]) {
    tot++;
  }
  if (Less[n-2] <= A[n-1]) {
    tot++;
  }
  cout <<tot <<endl;
}



