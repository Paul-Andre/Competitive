#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;



typedef long long ll;

bool chip[200][200];

int T;
int R,C,H,V;

void solve() {
    cin >> R >> C >> H >> V;
    H++;
    V++;

    int tot = 0;
    for(int i=0; i<R; i++) {
      for(int j=0; j<C; j++) {
        char c;
        cin >> c;
        chip[i][j] = c=='@';
        tot += (int)(c == '@');
      }
    }

    int vis = H * V;
    if (tot % vis != 0) {
    cout << "IMPOSSIBLE\n";
    return;
    }
    if (tot % H != 0) {
    cout << "IMPOSSIBLE\n";
    return;
    }
    if (tot % V != 0) {
    cout << "IMPOSSIBLE\n";
    return;
    }

    int h_need = tot / H;
    int h_count = 0;
    vector<int> h_spl;
    h_spl.push_back(0);

    // Horizontal
    int current_count = 0;
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        current_count+= chip[i][j];
      }
      if (current_count == h_need && h_count < H-1) {
        h_count ++;
        current_count = 0;
        h_spl.push_back(i+1);
      }
      if (current_count > h_need) {
        cout << "IMPOSSIBLE\n";
        return;
      }
    }
    if (h_count != H-1) {
      cout << "IMPOSSIBLE\n";
      return;
    }
    h_spl.push_back(R);

    int v_need = tot / V;
    int v_count = 0;
    vector<int> v_spl;
    v_spl.push_back(0);

    // Verical
    current_count = 0;
    for (int j=0; j<C; j++) {
      for (int i=0; i<R; i++) {
        current_count+= chip[i][j];
      }
      if (current_count == v_need && v_count < V-1) {
        v_count ++;
        current_count = 0;
        v_spl.push_back(j+1);
      }
      if (current_count > v_need) {
        cout << "IMPOSSIBLE\n";
        return;
      }
    }
    if (v_count != V-1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    v_spl.push_back(C);


    int tot_need = tot / (H * V);
    for (int i=0; i<h_spl.size()-1; i++) {
      for (int j=0; j<v_spl.size()-1; j++) {
        int cnt = 0;
        for (int ii=h_spl[i]; ii<h_spl[i+1]; ii++) {
          for (int jj=v_spl[j]; jj<v_spl[j+1]; jj++) {
            cnt += chip[ii][jj];
          }
        }
        if (cnt != tot_need) {
          cout << "IMPOSSIBLE\n";
          return;
        }
      }
    }


    cout << "POSSIBLE\n";
    return;

}

int main() {
  cin >> T;
  for(int t = 1; t <= T; t++) {
    cout << "Case #"<<t<<": ";
    solve();

  }
}

