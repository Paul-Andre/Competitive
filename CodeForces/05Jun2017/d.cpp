#include <bits/stdc++.h>
using namespace std;

int n;
int A[5001];

int T[5001][5001];

int main() {
    cin >> n;
    for (int i=0; i< n; i++) {
        cin >> A[i+1];
    }

    /*
    T[0][1] = 1;
    T[1][0] = 1;
    */

    for (int ii=1; ii<=n; ii++) {
        for (int i=0; i<ii; i++) {

            int m = 0;
            for (int j=0; j<ii; j++) {
                if ( i!=j && (A[j] - A[ii] == 1 || A[j]-A[ii] == -1 || (A[j]-A[ii])%7==0 || j==0 ) ) {
                    m = max(m, T[i][j]);
                }
            }
            T[i][ii] = m+1;

            m = 0;
            for (int j=0; j<ii; j++) {
                if ( i!=j && (A[j] - A[ii] == 1 || A[j]-A[ii] == -1 || (A[j]-A[ii])%7==0 || j==0) ) {
                    m = max(m, T[j][i]);
                }
            }
            T[ii][i] = m+1;
        }
    }

    int m = 0;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            //cout << T[i][j] << " ";
            m = max(m, T[i][j]);
        }
        //cout << endl;
    }

    cout << m << endl;
}
