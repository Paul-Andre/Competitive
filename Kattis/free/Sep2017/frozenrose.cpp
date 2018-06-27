#include <bits/stdc++.h>
using namespace std;


vector<int> W[1001];
vector<int> G[1001];
bool vis[1001];


typedef long long ll;

ll trav(int i) {
    vis[i] = true;
    ll tot = 0;
    for(int j=0; j<G[i].size(); j++) {
        int u = G[i][j];
        ll w = W[i][j];
        if (!vis[u]) {
            ll r = trav(u);
            if (r != 0) tot += min(r, w);
            else tot += w;
        }
        
    }
    return tot;
}

int n, c;
int main() {

    while(cin>>n>>c) {
        for(int i=0; i<=1000; i++) {
            vis[i] = false;
            G[i].clear();
            W[i].clear();
        }

        for(int i=0; i<n-1; i++) {
            int u,v,w;
            cin>>u>>v>>w;

            G[u].push_back(v);
            G[v].push_back(u);
            W[u].push_back(w);
            W[v].push_back(w);
        }

        cout << trav(c) <<endl;
    }
}
