#include <bits/stdc++.h>
using namespace std;


int n, m;

bool grid[10002][10002];
bool vis[10002][10002];

vector<int> rowDwellers[10002];
vector<int> columnDwellers[10002];

bool visRow[10002];
bool visCol[10002];

typedef pair<int,int> pii;


int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
    

queue<pii> que;


int tot = 0;


void dwell(int x, int y) {
    if (x<= 0 || x>n || y<=0 || y>m) return ;
    rowDwellers[x].push_back(y);
    columnDwellers[y].push_back(x);
}

void addToQueue(int x, int y) {
    if (vis[x][y] ||  !grid[x][y] || x<= 0 || x>n || y<=0 || y>m) return ;
    vis[x][y] = true;

    //cerr << x << " " << y << endl;
    if(pii(x,y) == pii(n,m) ) {
        cout << tot << endl;
        exit(0);
    }


    que.push(pii(x,y));

    for(int k=0; k< 4; k++) {
        int xx = x + dx[k];
        int yy = y +  dy[k];
        addToQueue(xx, yy);
    }
}

void tryAddToQueue(int x, int y) {

    if (vis[x][y] || x<= 0 || x>n || y<=0 || y>m) return ;
    //cerr << "try " <<  x << " " << y << endl;
    if(pii(x,y) == pii(n,m) ) {
        cout << tot << endl;
        exit(0);
    }
    //vis[x][y] = true;

    addToQueue(x, y);
    for(int k=0; k< 4; k++) {
        int xx = x + dx[k];
        int yy = y +  dy[k];
        addToQueue(xx, yy);
    }
}

int main() {
    int k;
    cin >> n >> m >> k;
    for(int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = true;
        dwell(x,y);
        for(int k=0; k< 4; k++) {
            int xx = x + dx[k];
            int yy = y +  dy[k];
            dwell(xx, yy);
        }
        //cerr << "as\n";
    }

    dwell(n,m);


    addToQueue(1,1);


    while(!que.empty()) {

        tot ++;
        int size = que.size(); 
        for(int ii=0; ii<size; ii++) {
            pii p = que.front();
            que.pop();
            //cerr << "pop\n";


            for(int j = p.first-1; j<= p.first+1; j++) {

                if (j>=1 && j<=n && !visRow[j]) {
                    visRow[j] = true;
                    for(int i=0; i<rowDwellers[j].size() ; i++) {
                        int u = rowDwellers[j][i];
                        tryAddToQueue(j, u);
                    }
                }
            }

            for(int j = p.second-1; j<= p.second+1; j++) {
                if (j>=1 && j<=m && !visCol[j]) {
                    visCol[j] = true;
                    for(int i=0; i<columnDwellers[j].size() ; i++) {
                        int u = columnDwellers[j][i];
                        tryAddToQueue(u, j);
                    }
                }
            }
        }
    }

    cout << "-1\n";
}
    
