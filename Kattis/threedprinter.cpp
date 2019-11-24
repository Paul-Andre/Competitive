#include <bits/stdc++.h>
using namespace std;

template<typename T>
void
hash_combine(std::size_t &seed, T const &key) {
  std::hash<T> hasher;
  seed ^= hasher(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct Pt {
  double x;
  double y;
  double z;
  Pt(double x,double y,double z):x(x),y(y),z(z) { }
};

bool operator==(Pt a, Pt b) {
  return a.x == b.x && a.y == b.y && a.z == b.z;
}

double signedVolume(Pt a, Pt b, Pt c) {
  return 0.
    + a.x * b.y * c.z
    + a.y * b.z * c.x
    + a.z * b.x * c.y
    - a.z * b.y * c.x
    - a.x * b.z * c.y
    - a.y * b.x * c.z
    ;
}

namespace std {
  template<typename T1, typename T2>
  struct hash<std::pair<T1, T2>> {
    std::size_t operator()(std::pair<T1, T2> const &p) const {
      std::size_t seed(0);
      ::hash_combine(seed, p.first);
      ::hash_combine(seed, p.second);
      return seed;
    }
  };
  template<>
  struct hash<Pt> {
    std::size_t operator()(Pt const &p) const {
      std::size_t seed(0);
      ::hash_combine(seed, p.x);
      ::hash_combine(seed, p.y);
      ::hash_combine(seed, p.z);
      return seed;
    }
  };
}

typedef pair<Pt, Pt> Segment;

unordered_map<Segment, vector<pair<int, bool> > > edges;

struct Face {
  bool vis = false;
  bool reversed = false;
  vector<Pt> vertices;
};

vector<Face> faces;

int N;
int F;

void vis(int i, bool reverse) {
  Face &face = faces[i];
  if (face.vis) {
    assert(face.reversed == reverse);
    return;
  }
  face.vis = true;
  face.reversed = reverse;
  for (int j=0; j<(int)face.vertices.size(); j++) {
    Pt a = face.vertices[j];
    Pt b = face.vertices[(j+1)%face.vertices.size()];
    if (reverse) {
      Pt tmp = a;
      a = b;
      b = tmp;
    }
    if (edges.count(Segment(a,b))) {
      for (int k=0; k<2; k++) {
        int ur = edges[Segment(a,b)][k].second;
        int u = edges[Segment(a,b)][k].first;
        if (u != i) {
          vis(u, !ur);
        }
      }
    } else if (edges.count(Segment(b, a))) {
      for (int k=0; k<2; k++) {
        int ur = edges[Segment(b,a)][k].second;
        int u = edges[Segment(b,a)][k].first;
        if (u != i) {
          vis(u, ur);
        }
      }
    } else {
      assert("Whoops" && false);
    }
  }
}

double computeFace(int i) {
  Face &face = faces[i];
  Pt summet = face.vertices[0];
  double tot = 0;
  for (int j=1; j<=(int)face.vertices.size()-2; j++) {
    Pt a = face.vertices[j];
    Pt b = face.vertices[j+1];
    if (face.reversed) {
      Pt tmp = a;
      a = b;
      b = tmp;
    }

    double asdf = signedVolume(summet, a, b);
    //cerr << "asdf " << asdf <<endl;
    tot += asdf;
  }
  return tot;
}

double doPolyhedron() {
  cin >> F;
  edges.clear();
  faces.clear();

  double tot = 0;
  for (int fff=0; fff < F; fff++) {
    int v;
    cin >> v;
    Face f;
    for (int i=0; i<v; i++) {
      double x,y,z;
      cin >>x>>y>>z;
      f.vertices.push_back(Pt(x,y,z));
    }
    faces.push_back(f);
    for (int i=0; i<v; i++) {
      Pt a = f.vertices[i];
      Pt b = f.vertices[(i+1)%v];
      if (edges.count(Segment(a,b))) {
        edges[Segment(a,b)].push_back(make_pair( faces.size() - 1, false));
      } else if (edges.count(Segment(b, a))) {
        edges[Segment(b, a)].push_back(make_pair( faces.size() - 1, true));
      } else {
        edges[Segment(a,b)].push_back(make_pair( faces.size() - 1, false));
      }
    }
  }
  for (auto &w : edges) {
    assert(w.second.size() == 2);
  }
  vis(0, false);
  for (int i=0; i<F; i++) {
    assert(faces[i].vis);
    //cerr << faces[i].reversed  << endl;
  }
  for (int i=0; i<F; i++) {
    double heh = computeFace(i);
    //cerr << "heh " << heh <<endl;
    tot += heh;
  }

  return fabs(tot);
}

int main() {
  cin >> N;
  double tot = 0;
  for (int i = 0; i<N; i++) {
    double h =  doPolyhedron();
    //cerr << h << endl;
    tot += h;
  }

  std::cout << std::fixed << std::setprecision(2) << (tot/6) << endl;
}
