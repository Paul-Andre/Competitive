#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int h, w;

template <class T>
inline size_t hash_combine(std::size_t seed, const T& v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    return seed;
}
namespace std {
  template <typename a, typename b>
  struct hash<pair<a,b>>
  {
    std::size_t operator()(const pair<a,b>& p) const
    {
      using std::size_t;
      using std::hash;
      using std::string;
      return hash_combine(hash<a>()(p.first), p.second);
    }
  };
}

struct State {
  int32_t current, hi;
  uint64_t lo;
};
namespace std {
  template <>
  struct hash<State>
  {
    std::size_t operator()(const State& p) const
    {
      using std::size_t;
      using std::hash;
      using std::string;
      return hash_combine(hash_combine(hash<ull>()(p.hi), p.lo), p.current);
    }
  };
}
bool operator==(State a, State b) {
  return a.hi == b.hi && a.lo == b.lo && a.current == b.current;
}

int N;
unordered_set<State> vis;

unordered_map<string, int> artistToInt;
int artistToIntI = 0;

vector<int> G[120];
int A[120]; // the artist of the song

State newState(const State &old, int v) {
  State ret = old;
  ret.current = v;
  int u = A[v];
  if (u < 64) {
    ret.lo |= (1ull << u);
  } else {
    ret.hi |= (1ull << (u-64));
  }
  return ret;
}

bool artistWasVisited(const State &s, int v) {
  int u = A[v];
  if (u < 64) {
    return !! (s.lo & (1ull << u));
  } else {
    return !! (s.hi & (1ull << (u-64)));
  }
}

vector<int> stach;

void printState(const State &state) {
  cerr << "Visiting " << state.current << " ";
  for (int i=0; i<64; i++) {
    cerr << !!(state.lo & (1ull << i));
  }
  for (int i=0; i<64; i++) {
    cerr << !!(state.hi & (1ull << i));
  }
  cerr <<endl;
}



bool visit(State state, int remaining) {
  if (vis.count(state) != 0) return false;
  vis.insert(state);
  stach.push_back(state.current);
  //printState(state);
  if (remaining == 1) return true;
  vector<int> vv = G[state.current];
  random_shuffle(vv.begin(), vv.end());
  for (int j=0; j<vv.size(); j++) {
    int u = vv[j];
    if (!artistWasVisited(state, u)) {
      if (visit(newState(state, u), remaining-1)) {
        return true;
      }
    }
  }
  stach.pop_back();
  return false;
}

int main() {

  cin >> N;
  for (int i=0; i<N; i++) {
    string artist;
    cin >> artist;
    if (artistToInt.count(artist) == 0) {
      artistToInt[artist] = artistToIntI;
      artistToIntI ++;
    }
    int ai = artistToInt[artist];
    A[i] = ai;
    int t;
    cin >> t;
    for (int j=0; j<t; j++) {
      int u;
      cin >> u;
      u --;
      G[i].push_back(u);
    }
  }
  State state = {0,0,0};
  for (int i=0; i<N; i++) {
    if (visit(newState(state, i), 9)) {
      assert(stach.size() == 9);
      for (int i=0; i<9; i++) {
        cout << stach[i]+1 << " ";
      }
      cout << endl;
      return 0;
    }
  }
  cout << "fail" <<endl;
}
