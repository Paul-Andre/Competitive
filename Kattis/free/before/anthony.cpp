#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// Anthony Cora
// N       M
double t[1001][1001];
double rounds[1000+1000+1];
int main() {
    int N, M;
    cin >> N >> M;
    for (int i=0; i<N+M-1; i++) {
        cin >> rounds[i];
    }

    for (int i=1; i<1001; i++) {
        t[i][0] = 1.;
        t[0][i] = 0.;
    }

    for(int i=2; i<=N+M; i++) {
        for(int n=1; n<i && n<=N; n++) {
            int m = i-n;
            //cout << n << " " << m << '\n';
            t[n][m] = rounds[N+M-i]*t[n][m-1] + (1.-rounds[N+M-i])*t[n-1][m];
        }
    }

    /*
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=M; j++) {
            cout << t[i][j] << " " ;
        }
        cout << '\n';
    }
    */


    printf("%.9f\n", t[N][M]);
    //cout << t[N][M] << '\n';
}

