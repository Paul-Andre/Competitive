#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int n, K;
vector<int> g[50];
long c[50][50];
bool vis[50];

void traverse(int i) {

    vector<long> cc(n,0);
    cc[0] = 1;

    for (int j=0; j<g[i].size(); j++) {
        int u = g[i][j];
        if (!vis[u]) {
            vis[u] = true;
            traverse(u);

            vector<long> ccp(n,0);
            for (int k = 0; k<n-1; k++) {
                ccp[k+1] = cc[k];
            }

            for (int k = 0; k<n; k++) {
                for (int kk = 0; kk<n; kk++) {
                    if (k+kk<n) {
                        ccp[k+kk] += c[u][k]*cc[kk];
                    }
                }
            }

            cc = ccp;
        }
    }

    for (int j=0; j<n; j++) {
        c[i][j] = cc[j];
    }
}


int main() {
    cin >> n >> K;
    
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vis[0] = true;
    traverse(0);

    long tot = 0;
    for (int j=0; j<=K; j++) {
        tot += c[0][j];
    }
    
    for (int i = 1; i<n; i++) {
        for (int j=0; j<=K-1; j++) {
            tot += c[i][j];
        }
    }
    


    for (int i = 0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout <<  c[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";


    cout << tot + 1 << '\n' ;

    return 0;
}

