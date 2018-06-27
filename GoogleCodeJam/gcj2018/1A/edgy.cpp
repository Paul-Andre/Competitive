#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;

int T;
int N;
int W[200];
int H[200];
int P;
int mmin[200];
double mmax[200];

bool got[200][90000];
bool used[200][90000];

void solve() {
  cin >> N >> P;

  double p_before = 0;

  int summin = 0;

  for(int i=0; i<N; i++) {
    cin >> W[i] >> H[i];
  }
  for(int i=0; i<N; i++) {
    P -= 2*(W[i] + H[i]);

    p_before += 2*(W[i] + H[i]);

    mmin[i] = 2*min(W[i], H[i]);
    mmax[i] = 2*sqrt((double)(W[i]*W[i] +  H[i]*H[i] ));
  summin += mmin[i];
  }

  P = min(80000, P);

  sort(mmin, mmin + N);
  sort(mmax, mmax + N);

  for (int i=0; i < N; i++) {
    for (int j=0; j <= summin; j++) {
      got[i][j] = false;
      used[i][j] = false;
    }
  }

  for (int i=0; i < N; i++) {
    got[i][0] = true;
  }
  got[0][mmin[0]] = true;
  used[0][mmin[0]] = true;

  for (int i=1; i < N; i++) {
    for (int j=0; j<=summin; j++) {

      // needed if we include:
      int nnii = j - mmin[i];
      if (nnii >= 0 && got[i-1][nnii]) {
        got[i][j] = true;
        used[i][j] = true;
      } else {
        got[i][j] =got[i-1][j];
      }
    }
  }

  for (int k=P; k>=0; k--) {
    if (got[N-1][k]) {
      double up_bound = 0;
      int next = k;
      for (int i=N-1; i>=0; i--) {
        if (used[i][next]) {
          up_bound += mmax[i];
          next -= mmin[i];
        } else {
        }
      }
      cout.precision(12);

      cerr << up_bound <<"  ;  ";

      up_bound = min(up_bound, (double)P);

      cout << up_bound+p_before << endl;
      return;
    }
  }
}





int main() {
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cout << "Case #"<<t<<": ";
    solve();

  }
}

