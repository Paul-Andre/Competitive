#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007

bool vis[100001];
vector<int> GGG[100001];
vector<int> G[100001];
ll smaller[100001][11];
ll eqal[100001][11];
ll bigger[100001][11];


ll scratch[100001][11];

ll m, k;
int n, x;

void root(int i) {
    vis[i] = true;
    for(int j=0; j<GGG[i].size(); j++) {
        int u = GGG[i][j];
        if (!vis[u]) {
            G[i].push_back(u);
            root(u);
        }
    }
}


void trav(int i) {
    for(int j=0; j<G[i].size(); j++) {
        int u = G[i][j];
        trav(u);
    }


    for(int j=1; j<G[i].size()+1; j++) {
        int u = G[i][j-1];
        for(int k=0; k<=10; k++) {
            scratch[j][k] = 0;
            for(int kk=0; kk<=k; kk++) {
                scratch[j][k] += (scratch[j-1][k-kk] * smaller[u][kk]) % MOD;
                scratch[j][k] %= MOD;
            }
        }
    }

    for(int j=1; j<=10; j++) {
        eqal[i][j] = scratch[G[i].size()][j-1];
    }

    for(int j=1; j<G[i].size()+1; j++) {
        int u = G[i][j-1];
        for(int k=0; k<=10; k++) {
            scratch[j][k] = 0;
            for(int kk=0; kk<=k; kk++) {
                scratch[j][k] += (scratch[j-1][k-kk] * ((smaller[u][kk] + bigger[u][kk]) % MOD)) %MOD;
                scratch[j][k] %= MOD;
            }
        }
    }

    for(int j=0; j<=10; j++) {
        bigger[i][j] = (scratch[G[i].size()][j] * (m - k)) % MOD;
    }

    for(int j=1; j<G[i].size()+1; j++) {
        int u = G[i][j-1];
        for(int k=0; k<=10; k++) {
            scratch[j][k] = 0;
            for(int kk=0; kk<=k; kk++) {
                scratch[j][k] += (scratch[j-1][k-kk] * ((smaller[u][kk] + bigger[u][kk] + eqal[u][kk])%MOD))%MOD;
                scratch[j][k] %= MOD;
            }
        }
    }

    for(int j=0; j<=10; j++) {
        smaller[i][j] = (scratch[G[i].size()][j] * (k - 1)) % MOD;
    }

}

int main() {
    cin>>n>>m;

    for(int i=0; i<n-1 ;i++) {
        int x,y;
        cin>>x>>y;
        GGG[x].push_back(y);
        GGG[y].push_back(x);
    }
    cin >>k>>x;

    scratch[0][0] = 1;


    root(1);
    trav(1);


    ll tot = 0;
    for(int i=0; i<=x; i++) {
        tot += smaller[1][i];
        tot += eqal[1][i];
        tot += bigger[1][i];
        tot %= MOD;
        //cerr << i << " " << smaller[1][i] << " " << eqal[1][i] << " " << bigger[1][i] << endl;
    }

    cout << tot <<endl;

}







