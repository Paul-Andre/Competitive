#include <bits/stdc++.h>
using namespace std;

vector<string> G;
vector<vector<bool>> vis;

string s;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int n, m;

bool trav(int x, int y, int p) {
    if (vis[x][y]) return false;
    if (p >= s.size()) return false;
    if ( G[x][y] != s[p]) return false;

    vis[x][y] = true;

    if (x == n-1 && y == m-1) return true;

    for(int i=0; i<4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx >= 0 && xx<n && yy>=0 && yy<m) {
            bool r = trav(xx, yy, p+1);
            if (r) return true;
        }
    }

    vis[x][y] = false;
    return false;
}


int main() {

    cin >> s;

    string t;
    while(cin >> t) {
        //cout << t << endl;
        G.push_back(t);
        vis.push_back(vector<bool>(vis.size(), false));
    }

    n = G.size();
    m = G[0].size();

    trav(0,0,0);

    for(int i=0; i< n; i++) {
        for(int j=0; j<m; j++) {
            if (!vis[i][j]) {
                cout << '.';
            }
            else {
                cout << G[i][j];
            }
        }
        cout << endl;
    }
}
