#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> tree[200010];
int subtree[200010];
int cnt[200010];

bool needGenderChange[200010];

void traverse(int i) {
  int notNeed = 0;
  for (int j=0; j<tree[i].size(); j++) {
    int u = tree[i][j];
    traverse(u);
    notNeed += (int)(!needGenderChange[u]);
  }
  if ((cnt[i] + notNeed)%2 == 1) {
    needGenderChange[i] = true;
  }
}

void print(int i) {
  for (int j=0; j<tree[i].size(); j++) {
    int u = tree[i][j];
    if (!needGenderChange[u]) {
      print(u);
    }
  }
  cout << i << endl;
  for (int j=0; j<tree[i].size(); j++) {
    int u = tree[i][j];
    if (needGenderChange[u]) {
      print(u);
    }
  }
}


int main() {

  cin>>n;
  int head;
  for(int i=1; i<=n; i++) {
    int d;
    cin >> d;
    if (d==0) {

      head = i;
      continue;
    }
    tree[d].push_back(i);
    cnt[d]++;
    cnt[i]++;
  }

  traverse(head);
  if (needGenderChange[head]) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  print(head);
}



