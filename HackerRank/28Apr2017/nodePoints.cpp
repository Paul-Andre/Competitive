#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
int n;

typedef pair<int, int> pii;

vector<int> tree[1000];
vector<int> unrooted[1000];
bool vis[1000];

pii points[1000];
int ass[1000];

bool visW[1000];
int weight[1000];


void rootTree(int i) {
    vis[i] = true;
    for (int j=0; j<unrooted[i].size(); j++) {
        int u = unrooted[i][j];
        if (!vis[u]) {
            tree[i].push_back(u);
            rootTree(u);
        }
    }
}


void assWeight(int i) {
    int tot =0;
    for (int j=0; j<tree[i].size(); j++) {
        int u = tree[i][j];
        assWeight(u);
        tot += weight[u];
    }
    weight[i] = tot + 1;
}
    

bool sortRot(int aa, int bb) {
    pii a = points[aa];
    pii b = points[bb];
    return a.x*b.y > b.x*a.y;
}


void assign(vector<int> &pts, int i) {
    int min = 100000000;
    int index;
    //cout << "=================\n";
    for (int i=0; i<pts.size(); i++) {
        if ( points[pts[i]].x < min) {
            min = points[pts[i]].x;
            index = i;
        }
        //cout << pts[i] << '\n';
    }
    
    int temp = pts[index];
    pts[index] = pts[0];
    pts[0] = temp;

    ass[i] = temp;

    int xx = points[temp].x;
    int yy = points[temp].y;
    for (int i=0; i<pts.size(); i++) {
        points[pts[i]].x -= xx;
        points[pts[i]].y -= yy;
    }

    sort(pts.begin()+1, pts.end(), sortRot);


    int ii=1;

    for (int j=0; j<tree[i].size(); j++) {
        int u = tree[i][j];
        int w = weight[u];
        vector<int > slice(&pts[ii], &pts[ii+w]);
        assign(slice, u);
        ii+=w;
    }
}

int main() {
    cin >> n;
    for(int a0 = 0; a0 < n-1; a0++){
        // An edge connects nodes 'u' and 'v':
        int u;
        int v;
        cin >> u >> v;
        u--;
        v--;
        unrooted[u].push_back(v);
        unrooted[v].push_back(u);
    }
    for(int a0 = 0; a0 < n; a0++){
        // Cartesian coordinate:
        int x;
        int y;
        cin >> x >> y;
        points[a0] = pii(x,y);
        ass[a0] = a0;
    }

    rootTree(0);
    //cout << "fin root\n";

    assWeight(0);
    //cout << "fin weight\n";

    vector<int> pts(n);
    for(int i=0; i<n; i++) pts[i] = i;

    assign(pts, 0);
    //cout << "fin awss\n";

    for (int i=0; i<n-1; i++) {
        cout << 1+ass[i] << " ";
    }
    cout <<1+ ass[n-1] << "\n";
}
