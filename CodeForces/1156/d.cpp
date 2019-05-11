#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) 0
#endif

int n;
vector<int> G0[212345];
vector<int> G1[212345];

bool vis0[212345];
bool vis1[212345];

ll ts0[212345];
ll ts1[212345];

ll tot;

typedef  vector<int> GGG[212345];
typedef  bool VIS[212345];
typedef  ll TS[212345];

ll cnt = 0;

void vv(int i, GGG &G, VIS &vis, TS &ts) {
  if (vis[i]) return;
  vis[i] = true;
  cnt += 1;
  for (int j=0; j<G[i].size(); j++) {
    int u = G[i][j];
    vv(u, G, vis, ts);
  }
  vis[i] = false;
}
void prop(int i, GGG &G, VIS &vis, TS &ts) {
  if (vis[i]) return;
  vis[i] = true;
  ts[i] = cnt;
  for (int j=0; j<G[i].size(); j++) {
    int u = G[i][j];
    prop(u, G, vis, ts);
  }
  vis[i] = false;
}

ll visit(int i, GGG &G, VIS &vis, TS &ts) {
  if (ts[i] != 0) return ts[i];
  cnt = 0;
  vv(i, G, vis, ts);
  prop(i, G, vis, ts);
  tot += ts[i] * (ts[i] - 1);
  return ts[i];
}


int main() {
  cin >> n;
  for (int i=0 ;i<n-1; i++) {
    int a, b;
    bool c;
    cin >> a>>b>>c;
    if (!c) {
      G0[a].push_back(b);
      G0[b].push_back(a);
    } else {
      G1[a].push_back(b);
      G1[b].push_back(a);
    }
  }
  for (int i=1; i<=n; i++) {
    ll a = (visit(i, G0, vis0, ts0) );
    ll b = (visit(i, G1, vis1, ts1) );
    LOG(i);
    LOG(a);
    LOG(b);
    tot += (a-1)*(b-1);
  }
  cout << tot <<endl;
}
