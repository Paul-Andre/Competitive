#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<bool>> G(100, vector<bool>(100, false));

#define SWAP(a,b) {auto tmp = a; a=b; b=tmp;}

int main() {
    cin >> n>> m;
    int blackCount = 0;
    int top = 1000, bottom = -1000, left=1000, right=-1000;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char c;
            cin >> c;
            if(c=='B') {
                G[i][j] = true;
                blackCount++;
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
            else G[i][j] = false;
        }
    }
    if(blackCount == 0) {
        cout <<"1\n";
        return 0;
    }
    int height = bottom -top +1;
    int width =  right-left +1;
        cerr <<height <<" " << width <<endl;

    if(height == width) {
        cerr <<height <<" " << width <<endl;
        cerr << "wew\n";
        cout << (height*width - blackCount) <<endl;
        return 0;
    }



    if (width> height) {
        cerr <<"flippe\n";
        vector<vector<bool>> tmp = G;
        for(int i=0; i<100; i++) {
            for(int j=0; j<100; j++) {
                G[i][j] = tmp[j][i];
            }
        }

        SWAP(top, left)
        SWAP(bottom, right)
        SWAP(n, m)
        SWAP(width, height)
    }

    int best = 1000000;
    for(int x = 0; x+height-1<m; x++) {
        int totWhite = 0;
        for(int i=top ;i<=bottom; i++) {
            for(int j=x; j<=x+height-1; j++) {
                totWhite += (int)(!G[i][j]);
            }
        }
        cerr <<"tot " <<totWhite<<endl;
        best = min(best, totWhite);
    }
    if ( best == 1000000) cout << "-1\n";
    else cout << best <<endl;
}
        
