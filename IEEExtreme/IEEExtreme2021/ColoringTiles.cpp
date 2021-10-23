#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename K> using hset = gp_hash_table<K, null_type>;
template <typename K, typename V> using hmap = gp_hash_table<K, V>;

typedef long long ll;

int n,m,c;
vector<string> a;

hmap<string, ll> prevMap;
hmap<string, ll> nextMap;

#define MOD 1000000007

void enumerateAll(const string &t, string &have) {
  //cerr << t << " " << have <<endl;
  if (have.size() == t.size()) {
    nextMap[have]++;
    return;
  }
  if (t[have.size()] == '#') {
    have.push_back('#');
    enumerateAll(t, have);
    have.pop_back();
    return;
  }
  for (int k=0; k<c; k++) {
    char cc = 'a' + k;
    have.push_back(cc);
    enumerateAll(t, have);
    have.pop_back();
  }
}

void enumerateConstrained(const string &t, const string &s, string &have, ll reward) {
  if (have.size() == t.size()) {
    nextMap[have]+=reward;
    nextMap[have] %= MOD;
    return;
  }
  if (t[have.size()] == '#') {
    have.push_back('#');
    enumerateConstrained(t,s, have, reward);
    have.pop_back();
    return;
  }
  int i = have.size();
  for (int k=0; k<c; k++) {
    char cc = 'a' + k;
    if (i>0) {
      int cnt = 1;
      cnt += s[i-1] == cc;
      cnt += s[i] == cc;
      cnt += have[i-1] == cc;
      if (cnt >= 3) continue;
    }
    if (i<t.size()-1) {
      int cnt = 1;
      cnt += s[i+1] == cc;
      cnt += s[i] == cc;
      if (cnt >= 3) continue;
    }
    have.push_back(cc);
    enumerateConstrained(t,s, have, reward);
    have.pop_back();
  }
}

ostream& operator<<(ostream& os, const hmap<string, ll> &m) {
  os << "{";
  for(const auto& [key, value]: m) {
    os << key << ":" <<value << " ";
  }
  os << "}";
  return os;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    cin>>n>>m>>c;
    a.clear();
    nextMap.clear();
    prevMap.clear();
    for (int i=0; i<n; i++) {
      string s;
      cin>>s;
      assert(s.size() == m);
      a.push_back(s);
    }
    if (! (n > m) ) {
      auto cop = a;
      a.clear();
      for (int j=0; j<m; j++) {
        a.emplace_back();
        for (int i=0; i<n; i++) {
          a[j].push_back(cop[i][j]);
        }
      }
      swap(n,m);
    }
    cerr <<n<<" " << m <<endl;
    string temp = "";
    enumerateAll(a[0], temp);
    assert(temp == "");
    /*
    cerr << nextMap;
    cerr << nextMap.size() <<endl;
    */

    for(int i=1; i<n; i++) {
      prevMap = move(nextMap);
      nextMap.clear();
      for(const auto& [key, value]: prevMap) {
        if (value != 0) {
          assert(temp == "");
          enumerateConstrained(a[i], key, temp, value);
          assert(temp == "");
          /*
          cerr << key << "  ";
        cerr << nextMap;
        cerr << nextMap.size() <<endl;
        */
        }
      }
      /*
    cerr << nextMap;
    cerr << nextMap.size() <<endl;
    */

    }
    ll tot = 0;
    for(const auto& [_, value]: nextMap) {
      tot += value;
      tot%=MOD;
    }

    cout <<tot <<endl;
  }
}






