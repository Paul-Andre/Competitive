#include <bits/stdc++.h>
using namespace std;


int m,n;

int circ[100][3];
int rect[100][4];

#define SQR(x) ((x)*(x))


int main() {
    cin>>m;
    int ci = 0;
    int ri = 0;
    for(int i=0; i<m; i++) {
        string s;
        cin>>s;
        if(s=="rectangle") {
            for(int j=0; j<4; j++) {
                cin>>rect[ri][j];
            }
                ri++;
        }
        else {
            for(int j=0; j<3; j++) {
                cin>>circ[ci][j];
            }
                ci++;
        }
    }

    cin>>n;
    for(int i=0; i<n; i++) {
        int x,y;
        cin>>x>>y;
        int tot =0;
        for(int j=0; j<ci; j++) {
            if (SQR(x-circ[j][0]) + SQR(y - circ[j][1]) <= SQR(circ[j][2])) {
                tot ++;
            }
        }
        for(int j=0; j<ri; j++) {
            if (rect[j][0] <= x && x <= rect[j][2] && rect[j][1] <= y && y <= rect[j][3]) {
                tot++;
            }
        }
        cout << tot <<endl;
    }
}



    


