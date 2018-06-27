#include <bits/stdc++.h>
using namespace std;

int n;
int weights[300000];
vector<int> treeUndir[300000];

bool visDir[300000];
vector<int> tree[300000];

void traverseDir(int i) {
    for (int j=0; j<treeUndir[i].size(); j++) {
        int u = treeUndir[i][j];
        if (!visDir[u]) {
            tree[i].push_back(u);
            visDir[u] = true;
            traverseDir(u);
        }
    }
}

long downMax[300000];
long downMin[300000];

long downMaxCon[300000];
long downMinCon[300000];

void traverseDown(int i) {
    for (int j=0; j<tree[i].size(); j++) {
        int u = tree[i][j];
        traverseDown(u);
    }
    long maxC = 0;
    long minC = 0;
    long maxSum = weights[i];
    long minSum = weights[i];
    for (int j=0; j<tree[i].size(); j++) {
        int u = tree[i][j];
        maxC = max(maxC, downMax[u]);
        minC = min(minC, downMin[u]);
        maxSum += downMaxCon[u];
        minSum += downMinCon[u];
    }
    downMaxCon[i] = max(0L, maxSum);
    downMinCon[i] = min(0L, minSum);
    downMax[i] = max(maxC, downMaxCon[i]);
    downMin[i] = min(minC, downMinCon[i]);
}

long upMax[300000];
long upMin[300000];

long upMaxCon[300000];
long upMinCon[300000];

void traverseUp(int i) {
    for (int j=0; j<tree[i].size(); j++) {
        int u = tree[i][j];

        upMax[u] = upMax[i];
        upMin[u] = upMin[i];

        upMaxCon[u] = weights[i] + upMaxCon[i];
        upMinCon[u] = weights[i] + upMinCon[i];
    }
    for (int ii=0; ii<=1; ii++) {
        long maxC = 0;
        long minC = 0;
        long maxSum = 0;
        long minSum = 0;
        for (int jj=0; jj<tree[i].size(); jj++) {
            int j;
            if (ii) {
                j= jj;
            }
            else {
                j= tree[i].size()-1-jj;
            }
            int u = tree[i][j];
            upMax[u] = max(upMax[u], maxC);
            upMin[u] = min(upMin[u], minC);

            upMaxCon[u] += maxSum;
            upMinCon[u] += minSum;

            ////cout << upMinCon[u] << '\n';

            maxC = max(maxC, downMax[u]);
            minC = min(minC, downMin[u]);
            maxSum += downMaxCon[u];
            minSum += downMinCon[u];
            //cout << "i u maxSum minSum  " << i << " " << u << " " << maxSum << " " << minSum << '\n';
        }
    }

    for (int j=0; j<tree[i].size(); j++) {
        int u = tree[i][j];


        upMaxCon[u] = max(upMaxCon[u], 0L);
        upMinCon[u] = min(upMinCon[u], 0L);

        upMax[u] = max(upMax[u], upMaxCon[u]);
        upMin[u] = min(upMin[u], upMinCon[u]);

        traverseUp(u);
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> weights[i];
    }
    
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        treeUndir[u].push_back(v);
        treeUndir[v].push_back(u);
    }

    visDir[0] = true;
    traverseDir(0);

    traverseDown(0);

    traverseUp(0);

    long maxxx = 0;
    for (int i=1; i<n; i++) {
        //cout << "i upMax upMin downMax downMin " << i << "  " <<  upMax[i] << " " << upMin[i] << "  " << downMax[i] << " " << downMin[i] << '\n';
        maxxx = max(maxxx, max(upMax[i]*downMax[i], upMin[i]*downMin[i]));
    }

    cout << maxxx << '\n';
}
