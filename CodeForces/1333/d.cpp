#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
// L = 0, R = 1
ll A[3001];
ll B[3001];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> k;
  for (int i=0; i<n; i++) {
    char c;
    cin >> c;
    A[i] = (c=='R');
    B[i] = (c=='R');
  }
  int minSteps = 0;
  int maxSteps = 0;
  while(true) {
    bool did = false;
    for (int i=0; i<n-1; i++) {
      if (A[i] == 1 && A[i+1] == 0) {
        A[i] = 0; A[i+1] = 1;
        i++;
        did = true;
        maxSteps ++;
      }
    }
    if (did) {
      minSteps ++;
      if (minSteps > 3000000) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      break;
    }
  }
  if (! (k >= minSteps && k <= maxSteps) ) {
    cout << -1 << endl;
  } else {
    int rem = k-minSteps;
      vector<int> have;
    while(true) {
      bool did = false;
      for (int i=0; i<n-1; i++) {
        if (B[i] == 1 && B[i+1] == 0) {
          B[i] = 0; B[i+1] = 1;
          i++;
          if (!did || rem > 0) {
            if (have.size() != 0) {
            cout << have.size() << " ";
            for (int a:have) {
              cout << a << " ";
            }
            cout << "\n";
            have.clear();
            }
            if (did) {
              rem--;
            }
          }
          did = true;
          have.push_back(i);
        }
      }
      if (did) {
      } else {
        break;
      }
    }
            cout << have.size() << " ";
            for (int a:have) {
              cout << a << " ";
            }
    cout << endl;
  }
}
  
