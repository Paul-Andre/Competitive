#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//#define MOD 1000000007

vector<int> H[100001]; // special case
vector<int> I[100001]; // part of
vector<int> G[100001]; // part of

int Hp[100001][20];
int Ip[100001][20];
int Gp[100001][20];

int HLevel[100001];
int ILevel[100001];
int GLevel[100001];

int n;

vector<int> downing;

void parent(int i,int lvl, vector<int> (&G)[100001], int (&Gp)[100001][20], int (&level)[100001] ) {

    level[i] = lvl;

    downing.push_back(i);

    for(int j=0; downing.size()-1 >= (1<<j); j++) {
        Gp[i][j] = downing[downing.size() -1 - (1<<j)];
    }

    for(int j=0; j<G[i].size(); j++) {
        int u = G[i][j];
        parent(u, lvl+1, G, Gp, level);
    }

    downing.pop_back();
}

int goUp(int i, int lvl, int (&level)[100001], int (&p)[100001][20]) {
    int l = level[i];
    for(int j= 19; j>=0; j--) {
        if (l - (1<<j) >= lvl) {
            l = l - (1<<j);
            i = p[i][j];
        }
    }
    return  i;
}


int main() {
    cin>>n;

    for(int i=1; i<=n ;i++) {
        int p, t;
        cin>>p>>t;
        if( t == -1) {
            H[0].push_back(i);
            I[0].push_back(i);
            G[0].push_back(i);
        }
        if ( t == 0) {
            H[p].push_back(i);
            I[0].push_back(i);
            G[p].push_back(i);
        }
        if ( t == 1) {
            H[0].push_back(i);
            I[p].push_back(i);
            G[p].push_back(i);
        }
    }

    parent(0, 0, H, Hp, HLevel);
    parent(0, 0, I, Ip, ILevel);
    parent(0, 0, G, Gp, GLevel);

    int q;
    cin>>q;

    for(int i=0; i<q; i++) {
        int t, u, v;
        cin>>t>>u>>v;

        if (t == 1) {
            if (u != v && goUp(v, HLevel[u], HLevel, Hp) == u) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            int uu = u;
            int vv = v;
            if ( u != v ) {
                u = goUp(u, GLevel[v], GLevel, Gp);
                v = goUp(v, GLevel[u], GLevel, Gp);

                for(int j=19; j>=0; j--) {
                    if (Gp[u][j] != Gp[v][j]) {
                        u = Gp[u][j];
                        v = Gp[v][j];
                    }
                }
                assert(Gp[u][0] == Gp[v][0]);
                int p = u;
                if (u != v) {
                    p = Gp[u][0];
                }

                if (p != 0) {
                    if (GLevel[p] - GLevel[uu] == HLevel[p] - HLevel[uu] && GLevel[p] - GLevel[vv] == ILevel[p] - ILevel[vv]) {
                        cout << "YES\n";
                        continue;
                    }
                }
            }

            cout << "NO\n";

        }
    }

}







