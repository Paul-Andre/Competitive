#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int q;

vector<int> orig[100001];

int low[100001];

int depth[200001];
bool visb[100001];

bool art[200001];

typedef pair<int, int> pii;

vector<pii> artAndDown;


vector<int> novel[200001];


int corresp[100001];

int comp[100001];

int top;

void biconnected(int i, int d) {
    visb[i] = true;
    comp[i] = top;
    //cerr << "visiting " << i << endl;

    depth[i] = d;
    low[i] = d;

    vector<int> childs;

    for(int j=0; j< orig[i].size(); j++) {
        int u = orig[i][j];
        if (visb[u]) {
            low[i] = min(low[i], depth[u]);
        }
        else {
            //cout << "u i " << u << " " << i <<endl;
            biconnected(u, d+1);
            low[i] = min(low[i], low[u]);
            childs.push_back(u);
            if ( low[u] >= depth[i] ) {
                if ( i!= top){ 
                    art[i]  = true;
                    corresp[i] = i;
                    artAndDown.push_back(pii(i, u));
                }
            }
        }
    }

    if (i == top && childs.size() > 1) {
        art[i] = true;
        corresp[i] = i;
        for(int j=0;j<childs.size(); j++) {
            int u  = childs[j];
            artAndDown.push_back(pii(i, u));
        }
    }
    else if (i == top) {
        artAndDown.push_back(pii(0, i));
    }

}



int vis2[100001];

int assigning;

void join(int u, int i) {
        novel[i].push_back(u);
        novel[u].push_back(i);
}


void travComp(int i) {

    vis2[i] = true;

    if ( !art[i] ) {
        corresp[i] = assigning;
    }
    else {
        join(assigning, i);
    }

    for(int j=0; j< orig[i].size(); j++) {
        int u = orig[i][j];
        if (!vis2[u]) {
            travComp(u);
        }
    }
}




void bic2(int i) {
    vis2[top] = true;

    travComp(i);

    vis2[top] = false;
}




bool visr[200001];

vector<int> goDown;

int parent[200001][19];

void root(int i, int d) {
    ////cerr << "While rooting visiting " << i << " at depth " << d << endl;
    visr[i] = true;
    depth[i] = d;
    for(int n = 0; (1<<n) <= goDown.size(); n++) {
        //if (i>=200001 || n >= 19) {
            //cerr << "i n " << i  << " " << n << endl;
            //cerr << "goDown size" << goDown.size()  << endl;
        //}

        int god = goDown[goDown.size() - (1<<n)];
        parent[i][n] = god;
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


int goUp(int u, int s) {
    //cerr << "Trying to go " << s << " steps from " << u << " of depth " << depth[u] << endl;
    for(int n=18; s!=0 && n>=0; n--) {
        if ((1<<n)<=s) {
            u = parent[u][n];
            s -= (1<<n);
        }
    }
    return u;
}



int lca(int u, int v) {
    ////cerr << "The lca of " << u << " and " << v;
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

    for(int n=18; n>=0; n--) {
        if ( parent[u][n] != parent[v][n]) {
            u = parent[u][n];
            v = parent[v][n];
            //cerr << " (do " << u << " " << v  << ") ";
        }
    }

    assert(parent[u][0] != 0);
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

    for(int i=0; i<n*2+1; i++) {
        novel[i] = vector<int>();
    }

    for(int i=0; i<artAndDown.size(); i++) {
        pii ad = artAndDown[i];
        top = ad.first;
        assigning = ad.second+n;
        if(ad.first!=0) {
            join(assigning, ad.first);
        }
        bic2(ad.second);
    }


    for(int i=1; i<=n; i++) {
        if (!visr[corresp[i]]) {
            root(corresp[i], 1);
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
        cerr << " with low: " << low[i] << endl;
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

        assert(uv == vw || uv == uw || vw == uw);
        if ( uv == vw ) {
            assert(depth[uv] <= depth[uw]);
        }
        else if (uv == uw) {
            assert(depth[uv] <= depth[vw]);
        }
        else {
            assert(depth[vw] <= depth[uv]);
        }


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
                break;
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
