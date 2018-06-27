#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int q;


struct Edge{
    int u;
    int v;
    bool filled;
};

vector<int> orig[100001];

vector<int> out[200001];
vector<int> in[200001];

vector<Edge> edges;

void connect(int u, int v) {
    Edge e;
    e.u = u;
    e.v = v;
    e.filled = false;
    edges.push_back(e);
    out[u].push_back(edges.size()-1);
    in[v].push_back(edges.size()-1);
}

int comp[100001];

int top;

void component(int i) {
    comp[i] = top;
    for(int j=0; j<orig[i].size(); j++) {
        int u = orig[i][j];
        if (!comp[u]) {
            component(u);
        }
    }
}

//typedef pair<int, int> pii;


bool vis[200001];
vector<int> edgesCrossed;

bool goThrough(int i, int goal) {
    //cerr << "Going through " << i << " (" << (i+1)/2 << ")" << endl;
    vis[i] = true;
    if (i == goal) {
        return true;
    }
    else {
        for (int j=0; j<out[i].size(); j++) {
            int e = out[i][j];
            Edge ee = edges[e];
            if (!ee.filled && !vis[ee.v] ) {
                edgesCrossed.push_back(e);
                if (goThrough(ee.v, goal)) {
                    return true;
                }
                else {
                    edgesCrossed.pop_back();
                }
            }
        }
        for (int j=0; j<in[i].size(); j++) {
            int e = in[i][j];
            Edge ee = edges[e];
            if (ee.filled && !vis[ee.u] ) {
                edgesCrossed.push_back(e);
                if (goThrough(ee.u, goal)) {
                    return true;
                }
                else {
                    edgesCrossed.pop_back();
                }
            }
        }
    }
    return false;
}



int main() {
    cin >> n >> m;
    cin >> q;

    for(int i=1; i<=n; i++) {
        connect(i*2-1, i*2);
    }


    for(int a0 = 0; a0 < m; a0++){
        int u;
        int v;
        cin >> u >> v;
        orig[u].push_back(v);
        orig[v].push_back(u);

        int ui = u*2-1;
        int uo = u*2;

        int vi = v*2-1;
        int vo = v*2;

        connect(uo, vi);
        connect(vo, ui);
    }

    for(int i=1; i<=n; i++) {
        if (!comp[i]) {
            top = i;
            component(i);
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

        u = u*2-1;
        v = v*2-1;
        w = w*2 -1;

        for(int i=0; i<edges.size(); i++) {
            edges[i].filled = false;
        }

        edgesCrossed = vector<int>();

        for(int i=1; i<=n ; i++) {
            vis[i*2-1] = false;
            vis[i*2] = false;
        }

        //cerr << "Succ: " << 
        goThrough(u, w); // << endl;

        for(int i=0; i<edgesCrossed.size(); i++) {
            edges[edgesCrossed[i]].filled = !edges[edgesCrossed[i]].filled;
        }

        edgesCrossed = vector<int>();

        for(int i=1; i<=n ; i++) {
            vis[i*2-1] = false;
            vis[i*2] = false;
        }

        bool good  = goThrough(v, w);


        if (good) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }

    return 0;
}
