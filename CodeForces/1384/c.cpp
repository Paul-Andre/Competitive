#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string A,B;
    cin >> A >> B;
    bool possible = true;
    vector<pair<int,int>> P;
    for (int i=0; i<n; i++) {
      int a = A[i]-'a';
      int b = B[i]-'a';
      if (b < a) possible = false;
      if (b > a) {
        P.emplace_back(a,b);
      }
    }
    if (!possible) {
      cout<< "-1\n";
      continue;
    }
    sort(P.begin(), P.end(), [](pair<int,int> a, pair<int,int> b) {
        int ad = a.second - a.first;
        int bd = b.second - b.first;
        if (ad != bd) {return ad < bd;}
        return a.first < b.first;
        });
    bool G[20][20] = {};
    for (int i=0; i<20; i++) {
      G[i][i] = true;
    }

    int cnt = 0;
    for (int i=0; i<P.size(); i++) {
      pair<int,int> p = P[i];
      if (G[p.first][p.second]) continue;
      G[p.first][p.second] = true;
      cnt ++;
      for (int j=0; j<20; j++) {
        for (int k=0; k<20; k++) {
          if (G[j][p.first] && G[p.second][k]) {
            G[j][k] = true;
          }
        }
      }
    }
    cout << cnt <<endl;
  }
}

