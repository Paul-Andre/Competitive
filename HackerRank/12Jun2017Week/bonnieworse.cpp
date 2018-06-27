#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int q;

vector<int> orig[100001];

int low[100001];

int depth[100001];
bool visb[100001];

bool art[100001];

int corresp[100001];

int comp[100001];

int top;

void biconnected(int i, int d) {
    visb[i] = true;
    comp[i] = top;
    //cout << "visiting " << i << endl;

    depth[i] = d;
    low[i] = d;

    int chct = 0;

    for(int j=0; j< orig[i].size(); j++) {
        int u = orig[i][j];
        if (visb[u]) {
            low[i] = min(low[i], depth[u]);
        }
        else {
            //cout << "u i " << u << " " << i <<endl;
            biconnected(u, d+1);
            low[i] = min(low[i], low[u]);
            chct ++;
            if ( low[u] >= depth[i] ) {
                if ( i!= top){ 
                    art[i]  = true;
                    corresp[i] = i;
                }
            }
        }
    }

    if (i == top && chct > 1) {
        art[i] = true;
        corresp[i] = i;
    }
}

typedef pair<int, int> pii;

set<pii> done;


vector<int> novel[100001];

int vis2[100001];


void bic2(int i) {
    vis2[i] = top;
    if ( art[i] ) {
        //cerr<<  " Connecting art " << i << " to " << top << endl;
        novel[i].push_back(top);
        novel[top].push_back(i);
    }
    else {
        corresp[i] = top;
        for(int j=0; j< orig[i].size(); j++) {
            int u = orig[i][j];
            if (vis2[u] != top) {
                bic2(u);
            }
        }
    }
}


int coco[100001];

void coconize(int i) {
    coco[i] = top;
    for(int j=0; j<novel[i].size(); j++) {
        int u = novel[i][j];
        if (!coco[u]) {
            coconize(u);
        }
    }
}


bool visr[100001];

vector<int> goDown;

int parent[100001][18];

void root(int i, int d) {
    ////cerr << "While rooting visiting " << i << " at depth " << d << endl;
    visr[i] = true;
    depth[i] = d;
    for(int n = 0; (1<<n) <= goDown.size(); n++) {
        parent[i][n] = goDown[goDown.size() - (1<<n)];
    }
    goDown.push_back(i);

    for(int j=0; j< novel[i].size(); j++) {
        int u = novel[i][j];
        if (!visr[u]) {
            root(u, d+1);
        }
    }
    goDown.pop_back();
}

int goUpDumb(int u, int s) {
    while(s>0) {
        u = parent[u][0];
        s --;
    }
    return u;
}

int goUp(int u, int s) {
    //cerr << "Trying to go " << s << " steps from " << u << " of depth " << depth[u] << endl;
    //
    int dumb = goUpDumb(u, s);

    for(int n=17; s!=0 && n>=0; n--) {
        if ((1<<n)<=s) {
            u = parent[u][n];
            s -= (1<<n);
        }
    }

    assert(dumb == u);
    return u;
}



int lca(int u, int v) {
    //cerr << "The lca of " << u << " and " << v;
    //cerr << " of depth " << depth[u] << ", " << depth[v];
    if (depth[u] < depth[v]) {
        int tmp = v;
        v = u;
        u = tmp;
    }

    u = goUp(u, depth[u]-depth[v]);

    //cerr << " ( " << u << " and " << v << " ) " << " is: " ;

    if (u == v) {
        //cerr << u <<endl;
        assert(u!=0);
        return u;
    }


    int dumbU = u;
    int dumbV = v;

    while(dumbU!= dumbV) {
        dumbU = parent[dumbU][0];
        dumbV = parent[dumbV][0];
    }

    for(int n=17; n>=0; n--) {
        if ( parent[u][n] != parent[v][n]) {
            u = parent[u][n];
            v = parent[v][n];
            //cerr << " (do " << u << " " << v  << ") ";
        }
    }

    assert(parent[u][0] != 0);
    assert(parent[u][0] == dumbU);
    //cerr << parent[u][0] <<endl;
    return parent[u][0];
}



int main() {
    cin >> n >> m;
    cin >> q;

    for(int a0 = 0; a0 < m; a0++){
        int u;
        int v;
        cin >> u >> v;
        orig[u].push_back(v);
        orig[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        if (!visb[i]) {
            top = i;
            biconnected(i, 1);
        }
    }

    for(int i=1; i<=n; i++) {
        if (!art[i] && !vis2[i]) {
            top = i;
            bic2(i);
        }
    }


    for (int i=1; i<=n; i++) {
        if (!coco[corresp[i]]) {
            top = i;
            coconize(corresp[i]);
        }
    }

    for(int i=1; i<=n; i++) {
        if (art[i]) {
            for (int j=0; j<orig[i].size(); j++) {
                int u = orig[i][j];
                if (art[u] && coco[u] != coco[i]) {
                    novel[u].push_back(i);
                    //novel[i].push_back(u);
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if (!visr[i]) {
            root(i, 1);
        }
    }

    
    
    /*
    for(int i=1; i<=n; i++) {
        cerr << i << " --> " << corresp[i]  << " art: " << art[i] << " depth: " << depth[corresp[i]] << endl;
        cerr <<" with friends: ";
        for (int j=0; j<novel[corresp[i]].size(); j++) {
            int u = novel[corresp[i]][j];
            cerr << u << " ";
        }
        cerr <<" with parents: ";
        for (int j=0; j<17; j++) {
            int u = parent[corresp[i]][j];
            cerr << u << " ";
        }
        cerr << endl;
    }
    */
    
    
    //assert(n<10);

    for(int a0 = 0; a0 < q; a0++){
        int u;
        int v;
        int w;
        cin >> u >> v >> w;

        if ( comp[u] != comp[w] || comp[v] != comp[w] || (u == v && u!=w) ) {
            cout << "NO\n";
            continue;
        }
        if (u==w || v==w) {
            cout << "YES\n";
            continue;
        }

        u = corresp[u];
        v = corresp[v];
        w = corresp[w];

        //cerr << "Corresponding nodes u v w" << u << " " << v  << " " << w << endl;

        //cerr << "Computing lca's\n";
        int uv = lca(u,v);
        int vw = lca(v,w);
        int uw = lca(u,w);

        //cerr << "Got: uv vw uw " << uv << " " << vw << " " << uw << endl;


        bool good  = true;

        int i = w;
        int ot = vw;
        if (vw == uv) {
            ot = uw;
        }

        //cerr << "branch 1's\n";
        while(depth[i] >= depth[ot]) {
            if (art[i] && i!=w ) {
                good = false;
            }
            i = parent[i][0];
        }

        if ( uw == vw) {
            i = uv;
            //cerr << "branch 2's\n";
            while(depth[i] >= depth[ot]) {
                if (art[i] && i != w) {
                    good = false;
                    break;
                }
                i = parent[i][0];
            }
        }

        if (good) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }

    return 0;
}
