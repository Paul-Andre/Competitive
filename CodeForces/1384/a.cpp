#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int A[100];
    for (int i=0; i<n; i++) {
      cin >> A[i];
    }
    char current[51];
    for (int i=0; i<51; i++) {
      current[i] = 'a';
    }
    for(int i=0; i<51; i++) {
      cout << current[i];
    }
    cout <<endl;
    for (int j=0; j<n; j++) {
      char c = current[A[j]+1-1];
      if (c == 'a') c='b'; else c='a';
      current[A[j]+1-1] = c;
      for(int i=0; i<51; i++) {
        cout << current[i];
      }
    cout <<endl;
    }
  }



  // ios_base::sync_with_stdio(false); cin.tie(NULL);
}

