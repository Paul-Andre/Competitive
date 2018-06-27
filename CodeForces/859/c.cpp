#include <bits/stdc++.h>
using namespace std;

int N;
int A[101];

typedef long long ll;

ll B[100][2][2];

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin >>A[i+1];
    }

    B[N][0][0] = A[N];
    B[N][1][1] = A[N];
    B[N][0][1] = 0;
    B[N][1][0] = 0;

    for(int i = N-1; i>=1; i--) {
        for(int j=0; j<2; j++) {
            ll take = A[i] + B[i+1][1-j][j];
            ll leave = B[i+1][j][j];
            if (take >= leave) {
                B[i][j][j] = take;
                B[i][j][1-j] = B[i+1][1-j][1-j];
            }
            else {
                B[i][j][j] = leave;
                B[i][j][1-j] = A[i] + B[i+1][j][1-j];
            }
        }
    }

    cout << B[1][0][1] << " " << B[1][0][0] << endl;
}





    





