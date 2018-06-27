#include <bits/stdc++.h>
using namespace std;

int n, q;

vector<int> g[212345];
bool vis[212345];
int level[212345];
int parent[212345];

int first[212345];
int last[212345];

int orig[512345];

int p = 1;

void trav(int i, int lvl) {
  vis[i] = true;
  level[i] = lvl;
  

  for(int j=0; j<g[i].size(); j++) {
    int u = g[i][j];
    if (!vis[u]) {

      first[u] = p;
      orig[p] = i;
      p++;

      parent[u] = i;

      trav(u, lvl+1);


    }
  }

  last[i] = p;
  orig[p] = i;
  p++;
}

struct node{
  int a, b;
  node *left, *right;
  int maxx;
  int cnt;

  node(int aa, int bb) {
    a = aa;
    b = bb;
    if (aa == bb) {
      left = right = nullptr;
      maxx = orig[aa];
    } else {
      int c = (a + b)/2;
      left = new node(a, c);
      right = new node(c+1, b);
      if (level[left->maxx] < level[right->maxx]){
        maxx = left->maxx;
      }else maxx = right->maxx;
    }
    cnt = 0;
  }

  void inc_cnt(int c, int v) {
    if (c < a || c > b) return;
    cnt += v;
    if (a == b) return;
    left->inc_cnt(c, v);
    right->inc_cnt(c, v);
  }

  pair<int,int> get(int aa, int bb) {
    if (bb < a || aa > b) return pair<int,int>(0,0);
    if (aa <= a && bb >= b) {
      return pair<int,int>(maxx, cnt);
    } else {
      pair<int,int> l = left->get(aa,bb);
      pair<int,int> r = right->get(aa,bb);
      int mm;
      if (level[l.first] < level[r.first]){
        mm = l.first;
      }else mm = r.first;
      return pair<int,int>(mm, l.second + r.second);
    }
  }
      
};

bool blocked[212345];


int which(int i, int j) {
  if (parent[i] == j) return i;
  if (parent[j] == i) return j;
  return 0;
}

node *root;

int main() {

  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  level[0] = 512345;

  first[1] = p;
  orig[p] = 0;
  p++;

  cin >> n;
  for (int i =1; i<n; i++) {
    int x, y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  trav(1,1);

  /*
  for (int i=1; i<p; i++) {
    cerr << orig[i] << " ";
  }
  cerr << endl;
  */


  root =  new node(1, p-1);

  cin >>q;
  for (int qqq=0; qqq<q; qqq++) {
    char cmd;
    int x, y;
    cin>>cmd>>x>>y;
    if (cmd =='d') {
      int z = which(x,y);
      if (z == 0) continue;
      if (blocked[z]) continue;

      blocked[z] = true;

      root->inc_cnt(first[z], 1);
      root->inc_cnt(last[z], -1);

    }else if (cmd == 'c') {
      int z = which(x,y);
      if (z == 0) continue;
      if (!blocked[z]) continue;

      blocked[z] = false;

      root->inc_cnt(first[z], -1);
      root->inc_cnt(last[z], 1);
    }else {

      /*
      cerr << " asdf: ";
      for(int i=0; i<20; i++) {
        cerr << root->get(i,i).second << " ";
      }
      cerr << endl;
      */

      if (x == y) {
        cout << 0 << endl;
        continue;
      }
      if (last[y] < first[x]) {
        int tmp =x;
        x = y;
        y = tmp;
      }
      int mi = first[x]+1;
      int ma = last[y]-1;
      //cerr << "   mi ma " << mi << " " << ma << endl;
      pair<int,int> p = root->get(mi,ma );
      //cerr << "   wew  "<<p.first << " " << p.second <<endl;
      
      int anc = p.first;
      if (level[anc] > level[x]) {
        anc = x;
      }
      if (level[anc] > level[y]) {
        anc = y;
      }
      
      bool good = true;

      if (anc == y || anc == x) {
        if (p.second != 0) good =false;
      }
      else {
        if(root->get(mi, last[anc]-1).second != 0 || root->get(first[anc]+1, ma).second != 0) good = false;
      }

      if (!good) {
        cout << "Impossible\n";
      }else {
        cout << level[x] + level[y] - level[anc]*2 <<endl;
      }
    }
  }
}









