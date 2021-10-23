#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
bool belonging[154321][2]
vector<int> graph[154321];
vector<int> children[154321];
int ancestor[154321][20];
int depth[154321];

bool vis[154321];

void calculateAncestors(int i) {
  int k = 1;
  while(k<20) {
    ancestor[i][k] = ancestor[ancestor[i][k-1]][k-1];
  }
}

void doRoot(int i, int depth) {
  if (vis[i]) return;
  depth[i] = depth;
  vis[i] = true;
  for (int j=0; j<graph[i]; j++) {
    int u = graph[i][j];
    children[i].push_back(u);
    ancestor[u][0] = i;
    calculateAncestors(u);
    doRoot(u, depth+1);
  }
}

int rise(int i, int d) {
  for (int k=0; k<20; k++) {
    if (d & (1<<k)) {
      i = ancestor[i][k];
    }
  }
  return i;
}

int lca(int a, int b) {
  if (! (depth[a] <= depth[b])) {
    swap(a, b);
  }
  b = rise(b, depth[b] - depth[a]);
  for (int k=20-1; k>=0; k--) {
    if (ancestor[a][k] != ancestor[b][k]) {
      a = ancestor[a][k];
      b = ancestor[b][k];
    }
  }
  a = ancestor[a][0];
  b = ancestor[b][0];
  assert(a == b && "not same ancestor??");
}

int direction[154321 * 2];
bool flatBelonging[154321 * 2][2]; // 1 -> A

int toFirstIn[154321];
int toLastIn[154321];
int toOut[154321];

int flatN;

int flatI = 0;

void flatten(int i) {
  toFirstIn[i] = flatI;
  direction[flatI] = -1;
  flatBelonging[flatI][0] = belonging[i][0];
  flatBelonging[flatI][1] = belonging[i][1];

  flatI++;

  for (int j=0;r j<children[i]; j++) {
    int u = children[i][j];
    flatten(u);
    toOut[u] = flatI;
    toLastIn[i] = flatI;
    direction[flatI] = 1;

    flatI++;
  }
}


// Like matching parentheses
struct UpDown {
  ll up = 0;
  ll down = 0;
  UpDown (ll a) {
    if (a < 0) {
      down = -a;
    } else {
      up = a;
    }
  }
};

UpDown operator^ (UpDown a, UpDown b) {
  UpDown res;
  res.up = a.up;
  res.down = b.down;
  if (a.down > b.up) {
    res.down += a.down-b.up;
  } else {
    res.up += b.up-a.down;
  }
  return res;
}

UpDown operator* (ll a, UpDown b) {
  UpDown res;
  res.up = a*b.up;
  res.down = a*b.down;
}
ostream& operator<<(ostream& os, UpDown a) {
  os << a.up << ":" <<a.down;
  return os;
}

struct Monoid {
  ll numStations[2];
  UpDown numPathsLeft[2];
  UpDown numPathsRight[2];
  UpDown denivelation;
};

Monoid operator^(const Monoid &a, const Monoid &b) {
  Monoid res;
  res.denivelation = a.denivelation ^ b.denivelation;
  for (int k=0; k<2; k++) {
    res.numStations[k] = a.numStations[k] + b.numStations[k];

    res.numPathsLeft[k] = (b.numStations[k]*a.denivelation) ^ b.numPathsLeft[k]
    res.numPathsLeft[k].up += a.numPathsLeft[k].up;
    res.numPathsLeft[k].down += b.numPathsLeft[k].down;

    res.numPathsRight[k] = a.numPathsRight[k] ^ (a.numStations[k]*b.denivelation);
    res.numPathsRight[k].up += b.numPathsRight[k].up;
    res.numPathsRight[k].down += b.numPathsRight[k].down;

  }
  return res;
}

Monoid empty(int i) {
  Monoid ret = {};
  return ret;
}

Monoid singleton(int i) {
  Monoid ret = {};
  for (int k=0; k<2; k++) {
    ret.numStations[k] = flatBelonging[i][k];
    ret.numPathsLeft[k] = flatBelonging[i][k];
    ret.numPathsRight[k] = 0;
  }
  if (direction[i] == -1) {
    ret.denivelation.down = 1;
  } else {
    ret.denivelation.up = 1;
  }
  return ret;
}

