#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int n = s.size();
    int tot0[10][10] = {0};
    int tot1[10][10] = {0};
    memset(tot1, -1, sizeof(tot1));
    for(int i=0; i<n; i++) {
      int c=s[i]-'0';
      for(int d=0; d<10; d++) {
        if (c != d) {
          if (tot1[c][d] != -1) {
            tot0[d][c] = tot1[c][d] + 1;
          }
          tot1[d][c] = tot0[c][d] + 1;
        }
      }
      /*
    for (int i=0; i<10; i++) {
      for (int j=0; j<10; j++) {
        cerr << tot[i][j] << " ";
      }
      cerr << endl;
    }
    cerr << endl;
    */
    }

    int best = 0;

    for (int i=0; i<10; i++) {
      for (int j=0; j<10; j++) {
        best = max(best, tot0[i][j]);
      }
    }

    for (int i=0; i<10; i++) {
      int tot = 0;
      for (int j=0; j<n; j++) {
        tot += (s[j] == '0' + i);
      }
      best = max(best, tot);
    }

    cout << (n-best) << endl;
  }
}

