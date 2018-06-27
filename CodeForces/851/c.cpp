#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
long long points[1000][5];

bool bad[1000];

int main() {
    cin >>n;
    if (n>=34) {
        cout<<0<<endl;
        return 0;
    }

    for(int i=0; i<n; i++) {
        cin >> points[i][0] 
        >> points[i][1] 
        >> points[i][2] 
        >> points[i][3] 
        >> points[i][4] ;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if ( j==k) continue;
                ll cross = 0;
                for(int kk=0; kk<5; kk++) {
                    cross += (points[j][kk] - points[i][kk]) * (points[k][kk] - points[i][kk]);
                }

                if (cross > 0) {
                    bad[i] = true;
                    //printf("bad: %d, %d, %d\n", i, j, k);
                }
            }
        }
    }

    int goodCnt = 0;
    for(int i=0; i<n;i++) {
        goodCnt += !(bad[i]);
    }
    cout << goodCnt <<endl;

    for(int i=0; i<n;i++) {
        if (!bad[i]) {
            cout << i+1 <<endl;
        }
    }
}

