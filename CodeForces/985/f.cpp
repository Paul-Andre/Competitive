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


int n, m;
string s;
int t[212345][26];

void solve() {
  cin>>n>>m;
  cin>>s;
  for(int i=0; i<n; i++) {
    for (int j=0; j<26; j++) {
      t[i+1][j] = t[i][j];
    }
    t[i+1][s[i]-'a'] ++;
  }
  for (int i=0; i<m ; i++){
    int x, y, len;
    cin>>x>>y>>len;
    map<int,int> cnt;
    for (int j=0; j<26; j++) {
      int a = t[x+len-1][j] - t[x-1][j];
      int b = t[y+len-1][j] - t[y-1][j];
      cnt[a]++;
      cnt[b]--;
    }
    bool f = true;
    for (auto p: cnt){
      if (p.second != 0) {
        f = false;
      }
    }
    if (f) cout << "YES\n";
    else cout << "NO\n";
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}

