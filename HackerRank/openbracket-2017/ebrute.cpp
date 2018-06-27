#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> G[200001];
int P[200001];

bool vis[200001];
vector<int> path;

bool dfs(int i, int needle) {
    vis[i] = true;
    path.push_back(P[i]);

    if (i == needle) return true;

    for(int j=0; j<G[i].size(); j++) {
        int u = G[i][j];
        if(!vis[u]) {
            if (dfs(u, needle)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

bool analPath() {
    vector<bool> seen(n/2 + 1, false);

    for(int i=0; i<path.size(); i++) {
        if (seen[path[i]]) {
            return false;
        }
        seen[path[i]] = true;
    }

    return true;
}


int main() {
    cin>>n;
    for(int i=0; i<n-1; i++) {
        int x;
        cin>>x;
        G[x].push_back(i+2);
        G[i+2].push_back(x);
    }

    for(int i=1; i<=n; i++) {
        cin>>P[i];
    }

    ll tot = 0;

    for(int i=1; i<=n ;i++) {
        for(int j=1; j<=n; j++) {

            for(int k=1; k<=n; k++) {
                vis[k] = false;
            }
            path.clear();

            dfs(i, j);
            tot += analPath();
        }
    }

    cout << tot <<endl;
}




