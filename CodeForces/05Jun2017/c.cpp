#include <bits/stdc++.h>
using namespace std;

int n, x;

vector<int> undir[200001];
vector<int> down[200001];
vector<int> up[200001];
bool orientVis[200001];

void orient(int i) {
    if (!orientVis[i]) {
        orientVis[i] = true;
        for (int j=0; j<undir[i].size(); j++) {
            int u = undir[i][j];
            if (!orientVis[u]) {
                down[i].push_back(u);
                up[u].push_back(i);
                orient(u);
            }
        }
    }
}


int dist(int i) {
    int m = 0;
    for (int j=0; j<down[i].size(); j++) {
        int u = down[i][j];
        m = max(m, dist(u));
    }
    return m + 1;
}

int main() {
    cin >> n >> x;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        undir[u].push_back(v);
        undir[v].push_back(u);
    }

    orient(1);

    int u = x;
    int v = x;
    int count = 0;
    int countU = 0;
    while(true) {
        u = up[u][0];
        countU ++;
        if (u == 1) break;
        u = up[u][0];
        countU ++;
        if (u == 1) break;

        v = up[v][0];
        count ++;
    }

    cout << (countU-count + dist(v) -1)*2 << endl;
}
