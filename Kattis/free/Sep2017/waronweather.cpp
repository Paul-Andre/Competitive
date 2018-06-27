#define _USE_MATH_DEFINES
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int k,m;

#define SQR(x) ((x)*(x))

double S[100][3];
double T[100][3];

bool get(int s, int t) {
    double up = 0; 
    double dn = 0; 
    for(int i=0; i<3; i++) {
        up += (T[t][i] - S[s][i])*S[s][i];
        dn += SQR(T[t][i]-S[s][i]);
    }

    double p = -up/dn;

    return p>=1;
}


int main() {
    while(true) {
        cin>>k>>m;
        if (k==0 && m== 0) break;

        for(int i=0; i<k; i++) {
            for(int j=0; j<3; j++) cin>>S[i][j];
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<3; j++) cin>>T[i][j];
        }
        int tot =0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<k; j++) {
                if (get(j, i)) {
                    tot++;
                    break;
                }
            }
        }

        cout << tot <<endl;

    }
}
