#include <bits/stdc++.h>
using namespace std;

#define N 100001

vector<int> unrooted[N];
vector<int> G[N];

int n;

bool vis[N];

void root(int i) {
    vis[i] = true;
    for(int j=0; j<unrooted[i].size(); j++) {
        int u = unrooted[i][j];
        if (!vis[u]) {
            G[i].push_back(u);
            root(u);
        }
    }
}


double expect(int i) {
    double tot = 0;
    if (G[i].size() == 0) return 0;
    for(int j=0; j<G[i].size(); j++) {
        int u = G[i][j];
        tot += 1 +expect(u);
    }
    return tot / G[i].size();
}


int main() {
    cin>>n;
    for(int i=0; i<n-1; i++) {
        int x,y;
        cin>>x>>y;
        unrooted[x].push_back(y);
        unrooted[y].push_back(x);
    }

    root(1);

    cout.precision(20);
    cout << expect(1) <<endl;
}


