#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;

string P[100];
int a[100];
int b[100];

void solve() {
  cin >> N;
  for(int i=0; i<N ;i++) {
    cin >> P[i];
    a[i] = 0;
    b[i] = P[i].size() - 1;
  }
  string begin;
  string end;
  while(true) {
    char have = 0;
    for (int i=0; i<N ;i++) {
      char c = P[i][b[i]];
      if (c != '*') {
        if (have == 0 ) {
          have= c;
        } else if (have != c) {
          cout << "*\n";
          return;
        }
          b[i] --;
      } else {
        // nothing
      }
    }
    if (have == 0) break;
    end.push_back(have);
  }
  while(true) {
    char have = 0;
    for (int i=0; i<N ;i++) {
      char c = P[i][a[i]];
      if (c != '*') {
        if (have == 0 ) {
          have= c;
        } else if (have != c) {
          cout << "*\n";
          return;
        }
          a[i] ++;
      } else {
        // nothing
      }
    }
    if (have == 0) break;
    begin.push_back(have);
  }

  for (int i=0; i<N; i++) {
    while(a[i] != b[i]) {
      char c = P[i][a[i]];
      if (c != '*') {
        begin.push_back(c);
      }
      a[i] ++;
    }
  }


  cout << begin;
  for (int i=end.size()-1; i>=0; i--) {
    cout << end[i];
  }
  cout << endl;
}


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int T;
  cin >> T;
  for(int i=1; i<=T; i++) {
    cout << "Case #" << i << ":  ";
    solve();
  }
}

