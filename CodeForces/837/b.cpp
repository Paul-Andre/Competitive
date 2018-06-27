#include <bits/stdc++.h>
using namespace std;


int n,m;
char F[100][100];

char get(int x, int y, int w, int h) {
    char r = F[x][y];
    for(int i = 0; i<w; i++) {
        for(int j=0; j<h;j++) {
            int xx = x+i;
            int yy = y+j;
            if (F[xx][yy] != r) {
                r = '\0';
            }
        }
    }
    return r;
}


int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>F[i][j];
        }
    }

    if (n%3 == 0) {
        char a = get(0,0,n/3, m);
        char b = get(n/3,0,n/3, m);
        char c = get(n/3*2,0,n/3, m);

        if(a && b && c && a!=b && b!=c && c!=a) {
            cout<<"YES\n";
            return 0;
        }
    }

    if (m%3 == 0) {
        char a = get(0,0,n, m/3);
        char b = get(0,m/3,n, m/3);
        char c = get(0,m/3*2,n, m/3);

        if(a && b && c && a!=b && b!=c && c!=a) {
            cout<<"YES\n";
            return 0;
        }
    }

    cout<<"NO\n";
}
