#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int K, N;
map<char, int> symbolsToInt;
map<int, char> intToSymbol;

#define MOD 1000000007

// [start][end][resulting letter]
ll T[210][210][26];

ll ttime[26][26];
char result[26][26];

int main() {

  cin >> K;
  for (int i=0; i<K; i++) {
    char c;
    cin >> c;
    symbolsToInt[c] = i;
    intToSymbol[i] = c;
  }

  for (int i=0; i<K; i++) {
    for (int j=0; j<K; j++) {
      int v;
      char minus, c;
      cin>>v>>minus>>c;
      assert(minus == '-');
      ttime[i][j] = v;
      result[i][j] = symbolsToInt[c];
    }
  }
  cin>>N;

  for(int iii=0; iii<N; iii++) {
    string s;
    cin >> s;
    if (s == "0") break;
    int m = s.size();

    for (int i=0; i<210; i++) {
      for (int j=0; j<210; j++) {
        for (int k=0; k<26; k++) {
          T[i][j][k] = 500000000;
        }
      }
    }

    for (int i=0; i<m; i++) {
      int ss = symbolsToInt[s[i]];
      T[i][i][ss] = 0;
    }

    for (int k=2; k<=m; k++) {
      for (int i=0; i<m+1-k; i++) {
        for (int j=1; j<k; j++) {
          for (int ra = 0; ra<K; ra++) {
            for (int rb = 0; rb<K; rb++) {
              int rr = result[ra][rb];
              ll ta = T[i][i+j-1][ra];
              ll tb = T[i+j][i+k-1][rb];
              ll tt = ttime[ra][rb] + ta + tb;
              T[i][i+k-1][rr] = min(T[i][i+k-1][rr], tt);
            }
          }
        }
      }
    }

    char bestSym = '*';
    ll bestTime = 10000000000;
    for (int i=0; i<K; i++) {
      int t = T[0][m-1][i];
      if (t < bestTime) {
        bestTime = t;
        bestSym = intToSymbol[i];
      }
    }
    assert(bestSym != '*');
    cout << bestTime << "-" << bestSym <<endl;
  }
  
  string asdf;
  cin >> asdf;
  assert(asdf == "0");
  
}

