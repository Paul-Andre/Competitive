#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif

int beats(char a, char b) {
  if (a == b) return 0;
  if( (a == 'R' && b == 'S')
    || (a == 'S' && b == 'P')
    || (a == 'P' && b == 'R')) return 1;
  return -1;
}

string solve() {
  int N;
  cin >>N;
  vector<string> v;
  for (int i=0; i<N; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }

  string ret;
  for (int j=0; j<500; j++){

    map<char,int> m;
    for (int i=0; i<N; i++) {
      m[v[i][j%v[i].size()]] ++;
    }
    int ss = m.size();
    if (ss == 1) {
      if (m['R']) {
        ret.push_back('P');
      }else if (m['P']) {
        ret.push_back('S');
      }else if (m['S']) {
        ret.push_back('R');
      } else exit(-1);
      return ret;
    } else if (ss == 2) {
      if (!m['R']) {
        ret.push_back('S');
      }else if (!m['P']) {
        ret.push_back('R');
      }else if (!m['S']) {
        ret.push_back('P');
      } else exit(-1);
    } else {
      return "IMPOSSIBLE";
    }
  }
  for (int i=0; i<N; i++) {
    int j=0;
    while(true) {
      char r= ret[j%500];
      char a = v[i][j % (v[i].size())];
      if (beats(r,a) == 1) goto continue_outer;
      if (beats(r,a) == -1) return "IMPOSSIBLE";
      j++;
      if (j%500 == 0 && j%v[i].size() == 0) {
        return "IMPOSSIBLE";
      }
    }
continue_outer:
  }
}

int main() {
  int T;
  cin >> T;
  for (int ttt=1; ttt<=T; ttt++) {
    cout << "Case #" << ttt << ": ";
    cout << solve() <<endl;
  }
}
