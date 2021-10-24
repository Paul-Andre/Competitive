#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 9;
const long long INF = 2000000000000000007;
const int d = 2; ///dimension

struct point {
  int p[d];
  bool operator !=(const point &a) const {
    bool ok = 1;
    for(int i = 0; i < d; i++) ok &= (p[i] == a.p[i]);
    return !ok;
  }
  bool operator ==(const point &a) const {
    bool ok = 1;
    for(int i = 0; i < d; i++) ok &= (p[i] == a.p[i]);
    return ok;
  }
};

ostream& operator<<(ostream& os, point a) {
  os << a.p[0] << ","<< a.p[1];
  return os;
}

struct kd_node {
  int axis, value;
  point p;
  kd_node *left, *right;
  bool exists;// = true;
};

struct cmp_points {
  int axis;
  cmp_points() {}
  cmp_points(int x): axis(x) {}
  bool operator () (const point &a, const point &b) const {
    return a.p[axis] < b.p[axis];
  }
};

typedef kd_node* node_ptr;

int n;

long long squared_distance(point a, point b) {
  long long ans = 0;
  for(int i = 0; i < d; i++) ans += (a.p[i] - b.p[i]) * 1ll * (a.p[i] - b.p[i]);
  return ans;
}

void build_tree(node_ptr &node, int from, int to, int axis, point *arr) {
  if(from > to) {
    node = NULL;
    return;
  }

  node = new kd_node();

  if(from == to) {
    node->p = arr[from];
    node->left = NULL;
    node->right = NULL;
    node->exists = true;
    return;
  }

  int mid = (from + to) / 2;

  nth_element(arr + from, arr + mid, arr + to + 1, cmp_points(axis));
  node->value = arr[mid].p[axis];
  node->axis = axis;
  build_tree(node->left, from, mid, (axis + 1) % d, arr);
  build_tree(node->right, mid + 1, to, (axis + 1) % d, arr);
}


void print_node(node_ptr node) {
  if (node == NULL) {
    cerr << "{}";
    return;
  }

  if(node->left == NULL && node->right == NULL) {
    cerr << node->p;
    return;
  }

  cerr<<"{";
  print_node(node->left);
  cerr<<" "<<node->axis << "|"<<node->value<< " ";
  print_node(node->right);
  cerr<<"}";
}

void nearest_neighbor(node_ptr node, point q, long long &ans, point &ret) {
  if(node == NULL) return;

  if(node->left == NULL && node->right == NULL) {
    if(node->exists)
    {
      ll dist = squared_distance(node->p, q);
      /*
      cerr << "adf "<<" " << node->p << endl;
      cerr<<dist<<endl;
      */

      if (dist < ans) {
        ans = dist;
        ret = node->p;
      }
    }
    return;
  }

  if(q.p[node->axis] <= node->value) {
    nearest_neighbor(node->left, q, ans, ret);
    if(q.p[node->axis] + sqrt(ans) >= node->value) nearest_neighbor(node->right, q, ans, ret);
  }

  else {
    nearest_neighbor(node->right, q, ans, ret);
    if(q.p[node->axis] - sqrt(ans) <= node->value) nearest_neighbor(node->left, q, ans, ret);
  }
}

bool deletePoint(node_ptr node, point q) {
  if(node == NULL) return false;

  if(node->left == NULL && node->right == NULL) {
    if(node->p == q && node->exists)
    {
      node->exists = false;
      return true;
    }
  }

  if(q.p[node->axis] <= node->value) {
    if (deletePoint(node->left, q)) return true;
  }
  if(q.p[node->axis] >= node->value) {
    if ( deletePoint(node->right, q)) return true;
  }
  return false;
}


int extractI(point p, map<pair<int,int>, vector<int>> &ptToI) {
  const pair<int,int> a(p.p[0], p.p[1]);
  int ret = ptToI[a].back();
  ptToI[a].pop_back();
  return ret;
}

node_ptr root[3];
map<pair<int,int>, vector<int>> ptToI[3];
point arr[3][N], pts[3][N];

int main() {
  scanf("%d", &n);
  for(int k=0; k<3; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < d; j++) scanf("%d", &arr[k][i].p[j]);
      pts[k][i] = arr[k][i];
    }
    build_tree(root[k], 1, n, 0, arr[k]);
    for(int i = 1; i <= n; i++) {
      ptToI[k][make_pair(pts[k][i].p[0],pts[k][i].p[1])].push_back( i);
    }
  
    /*
    cerr << "{";
    for(const auto& [key, value]: ptToI[k]) {
      cerr << "[";
      for (auto v: value) {
        cerr<<v<<" ";
      }
      cerr << "]";
    }
    cerr << "}"<<endl;
    */

  }
  //print_node(root);

  for(int i = 1; i <= n; i++) {
    point p = pts[0][i];
    auto ret1 = p;

    long long ans;
    
    ans = INF;
    point ret2;
    nearest_neighbor(root[1], p, ans, ret2);
    assert(ans != INF);
    deletePoint(root[1], ret2);

    ans = INF;
    point ret3;
    nearest_neighbor(root[2], p, ans, ret3);
    assert(ans != INF);
    deletePoint(root[2], ret3);

    cerr << ret1 << " " << ret2 << " " << ret3 <<endl;
    cout
      << extractI(ret1, ptToI[0]) << " "
      << extractI(ret2, ptToI[1]) << " "
      << extractI(ret3, ptToI[2]) << endl;
    
  }
  return 0;
}
