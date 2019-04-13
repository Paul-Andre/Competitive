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

bool vis[32][32];
int R, C;

#define FOR(a,b) for(int a=0; a< R; a++) for (int b=0; b<C; b++)

vector<pair<int,int>> st;

bool go(int i, int j) {
  vis[i][j] = true;
  st.emplace_back(i,j);
  if (st.size() == R*C) return true;
  //cerr << st.size() << endl;
  //cerr << i << " " << j << endl;
  FOR(xx,yy) {
    int x = (xx + i) % R;
    int y = yy;
    if (x != i && y != j && (x+y) != (i+j) && (x-y) != (i-j) && !vis[x][y]) {
      if (go(x,y)) return true;
    }
  }
  st.pop_back();
  vis[i][j] = false;
  return false;
}


bool sw = false;

void pront(int i, int j) {
  if (!sw) {
        cout << i << " " << j <<endl;
  } else {
        cout << j << " " << i <<endl;
  }

}


void solve() {
  sw = false;
  cin >>R >>C;
  if ((R <= 5 && C <= 5 && !(R == 5 && C == 5)) || R == 2 || C == 2 ) {
    memset(vis, 0, sizeof(vis));
    st.clear();
    FOR(i,j) {
      if (go(i, j)) break;
    }
    if (st.size()) {
      cout << "POSSIBLE\n";
      for (auto p: st) {
        cout << p.first+1 << " " <<p.second+1 <<endl;
      }
    } else {
      cout << "IMPOSSIBLE\n";
    }
  } else {
    cout << "POSSIBLE\n";


    if (R == 3) {
      sw = true;
      int tmp = R;
      R = C;
      C = tmp;
    }

    int i=0;
    for (; i<R-2; i++) {
      for (int j=0; j<C; j++) {
        pront( i + 2*(j%2) +1, j+1 );
      }
    }
    for (int j=0; j<C; j++) {
      pront( i - (R-2)*(j%2) +1, j+1 );
    }
    i++;
    for (int j=0; j<C; j++) {
      pront( i - (R-2)*(j%2) +1, j+1);
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int ttt=1; ttt<=T; ttt++) {
    cout << "Case #" << ttt << ": ";
    solve();
  }
}
