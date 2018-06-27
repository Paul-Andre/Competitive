#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;

    cin >> n;

    vector<vector<char> > g(n,vector<char>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> g[i][j];
        }
    }


    vector<vector<int> > m(n,vector<int>(n,3001));

    for (int perm = 0; perm<4; perm++) {

        if (perm&1) {
            reverse(g.begin(), g.end());
            reverse(m.begin(), m.end());
        }
        if (perm&2) {
            for (int i=0; i<n; i++) {
                reverse(g[i].begin(), g[i].end());
                reverse(m[i].begin(), m[i].end());
            }
        }

        for (int j=0; j<n; j++) {

            if (g[j][0]=='3') {
                m[j][0] = 0;
            }

            for (int i=1; i<n; i++) {
                if (g[j][i]=='3') {
                    m[j][i] = 0;
                }
                m[j][i] = min(m[j][i], m[j][i-1]+1);
            }
        }

        for (int j=1; j<n; j++) {
            for (int i=0; i<n; i++) {
                m[j][i] = min(m[j][i], m[j-1][i]+1);
            }
        }

        if (perm&2) {
            for (int i=0; i<n; i++) {
                reverse(g[i].begin(), g[i].end());
                reverse(m[i].begin(), m[i].end());
            }
        }
        
        if (perm&1) {
            reverse(g.begin(), g.end());
            reverse(m.begin(), m.end());
        }
    }

    int ma = -1;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            //cout << m[i][j] << " ";
            if (g[i][j]=='1') {
                ma = max(ma, m[i][j]);
            }
        }
        //cout << '\n';
    }

    cout << ma << '\n';
}

