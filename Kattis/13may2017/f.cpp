#include <bits/stdc++.h>
using namespace std;

// What I did here is really stupid

char in[500][500];

int dx[]= {0,1,0, -1};
int dy[]= {1,0, -1,0};


struct Edge{
    int u, v;
    int cap;
    int f;
};

class Node{
    public:
    vector<Edge*> fwd;
    vector<Edge*> bck;
};

vector<Node> nodes;

vector<Edge*> edges;

void addEdge(int u, int v, int cap) {
    Edge *e = new Edge;
    e->u = u;
    e->v = v;
    e->cap = cap;
    e->f = 0;
    nodes[u].fwd.push_back(e);
    nodes[v].bck.push_back(e);
    edges.push_back(e);
}

int link[500][500];

int main() {
    int n, m;

    cin >> n >> m;

    nodes.push_back(Node());
    nodes.push_back(Node());

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            link[i][j] = -1;
            cin >> in[i][j];
            if (in[i][j] == 'W') {
                link[i][j] = nodes.size();
                nodes.push_back(Node());
                addEdge(link[i][j],1,1);
            }
        }
    }


    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if ( in[i][j] == 'B') {

                nodes.push_back(Node());
                int nn = nodes.size()-1;

                addEdge(0,nn,2);
                link[i][j] = nn;

                for (int k=0; k<4; k++) {

                    int kk = (k+1)%4;
                    int x1 = i+dx[k];
                    int y1 = j+dy[k];
                    int x2 = i+dx[kk];
                    int y2 = j+dy[kk];

                    if (x1>=0 && x1<n && x2>=0 && x2<n && y1>=0 && y1<m && y2>=0 && y2<m  &&
                            in[x1][y1] == 'W' && in[x2][y2] == 'W') {

                        //cout << "k " << k << '\n';

                        nodes.push_back(Node());
                        int nnn = nodes.size()-1;

                        addEdge(nn,nnn,2);


                        addEdge(nnn,link[x1][y1], 1);
                        addEdge(nnn,link[x2][y2], 1);
                    }
                }
            }
        }
    }


    for (int i=0; i<edges.size(); i++) {
        cout << edges[i]->u << " " << edges[i]->v << " : " << edges[i]->f << "/" << edges[i]->cap << '\n';
    }


    while(true) {



        queue<int> que;
        vector<Edge*> parent(nodes.size(), nullptr);
        vector<bool> front(nodes.size());
        vector<bool> vis(nodes.size(), false);

        que.push(0);
        vis[0] = 1;

        while(!que.empty()) {
            int node = que.front();
            que.pop();

            if (node == 1) {
                break;
            }

            for (int i=0; i<nodes[node].fwd.size(); i++) {
                if (nodes[node].fwd[i]->cap - nodes[node].fwd[i]->f > 0) {
                    int v = nodes[node].fwd[i]->v;
                    if (!vis[v]) {
                        que.push(v);
                        vis[v] = true;
                        parent[v] = nodes[node].fwd[i];
                        front[v] = true;
                    }
                }
            }
            for (int i=0; i<nodes[node].bck.size(); i++) {
                if (nodes[node].bck[i]->f > 0) {
                    int v = nodes[node].bck[i]->u;
                    if (!vis[v]) {
                        que.push(v);
                        vis[v] = true;
                        parent[v] = nodes[node].bck[i];
                        front[v] = false;
                    }
                }
            }
        }

        if (!vis[1]) {
            break;
        }


        int nn = 1;
        while (nn != 0) {
            Edge *e = parent[nn];
            if (front[nn]) {
                e->f+=1;
                nn= e->u;
            }else {
                e->f-=1;
                nn = e->v;
            }
        }

        cout << "==========================\n";
        for (int i=0; i<edges.size(); i++) {
            cout << edges[i]->u << " " << edges[i]->v << " : " << edges[i]->f << "/" << edges[i]->cap << '\n';
        }
    }

    for (int i=0; i<nodes[0].fwd.size() ; i++) {
        if(nodes[0].fwd[i]->f != 2) {
            cout << "NO\n";
            return 0;
        }
    }
    for (int i=0; i<nodes[1].bck.size() ; i++) {
        if(nodes[1].bck[i]->f != 1) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

}

