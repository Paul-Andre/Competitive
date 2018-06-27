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

typedef pair<int,int> pii;

int dx[9] = {0,1,1,1,0,-1,-1,-1,0};
int dy[9] = {0,1,0,-1,-1,-1,0,1,1};

#define SQR(x) ((x)*(x))

void solve() {

  int N;
  cin >> N;
  vector<pii> v(N);

  for (int i=0;i<N; i++) {
    int x,y;
    cin >> x>> y;
    v[i] = pii(x,y);
  }

  int m = 100000000;

  for (int xi=0; xi<=8; xi++) {
    for (int yi=0; yi<=8; yi++) {
      vector<pii> w = v;
      for (int j=0; j<=1000; j++) {

        bool good = true;
        for(int i=1; i<N; i++) {
          if (w[i] != w[i-1]) good = false;
        }

        if (good) {
          m  = min(m, j);
          break;
        }

        int x = xi;
        int y = yi;
        for(int i=0; i<N; i++) {
          int mm = 100000000;
          int dir = 0;
          int xx = w[i].first;
          int yy = w[i].second;
          for(int k=0; k<9; k++) {
            int d = ( SQR(xx+dx[k]-x) + SQR(yy+dy[k]-y));
            if (d < mm) {
              mm = d;
              dir = k;
            }
          }
          w[i].first += dx[dir];
          w[i].second += dy[dir];
          x = w[i].first;
          y = w[i].second;
        }
      }
    }
  }

  cout << m << endl;
}








int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cout << "Case #"<<t<<": ";
    solve();

  }
}

