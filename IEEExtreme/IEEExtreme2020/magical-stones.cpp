#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int S[154321];

vector<int> back[154321];

int vis[154321];
bool isCyc[154321];

int edgeDist[154321];
int ofLength[154321];

map<int,int> giveTail;

int markCycles(int i) {
  if (vis[i] == 1) return i;
  if (vis[i] == 2) return 0;

  vis[i] = 1;
  shared_ptr<void> _(nullptr, bind([&]{vis[i] = 2;}));

  //cerr << i << " i\n";

  int r =markCycles(S[i]);
  if (r == 0) return 0;

  isCyc[i]=true;

  if (r == i) return 0;
  else return r;
}

void fromEdges(int i) {
  if (vis[i]) return;
  vis[i] = 1;
  for (int j=0; j<back[i].size();j++){
    int y = back[i][j];
    fromEdges(y);
    edgeDist[i] = max(edgeDist[i], edgeDist[y]+1);
  }
}

  
int main() {
  int n;
  cin>>n;
  for (int i=1; i<= n;i++) {
    int x;
    cin>>x;
    S[i] = x;
    back[x].push_back(i);
  }

  for (int i=1; i<=n; i++) {
    if (!vis[i]){
      markCycles(i);
    }
  }
  for (int i=1; i<=n; i++) {
    vis[i] = 0;
  }
  for (int i=1; i<=n; i++) {
    if (!isCyc[i] && !vis[i]){
      fromEdges(i);
    }
  }
  for (int i=1; i<=n; i++) {
    if (!isCyc[i]) {
      ofLength[edgeDist[i]]++;
    }
  }
  int cyc = 0;
  for (int i=1; i<=n; i++) {
    if (isCyc[i]) cyc++;
  }

  int acc = 0;
  for (int i=154321-1; i>=0; i--) {
    acc += ofLength[i];
    giveTail[acc] = i;
  }
  cerr << cyc <<endl;
  for (int i=0; i<10; i++) {
    cerr << isCyc[i] << " ";
  }cerr << endl;
  for (int i=0; i<10; i++) {
    cerr << edgeDist[i] << " ";
  }cerr << endl;

  int q;
  cin>>q;
  for (int i=0; i<q; i++) {
    int x;
    cin>>x;
    int y = x-cyc;
    if (giveTail.count(y) == 0) {
      cout << "-1\n";
    }else {
      cout << giveTail[y] << endl;
    }
  }
}


