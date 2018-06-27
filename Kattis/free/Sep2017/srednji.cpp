#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll A[100001];

ll g[2][200002];

int main() {
    ll N,B;
    cin>>N>>B;
    int c;
    for(int i=0; i<N; i++) {
        cin>>A[i];
        if (A[i] == B) {
            c =  i;
        }
    }
    for(int i=0; i<N; i++) {
        if(A[i] == B) {
            A[i] = 0;
        }
        else if (A[i] < B) {
            A[i] = -1;
        }
        else A[i] = 1;
    }
    ll sum = 0;
    for(int i=c; i>=0; i--) {
        sum+=A[i];
        g[0][sum + 100000]++;
    }
    sum = 0;
    for(int i=c; i<N; i++) {
        sum-=A[i];
        g[1][sum + 100000]++;
    }

    ll tot = 0;
    for(int i=0; i<200002; i++) {
        tot += g[0][i] * g[1][i];
    }


    cout << tot << endl;

}


