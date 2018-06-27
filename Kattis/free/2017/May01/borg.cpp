#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define x first
#define y second


struct heapItem {
    pii p;
    int d;
};

bool operator<(heapItem a, heapItem b) {
    return a.d>b.d;
}


int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1, 0};

int main() {
    int N;
    cin >> N;

    while(N--) {

        int w, h;
        cin >> w >> h;
        pii start;

        vector<vector<char>> grid(w, vector<char>(h));

        int aliums = 0;

        for (int j=0; j<h; j++) {
            for (int i=0; i<w; i++) {
                char c;
                do {
                   c = getchar();
                }
                while (c=='\n');

                grid[i][j] = c;
                if (grid[i][j] == 'S') {
                    start = pii(i,j);
                }
                if (grid[i][j] == 'A') {
                    aliums++;
                }
            }
        }

        vector<vector<bool>> done(w,vector<bool>(h, false));

        priority_queue<heapItem> heap;
        int tot = 0;

        while (true) {

            queue<pii> q;
            vector<vector<bool>> vis(w,vector<bool>(h, false));
            q.push(start);
            vis[start.x][start.y] = true;

            int count = 0;

            while (!q.empty()) {
                int size = q.size();
                count ++;

                for (int i=0; i<size; i++) {
                    pii p = q.front();
                    q.pop();

                    for (int k=0; k<4; k++) {
                        int x = p.x + dx[k];
                        int y = p.y + dy[k];
                        if (x>=0 && x<w && y>=0 && y<h && !vis[x][y] && grid[x][y]!='#') {
                            vis[x][y] = true;
                            q.push(pii(x,y));
                            if (grid[x][y] == 'A') {
                                heapItem hi;
                                hi.p = pii(x,y);
                                hi.d = count;
                                heap.push(hi);
                            }
                        }
                    }
                }
            }

            if (aliums!=0) {
                
                heapItem hi;
                pii p;
                do {
                    hi = heap.top();
                    heap.pop();
                    p = hi.p;
                }
                while (done[p.x][p.y]);

                aliums--;
                done[p.x][p.y]=true;
                tot += hi.d;
                start = p;
            }


            if (aliums == 0) {
                break;
            }
        }
        cout << tot << '\n';
    }
}


