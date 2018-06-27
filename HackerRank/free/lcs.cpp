#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[n];
    int b[m];

    for (int i=0; i<n; i++) {
        cin >> a[n-1-i];
    }
    for (int i=0; i<m; i++) {
        cin >> b[m-1-i];
    }

    int t[n][m];
    int p[n][m];

    t[0][0] = int(a[0]==b[0]);
    p[0][0] = t[0][0]*2;

    for (int i=1; i<n; i++) {
        if (a[i] == b[0]) {
            t[i][0] = 1;
            p[i][0] = 2;
        }
        else if (t[i-1][0] == 1) {
            t[i][0] = 1;
            p[i][0] = 1;
        }
        else  {
            t[i][0] = 0;
            p[i][0] = 0;
        }
    }

    for (int j=1; j<m; j++) {
        if (a[0] == b[j]) {
            t[0][j] = 1;
            p[0][j] = 2;
        }
        else if (t[0][j-1] == 1) {
            t[0][j] = 1;
            p[0][j] = 3;
        }
        else  {
            t[0][j] = 0;
            p[0][j] = 0;
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            t[i][j] = t[i-1][j];
            p[i][j] = 1;

            if ( t[i][j-1] > t[i][j]) {
                t[i][j] = t[i][j-1];
                p[i][j] = 3;
            }
            if (a[i] == b[j] && t[i-1][j-1] + 1 > t[i][j]) {
                t[i][j] = t[i-1][j-1]+1;
                p[i][j] = 2;
            }
        }
    }
            

    int i=n-1;
    int j=m-1;

    while (i>=0 && j>=0 ) {
        assert(p[i][j]!=0);
        if (p[i][j] == 2) {
            cout << a[i];
            i--;
            j--;
            if (i>=0 && j>=0) {
                cout << ' ';
            }
        }
        else if (p[i][j] == 1) {
            i--;
        }
        else if (p[i][j] == 3) {
            j--;
        }
    }
    cout << '\n';
}
