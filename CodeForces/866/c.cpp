#include <bits/stdc++.h>
using namespace std;


int N;
int F[50];
int S[50];
double P[50];

double pless[51][10000];

double ex[51][10000];

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin >> F[i] >> S[i] >> P[i];
        P[i]*0.01;
    }

    for(int i=0; i<10000; i++) {
        pless[50][i] = 1;
    }

    for(int i=N-1; i>=0; i--) {
        for(int j=0; j<6000; j++) {
            pless[i][j+F[i]] += P[i]*pless[i+1][j];
            pless[i][j+S[i]] += (1-P[i]) * pless[i+1][j];
        }
    }

    for(int i=N-1; i>=0; i--) {
        for(int j=0; j<6000; j++) {
            pless[i][j+F[i]] += P[i]*pless[i+1][j];
            pless[i][j+S[i]] += (1-P[i]) * pless[i+1][j];
        }
    }

    for(int iii= 0; iii< 100000; iii++) {
        for(int i=0; i<N; i++) {
            double ff = F[i] + exp[i+1];
            double ss = S[i] + min(exp[0], exp[i+1]);
            ex[i] = P[i]*ff + (1-P[i])*ss;
        }
    }


}


