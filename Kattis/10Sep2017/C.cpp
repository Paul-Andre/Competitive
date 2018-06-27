#include <bits/stdc++.h>
using namespace std;


int m,n;

vector<int> G[16];

bool vis[16];

int root;

int cnt(int i) {
    vis[i] = true;

    int tot = 0;

    for(int j=0; j<G[i].size(); j++) {
        int u  = G[i][j];
        if (u == root) {
            tot ++;
        }
        if (!vis[u]) {
            tot += cnt(u);
        }
    }

    vis[i] = false;
    return tot;
}


int main() {
    cin>>m>>n;

    for(int i=0; i<n; i++) {
        int s,t;
        cin>>s>>t;
        G[s].push_back(t);
    }

    int tot = 0;

    for(int i=0; i<=m; i++) {
        root = i;
        tot += cnt(root);
        vis[i] = true;
    }

    cout << tot <<endl;

}



    


