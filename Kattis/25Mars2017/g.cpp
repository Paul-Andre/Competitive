#include <iostream>
#include <queue>
using namespace std;


char g[50][50];
bool vis[50][50];
bool breeze[50][50];

int W, H;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    cin >> W >> H;

    int x, y;
    for (int j = 0; j< H; j++) {
        for (int i=0; i<W; i++) {
            cin >> g[i][j];
            if (g[i][j] == 'P') {
                x = i;
                y = j;
                g[i][j] = '.';
            }
        }
    }

    for (int j = 0; j< H; j++) {
        for (int i=0; i<W; i++) {
            if (g[i][j] == 'T') {
                for (int k = 0; k<4; k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    breeze[nx][ny] = true;
                }
            }
        }
    }


    int gold = 0;

    queue<int> xq;
    queue<int> yq;

    xq.push(x);
    yq.push(y);
    vis[x][y] = true;

    while (!xq.empty()) {


        int x = xq.front();
        int y = yq.front();
        xq.pop();
        yq.pop();

        /*
        for (int j = 0; j< H; j++) {
            for (int i=0; i<W; i++) {
                cout << vis[i][j];
            }
            cout << '\n';
        }
            cout << x << " " << y << '\n';
            */

        if (g[x][y] == 'G') {
            gold ++;
            g[x][y] = '.';
        }

        if(breeze[x][y]) {
            continue;
        }

        for (int i =0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if (g[nx][ny] != '#' && !vis[nx][ny] ) {
                xq.push(nx);
                yq.push(ny);
                vis[nx][ny] = true;
            }
        }
    }
    cout << gold << '\n';
}
