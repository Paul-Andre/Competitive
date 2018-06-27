#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

char g[400][400];


int R, C;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int count = 1;
queue<int> xq;
queue<int> yq;

void visit(int r,int c) {
    //cout << "visiting " << r << " " << c <<'\n';

    g[r][c]='*';
    xq.push(r);
    yq.push(c);

    queue<int> nxq;
    queue<int> nyq;

    nxq.push(r);
    nyq.push(c);

    while(!nxq.empty()) {

        int x = nxq.front();
        nxq.pop();
        int y = nyq.front();
        nyq.pop();

        for(int j=0; j<4; j++) {
            int nnx = x+dx[j];
            int nny = y+dy[j];

            if(nnx>=0 && nnx<R && nny>=0 && nny<C) {
                if (g[nnx][nny]=='D') {
                    g[nnx][nny] = '!';
                    xq.push(nnx);
                    yq.push(nny);

                    nxq.push(nnx);
                    nyq.push(nny);

                    if (nnx==0 || nnx ==R-1 || nny == 0 || nny == C-1) {
                        cout << count << '\n';
                        exit(0);
                    }
                }
            }
        }
    }
}

int main() {

    cin >> R >> C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> g[i][j];
        }
    }

    int r, c;
    cin >> r >> c;
    r--; c--;

    visit(r,c);

    /*
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << g[i][j];
        }
        cout << '\n';
    }
    cout << count <<'\n';
    */

    while(!xq.empty()) {
        int ss = xq.size();
        count++;

        for (int iii=0; iii<ss; iii++) {

            int x = xq.front();
            xq.pop();
            int y = yq.front();
            yq.pop();

            for(int i=0; i<4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx>=0 && nx<R && ny>=0 && ny<C) {
                    if (g[nx][ny]=='c') {
                        visit(nx,ny);
                    }
                }
            }
        }

        /*
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                cout << g[i][j];
            }
            cout << '\n';
        }
        cout << count <<'\n';
        */
    }

}