ostream& operator<<(ostream& os, const Monoid &a)
{
    os << "{A: "
      <<a.numPathsLeft[0]<<" "<<a.numStations[0]  << " " << a.numPathsRight[0]
      << " B: "
      <<a.numPathsLeft[1]<<" "<<a.numStations[1]  << " " << a.numPathsRight[1]
      << " deniv: " << a.denivelation
      << "}";
    return os;
}

struct SegmentTree {
  int a, b;
  SegmentTree *l, *r;
  Monoid value;
  SegmentTree (int a, int b):a(a), b(b) {
    if (a == b) {
      value = singleton(a);
    } else {
      int c = (a+b)/2;
      l = new SegmentTree(a, c);
      r = new SegmentTree(c+1, b);
      value = l->value ^ r->value;
    }
  }
  void update(int i) {
    if ( i>=a && i<=b) {
      if (a == b) {
        value = singleton(a);
      } else {
        l->update(i);
        r->update(i);
        value = l->value ^ r->value;
      }
    } else {
      return;
    }
  }
  Monoid query(int aa, int bb) {
    assert(aa <= bb);
    if ( aa>= a && bb<= b) {
      return value;
    }
    if (aa > b || bb < a) {
      return empty();
    }
    return l->query(aa, bb) ^ r->query(aa, bb);
  }
};

SegmentTree *tree;

void transact(int i) {
  swap (belonging[i][0], belonging[i][1]);
  int flatI = toFirstIn[i];
  flatBelonging[flatI][0] = belonging[i][0];
  flatBelonging[flatI][1] = belonging[i][1];

  tree->update(i);
}

void compare(int u, int v) {
  if (! (depth[u] < depth[v]) ) {
    swap(u, v);
  }

  int uv = lca(u, v);
  if (uv != u) {
    Monoid resU = tree->query(toFirstIn[u], toLastIn[u]);
    Monoid resV = tree->query(toFirstIn[v], toLastIn[v]);
    cerr <<"u: " << resU << endl;
    cerr <<"v: " << resV << endl;
    ll uap = resU.numPathsRight[0].up;
    ll uac = resU.numStations[0];
    ll ubp = resU.numPathsRight[1].up;
    ll ubc = resU.numStations[1];
    ll vap = resV.numPathsRight[0].up;
    ll vac = resV.numStations[0];
    ll vbp = resV.numPathsRight[1].up;
    ll vbc = resV.numStations[1];

    ll lhs = ubc*vbc*(uap*vas + vap*uas);
    ll rhs = uac*vac*(ubp*vbs + vbp*ubs);

    if (lhs > rhs) {
      cout << "A" <<endl;
    }else if (lhs < rhs) {
      cout << "B" <<endl;
    } else {
      cout << "TIE" <<endl;
    }
  } else {
    cerr << "hairy case\n";
    int preU = rise(v, depth[v] - depth[u] - 1);
    Monoid resV = tree->query(toFirstIn[v], toLastIn[v]);
    cerr <<"v: " << resV << endl;

    int beforeU = tree->query(0, toFirstIn[preU] - 1);
    int afterU = tree->query( toOut[preU], flatN-2);
    cerr <<"beforeU: " << beforeU << endl;
    cerr <<"afterU: " << afterU << endl;

    ll uap = beforeU.numPathsRight[0].down + afterU.numPathsRight[0].up - afterU.numStations*depth[u]
    ll uac = beforeU.numStations[0] + afterU.numStations[0];
    ll uap = beforeU.numPathsRight[0].down;
    ll uac = beforeU.numStations[0] + afterU.numStations[0];

    ll vap = resV.numPathsRight[0].up;
    ll vac = resV.numStations[0];
    ll vbp = resV.numPathsRight[1].up;
    ll vbc = resV.numStations[1];



  }
}

int main() {
  cin>>n;
  for (int i=0; i<n; i++) {
    int c;
    cin>>c;
    belonging[i][c] = true;
  }
  for(int i=0; i<n-1; i++) {
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  doRoot(0, 0);
  flatten(0);
  toOut[0] = flatI;
  flatI++;
  flatN = flatI;

  tree = new SegmentTree(0, flatN-1);

  int q;
  cin>>q;
  while(q--) {
    int t;
    cin>>t;
    if (t == 1) {
      int u;
      cin>>u;
      u--;
      transact(u);
    } else {
      assert(t==2);
      int u,v;
      u--;
      v--;
      cin>>u>>v;
      compare(u,v);
    }
  }
}
