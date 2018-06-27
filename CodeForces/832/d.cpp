#include <bits/stdc++.h>
using namespace std;

vector<int> unroot[100001];
vector<int> G[100001];
int parent[100001][21];
int level[100001];

vector<int> path;

int n,q;

bool vis[100001];
void root(int i, int lvl) {
    path.push_back(i);
    level[i] = lvl;
    vis[i]=true;
    for(int j=0; (int)path.size()-1-(1<<j) >=0; j++){
        parent[i][j] = path[(int)path.size() - 1 - (1<<j)];
    }
    for(int j=0;j<unroot[i].size(); j++) {
        int u = unroot[i][j];
        if (!vis[u]) {
            G[i].push_back(u);
            root(u, lvl+1);
        }
    }
    path.pop_back();
}

int goUp(int a, int b) {
    for(int i=20; i>=0; i--) {
        if ((1<<i) <= b) {
            b -= (1<<i);
            a = parent[a][i];
        }
    }
    return a;
}

int lca(int a, int b) {
    cerr << "lca of " << a << " " << b << " is ";
    if (level[a] > level[b]) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    b = goUp(b, (level[b] - level[a]));

    if (a != b) {
    for(int i=20; i>=0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    assert(parent[a][0]==parent[b][0]);
    cerr << parent[a][0] <<endl;
    return parent[a][0];
    }
    else {
    cerr << a << endl;
    return a;
    }

}


int get(int a,int b, int c) {
    int ab = lca(a,b);
    int bc = lca(c,b);
    int ac = lca(a,c);

    if(ab == ac) {
        return (level[a] - level[ab] + 1 + level[bc] - level[ab]);
    }
    else if (ab == bc) {
        return level[a] - level[ac] + 1;
    }
    else {
        return level[a] - level[ab] + 1;
    }
}


int main(){
    cin>>n>>q;

    for(int i=0; i<n-1; i++) {
        int x,y;
        cin>>x;
        y = i + 2;
        unroot[x].push_back(y);
        unroot[y].push_back(x);
    }

    root(1, 1);

    for(int i=0; i<q; i++) {
        int a,b,c;
        cin>>a>>b>>c;

        int ret = max( get(a,b,c), max( get(b,a,c), get(c, a, b)));
        cout << ret <<endl;
    }
}
