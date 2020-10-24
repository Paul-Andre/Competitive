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


vector<int> dfsDown[200001];
vector<int> artDown[200001];

vector<int> novel[300001];


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
                    artDown[i].push_back(u);
                }
            }
        }
    }

    dfsDown[i] = childs;

    /*
    if (i == top && childs.size() > 1) {
      art[i] = true;
    }
    */
    if (i==top) {
      art[i] = true;
      artDown[i] = childs;
    }

}

void join(int u, int i) {
  if (u != 0 && i != 0) {
    novel[i].push_back(u);
    novel[u].push_back(i);
  }
}

void makeNovel(int i, int attachment) {
  visb[i] = true;
  join(i, attachment);
  if (art[i]) {
    for (int j=0; j<artDown[i].size(); j++) {
      int u = artDown[i][j];
      int newAtt = u+n;
      join(i, newAtt);
      makeNovel(u, newAtt);
    }
  }
  for (int j=0; j<dfsDown[i].size(); j++) {
    int u = dfsDown[i][j];
    if (visb[u]) continue;
    makeNovel(u, attachment);
  }
}









bool visr[200001];

vector<int> goDown;

int parent[200001][19];

void root(int i, int d) {
    ////cerr << "While rooting visiting " << i << " at depth " << d << endl;
    visr[i] = true; depth[i] = d; for(int n = 0; (1<<n) <= goDown.size(); n++) { //if (i>=200001 || n >= 19) {
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


    for(int i=0; i<=n; i++) {
      visb[i] = 0;
    }

    for(int i=0; i<=n; i++) {
        if (!visb[i]) {
            makeNovel(i, 0);
        }
    }

    cerr << "comp\n";
    for (int i=0; i<22; i++) {
      cerr << comp[i] << " " ;
    }cerr <<endl;

    cerr << "novel\n";
    for (int i=0; i<22; i++) {
      cerr << i << ":  ";
      for (int j=0; j<novel[i].size(); j++) {
        cerr << novel[i][j] << " ";
      }
      cerr << endl;
    }
    cerr << "/novel\n";


    for(int i=1; i<=n; i++) {
        if (!visr[i]) {
            root(i, 1);
        }
    }
    
    


    
    
    
    //assert(n<10);

    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int u;
        int v;
        cin >> u >> v;

        if (comp[u] != comp[v]) {
          cout << "2\n";
          continue;
        }

        // cerr << "Corresponding nodes u v " << u << " " << v  <<  endl;

        //cerr << "Computing lca's\n";
        int uv = lca(u,v);
        cerr << "lca uv " << uv << endl;

        int dist = depth[u] - depth[uv] + depth[v] - depth[uv];

        cout << (dist/2 + 1) << endl;


    }

    return 0;
}

