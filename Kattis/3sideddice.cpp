#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Frac {
  ll num;
  ll denom;
  Frac(ll a, ll b) {
    assert(b!=0);
    if (b < 0) {
      a *= -1;
      b *= -1;
    }
    ll g = __gcd(a, b);
    a/=g;
    b/=g;
    num = a;
    denom = b;
  }
  Frac() {
    num = 0;
    denom = 1;
  }
  Frac(const Frac &f) {
    num = f.num;
    denom = f.denom;
  }
  Frac(ll v) {
    num = v;
    denom = 1;
  }
};

ostream &operator<<(ostream &os, Frac &f) {
  return (os << f.num << "/" << f.denom);
}
Frac operator+(Frac a, Frac b) {
  return Frac(a.num*b.denom + b.num*a.denom, a.denom*b.denom);
}

Frac operator*(Frac a, Frac b) {
  return Frac(a.num*b.num, a.denom*b.denom);
}

Frac operator/(Frac a, Frac b) {
  return Frac(a.num*b.denom, a.denom*b.num);
}

Frac operator*(ll a, Frac b) {
  return Frac(a*b.num, b.denom);
}

Frac operator-(Frac b) {
  return Frac(-b.num, b.denom);
}

Frac operator-(Frac a, Frac b) {
  return a + (-b);
}

bool operator==(Frac a, Frac b) {
  return a.num*b.denom == b.num*a.denom;
}
bool operator!=(Frac a, Frac b) {
  return a.num*b.denom != b.num*a.denom;
}
bool operator<(Frac a, Frac b) {
  return a.num*b.denom < b.num*a.denom;
}
bool operator>(Frac a, Frac b) {
  return a.num*b.denom > b.num*a.denom;
}
bool operator<=(Frac a, Frac b) {
  return a.num*b.denom <= b.num*a.denom;
}
bool operator>=(Frac a, Frac b) {
  return a.num*b.denom >= b.num*a.denom;
}

typedef vector<vector<Frac>> Matrix;

template<typename T>
vector<T> operator*(T t, vector<T> &v) {
  auto ret = v;
  for (int i=0; i<(int)ret.size(); i++) {
    ret[i] = t * ret[i];
  }
  return ret;
}

template<typename T>
vector<T> operator+(vector<T> &a, vector<T> &b) {
  auto ret = a;
  for (int i=0; i<(int)ret.size(); i++) {
    ret[i] = ret[i] + b[i];
  }
  return ret;
}

template<typename T>
vector<T> operator-(vector<T> &a, vector<T> &b) {
  vector<T> bb = T(-1)*b;
  return a + bb;
}

void printMatrix(Matrix &m) {
    for (int i=0; i<m.size(); i++) {
      for (int j=0; j<m[i].size(); j++) {
        cerr << m[i][j] << " ";
      }
      cerr << endl;
    }
      cerr << endl;


}

void printVector(vector<Frac> &v) {
  for (int j=0; j<v.size(); j++) {
    cerr << v[j] << " ";
  }
  cerr << endl;
}
  

void gaussianEliminate (Matrix &M) {
  int m = M.size();
  int n= M[0].size();
  int j=0;
  vector<bool> vis(m, false);
  while(true) {
    for (int i=0; i<m; i++) {
      if (M[i][j] != 0 && !vis[i]) {
        vis[i] = true;
        cerr << "i j " << i << " " << j <<endl;
        M[i] = (Frac(1)/M[i][j]) * M[i];

        for (int k=0; k<m; k++) {
          if (k!=i) {
            auto asdf = (M[k][j] * M[i]);
            asdf = Frac(-1) * asdf;
            M[k] = M[k] + asdf;
          }
        }

        break;
      }
    }
    j++;
    if (j<n) continue;
    else { return; }
  }
}



vector<Frac> get(int n) {
  vector<Frac> ret(n);
  for(int i=0; i<n; i++) {
    ll k; cin >> k;
    ret[i] = Frac(k, 10000);
  }
  return ret;
}


int main() {
  while(true) {
    auto a = get(3);
    if (a[0] == 0 && a[1] == 0 && a[2] == 0) return 0;
    auto b = get(3);
    auto c = get(3);
    auto r = get(3);
    Matrix m = {
      {a[0], b[0], c[0], r[0]},
      {a[1], b[1], c[1], r[1]},
      {a[2], b[2], c[2], r[2]},
      {1, 1, 1, 1}
    };
    gaussianEliminate(m);
    for (int i=0; i<m.size(); i++) {
      for (int j=0; j<m[i].size(); j++) {
        cerr << m[i][j] << " ";
      }
      cerr << endl;
    }
      cerr << endl;
      cerr << "==============================================================================\n";
  }
}

