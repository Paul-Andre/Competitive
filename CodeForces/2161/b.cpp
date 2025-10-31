#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int G[104][104];

int found = false;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

void fill_2(int i, int j) {
  for (int k=0; k<4; k++) {
    int ii = i+dx[k];
    int jj = j+dy[k];
    if (G[ii][jj] == 1) {
      G[ii][jj] = 2;
      fill_2(ii,jj);
    }
  }
}

int num_components() {
  int ret = 0;
  for (int i=2; i<n+2; i++) {
    for (int j=2; j<n+2; j++) {
      if (G[i][j] == 1) {
        ret+=1;
        fill_2(i,j);
      }
    }
  }
  for (int i=2; i<n+2; i++) {
    for (int j=2; j<n+2; j++) {
      if (G[i][j] == 2) {
        G[i][j] = 1;
      }
    }
  }
  return ret;
}

/* bool vis(int i, int j) { */
/*   for (; i<n+2; i++) { */
/*     for (; j<n+2; j++) { */
/*       bool good = true; */
/*       if (G[i][j]) good = false; */

/*       if (G[i-2][j] && G[i-1][j]) good = false; */
/*       if (G[i-1][j] && G[i+1][j]) good = false; */
/*       if (G[i+1][j] && G[i+2][j]) good = false; */

/*       if (G[i][j-2] && G[i][j-1]) good = false; */
/*       if (G[i][j-1] && G[i][j+1]) good = false; */
/*       if (G[i][j+1] && G[i][j+2]) good = false; */

/*       if (good) { */
/*         G[i][j] = true; */
/*         bool ret = vis(i,j); */
/*         G[i][j] = false; */
/*         if (ret) return ret; */
/*       } */
/*     } */
/*     j=2; */
/*   } */
/*   return num_components()==1; */
/* } */


bool check(set<int> diffs) {
  if (diffs.size() < 2) return true;
  if (diffs.size() == 2) {
    auto it = diffs.begin();
    int a = *it;
    ++it;
    int b = *it;
    if (abs(a-b) == 1) return true;
  }
  return false;
}

int main(){
  int t;
  cin>>t;
  for(int ttt=0;ttt<t;ttt++) {
    cin>>n;
    memset(G, 0, sizeof(G));
    found = false;
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        char c;
        cin>>c;
        G[i+2][j+2] = c=='#';
      }
    }
    bool good = true;
    for (int i=2; i<n+2; i++) {
      for (int j=2; j<n+2; j++) {
        if (G[i-1][j] && G[i][j] && G[i+1][j]) good = false;
        if (G[i][j-1] && G[i][j] && G[i][j+1]) good = false;
      }
    }
    if (!good) {
      cout << "NO" <<endl;
      continue;
    }
    if (good && num_components()==1){
      cout << "YES" <<endl;
      continue;
    }
    set<int> diffs_pos;
    set<int> diffs_neg;
    for (int i=2; i<n+2; i++) {
      for (int j=2; j<n+2; j++) {
        if (G[i][j]) {
          diffs_pos.insert(i+j);
          diffs_neg.insert(i-j);
        }
      }
    }
    good = check(diffs_pos) || check(diffs_neg);

    cout << (good?"YES":"NO") <<endl;
  }
}
