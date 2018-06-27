#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll no[3][100005];

ll n;
ll p[3];

ll A[100005];
int main() {
    cin>>n>>p[0]>>p[1]>>p[2];

    for(int i=0; i<n ;i++) {
        cin>>A[i];
    }

    no[0][0] = p[0]*A[0];
    for(int i=1; i<n ;i++) {
        no[0][i] = max(no[0][i-1], p[0]*A[i]);
    }

    for(int j=1; j<=2; j++) {
        no[j][0] = no[j-1][0] + p[j]*A[0];
        for(int i=1; i<n ;i++) {
            no[j][i] = max(no[j][i-1], p[j]*A[i] + no[j-1][i]);
        }
    }

    /*
    for(int j=0; j<=2; j++) {
        for(int i=0; i<n; i++) {
            cerr << no[j][i] << " ";
        }
        cerr << endl;
    }
    */

    cout << no[2][n-1] <<endl;
}







