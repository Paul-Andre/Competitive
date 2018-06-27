#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N;
int n;

double prob[64][64];
double win[5][64];

double m = -100;


//int way[128];

double calc (int N, vector<int> &got) {
    for(ull i=0;i<1<<(1<<(N-1)); i++) {
        vector<int> newGot(1<<(N-1));
        for(int j=0; j<1<<(N-1); j++) {
            newGot[j] == got[2*j+!!(i&(1<<j))];
        }
        exp = calc(N-1, newGot);
    }
}
            






int main() {
    cin>>N;
    n = 1<<N;
    //int saute = 1<<(6-N)
    for(int i=0; i<n; i++) {
        for(int j=0; j<n ;j++) {
            cin >> prob[i][j];
        }
    }

    for(int j=0; j<n; j+=2) {
        win[0][j] = prob[j][j+1];
        win[0][j-1] = 1 - prob[j][j+1];
    }

    for(int i=1; i<=N; i++) {
        int M = N-1-i;
        for(int j=0; j<(1<<M); j++) {
            for(int k=0; k<(1<<(i+1)); k++) {






}





    





