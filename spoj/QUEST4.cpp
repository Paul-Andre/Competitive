#include <bits/stdc++.h>
using namespace std;

struct Vertex {
  vector<int> links;
  bool visited = false;
  int matched = -1;
};

int n;

Vertex A[120];
Vertex B[120];

bool visitB(int i);
bool visitA(int i) {
  if (A[i].visited) return false;
  //cerr << "visitA " << i << endl;
  A[i].visited = true;
  for (int j=0; j<A[i].links.size(); j++) {
    int u = A[i].links[j];
    if (u != A[i].matched && visitB(u)) {
      B[u].matched = i;
      A[i].matched = u;
      return true;
    }
  }
  return false;
}

bool visitB(int i) {
  if (B[i].visited) return false;
  //cerr << "visitB " << i << endl;
  B[i].visited = true;
  if (B[i].matched == -1) {
    return true;
  }
  int u = B[i].matched;
  if (visitA(u)) {
    return true;
  }
  return false;
}

void solve() {
  for (int i=0; i<120; i++) {
    Vertex v;
    A[i] = B[i] = v;
  }
  cin >> n;
  for (int i=0; i<n; i++) {
    int x,y;
    cin >> x >> y;
    A[x].links.push_back(y);
    B[y].links.push_back(x);
  }
  int result = 0;
  while(true){
    for (int i=0; i<120; i++) {
      A[i].visited = false;
      B[i].visited = false;
    }
    for (int i=0; i<120; i++) {
      if (A[i].matched == -1) {
        if (visitA(i)) {
          result += 1;
          //cerr << "asdf " << i << endl;
          goto continue_outer;
        }
      }
    }
    break;
continue_outer:;
  }
  cout << result << endl;
}


int main() {
  int k;
  cin >> k;
  while(k--) {
    solve();
  }
}
