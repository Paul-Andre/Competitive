#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define x first
#define y second

int n;
vector<pii> S[1501];
int W[1501];
int H[1501];

int grid[751][751];

pii operator-(pii a) {
    a.x *= -1;
    a.y *= -1;
    return a;
}

pii operator+(pii a, pii b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}
pii operator*(int b, pii a) {
    a.x *= b;
    a.y *= b;
    return a;
}

pii rott(int i, int j, int rot) {
    rot %= 4;
    rot += 4;
    rot %= 4;
    if (rot == 0) {
        return S[i][j];
    }
    else if ( rot == 2) {
        return pii(W[i]+1,H[i]+1) + -S[i][j];
    } 
    pii in = S[i][j];
    pii ret;
    ret.x = in.y;
    ret.y = W[i] + 1 - in.x;
    if (rot == 1) {
        return ret;
    }
    else {
        return pii(H[i]+1,W[i]+1) + -ret;
    }
}


bool check(int i, int rot, int x, int y) {
    for (int j=0; j<S[i].size(); j++ ) {
        pii ii = rott(i, j, rot);
        int xx = ii.x + x - 1;
        int yy = ii.y + y - 1;

        if (grid[xx][yy]) {
            return false;
        }
    }
    return true;
}

void add(int i, int rot, int x, int y) {
    //cerr << "Adding " << i << " at " << x << " " << y << " " << rot << endl;
    for (int j=0; j<S[i].size(); j++ ) {
        pii ii = rott(i, j, rot);
        int xx = ii.x + x - 1;
        int yy = ii.y + y - 1;
        //cout << "xx yy " << xx << " " << yy << endl;

        grid[xx][yy] = i;
    }
}

int gW = 0;
int gH = 0;

int main() {
    cin >> n;

    for (int i=1; i<=n; i++) {
        int s;
        cin >>s;
        for (int j=0; j<s; j++) {
            int x,y;
            cin >> x >> y;
            S[i].push_back(pii(x,y));
            W[i] = max(W[i], x);
            H[i] = max(H[i], y);
        }
    }

    for (int i=1; i<=n ; i++) {

        /*
        cout << i << " i \n";
        cout << gW+1 << " " << gH+1 << endl;
        for (int x=0; x<=gW; x++) {
            for (int y=0; y<=gH; y++) {
                cout << grid[x][y] << " ";
            }
            cout << endl;
        }
        */
        long long potS = 1000000000000;
        int potx = 0;
        int poty = 0;
        int potrot = 0;

        //cerr << potS << " potS" << endl;

        for (int x=0; x<=gW+5; x++) {
            for (int y=0; y<=gH+5; y++) {
                for (int rot =0; rot <4; rot++) {
                    if (check(i, rot, x, y)) {

                        int w = W[i];
                        int h = H[i];
                        if (rot % 2) {
                            w = H[i];
                            h = W[i];
                        }

                        int ghW = max(gW, x+w-1);
                        int ghH = max(gH, y+h-1);
                        if ( ghW * ghH < potS) {
                            potS = ghW * ghH;
                            potx = x;
                            poty = y;
                            potrot = rot;
                        }
                    }
                }
            }
        }
        if ( potS == 1000000000000) {
            exit(1);
        }

        add(i, potrot, potx, poty);

        int w = W[i];
        int h = H[i];
        if (potrot % 2) {
            w = H[i];
            h = W[i];
        }
        gW = max(gW, potx+w-1);
        gH = max(gH, poty+h-1);

    }

    cout << gW+1 << " " << gH+1 << endl;
    for (int x=0; x<=gW; x++) {
        for (int y=0; y<=gH; y++) {
            cout << grid[x][y] << " ";
        }
        cout << endl;
    }
}
