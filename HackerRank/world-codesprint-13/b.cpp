
#include <bits/stdc++.h>

using namespace std;



int find(int i, int *parent, int *rk) {
    if (parent[i] == 0) {
        return i;
    }
    else {
        int par = find(parent[i], parent, rk);
        parent[i] = par;
        return par;
    }
}

void join(int a, int b, int *parent, int *rk) {
    int pa =find(a, parent, rk);
    int pb =find(b, parent, rk);
    if (pa != pb) {
        if (rk[pa] > rk[pb]) {
            parent[pb] = pa;
        }
        else if (rk[pb] > rk[pa]) {
            parent[pa] = pb;
        }
        else {
            parent[pa] = pb;
            rk[pb] ++;
        }
    }
}


int n, m, a, b;
int f[4];


int parent[112345];
int rk[112345];
int size[112345][4];

unordered_map<string,int> string_to_int;
unordered_map<int,string> int_to_string;

int main() {
  cin>>n>>m>>a>>b>>f[0]>>f[1]>>f[2];
  f[3] = b;

  for (int i=0; i<n; i++) {
    string n;
    int g;
    cin>>n>>g;
    string_to_int[n] = i+1;
    int_to_string[i+1] = n;
    size[i+1][g-1] = 1;
    size[i+1][3] = 1;
  }


  for(int i=0; i<m; i++) {
    string xx, yy;
    cin>>xx>>yy;
    int x = string_to_int[xx];
    int y = string_to_int[yy];

    int xp = find(x, parent, rk);
    int yp = find(y, parent, rk);
    bool good = true;
    for (int i=0; i<4; i++) {
      if (size[xp][i] + size[yp][i] > f[i]) good = false;
    }
    if (good && xp != yp) {
      //cerr << "join " << xx << " " << yy <<endl;
      join(xp, yp, parent, rk);
      int p = find(xp, parent, rk);
      for (int i=0; i<4; i++) {
        size[p][i] = size[xp][i] + size[yp][i];
      }
    }
  }

  int ma = 0;
  for (int i=1; i<=n; i++) {
    ma = max(ma, size[find(i, parent, rk)][3]);
  }
  if (ma < a) {
    cout << "no groups\n";
  }
  else {

    vector<string> picked;
    for (int i=1; i<=n; i++) {
      if (size[find(i, parent, rk)][3] == ma) {
        picked.push_back(int_to_string[i]);
      }
    }
    sort(picked.begin(), picked.end());
    for (string &s: picked) {
      cout << s <<endl;
    }
  }


}
