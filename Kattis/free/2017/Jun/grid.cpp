#include <bits/stdc++.h>
using namespace std;

int grid[500][500];
bool vis[500][500];

int dx[] = {1,0,-1, 0};
int dy[] = {0,-1, 0, 1};

int n, m;

typedef pair<int,int> pii;

#define x first
#define y second

int main() {
    cin >> n >> m;
    for(int i=0; i< n; i++) {
        for(int j=0; j<m; j++) {
            char c;
            cin >> c;
            grid[i][j] = (c-'0');
        }
    }


    queue<pii> q;

    q.push(pii(0,0));
    vis[0][0] = true;

    int count = 0;

    while(!q.empty()) {
        int size = q.size();

        for(int ii=0; ii<size; ii++) {
            pii p = q.front();
            q.pop();


            if (p.x == n-1 &&  p.y == m-1) {
                cout << count << endl;
                exit(0);
            }

            int mult = grid[p.x][p.y];

            for(int k=0; k<4; k++) {
                int x = p.x + mult*dx[k];
                int y = p.y + mult*dy[k];


                if( x>=0 && x<n && y>=0 && y < m && !vis[x][y]) {
                    vis[x][y] = true;
                    q.push(pii(x,y));
                }
            }
        }
        count ++;
    }
    cout << "-1\n";
}
