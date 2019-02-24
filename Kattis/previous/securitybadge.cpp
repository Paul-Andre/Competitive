#include <bits/stdc++.h>
using namespace std;

int N;
int L;
int B;

int S;
int D;

struct Lock {
  int dest;
  int x, y;
}; //classic, don't forget semicolon after struct declaraction

vector<Lock> G[2000];
bool vis[2000];

bool visit(int i, int n) {
  if (vis[i]) return false;
  vis[i] = true;
  if (i == D) return true;
  for (int j=0; j<G[i].size(); j++) {
    Lock l = G[i][j];
    int u = l.dest;
    if (l.x <= n && n <= l.y && visit(u,n)) return true;
  }
  return false;
}

int main() {
  cin>>N>>L>>B;
  cin>>S>>D;
  vector<int> landmarks;
  landmarks.push_back(1);
  landmarks.push_back(B+1);
  for(int i=0; i<L; i++) {
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    landmarks.push_back(x);
    landmarks.push_back(y+1);
    G[a].push_back({b,x,y});
  }
  sort(landmarks.begin(), landmarks.end());
  landmarks.erase(unique(landmarks.begin(), landmarks.end()), landmarks.end());
  /*
  for (int i=0; i<landmarks.size(); i++) {
    cerr << landmarks[i] << " ";
  }
  cerr <<endl;
  */
  int tot = 0;
  for (int i=0; i<landmarks.size()-1; i++) {
    int ll = landmarks[i];
    for (int j=0; j<2000; j++) {
      vis[j] = false;
    }
    if (visit(S, ll)) {
      //cerr << "Successfully visited " << ll <<endl;
      tot += landmarks[i+1] - landmarks[i];
    }
  }
  cout <<tot <<endl;
}

