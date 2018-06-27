#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,k,p;

ll A[1001];
ll B[2001];

// [peop][keys]
ll dist[1001][2000];

int main() {
    cin>>n >>k>>p;
    for(int i=1;i<=n; i++) {
        cin >> A[i];
    }
    for(int i=1;i<=k; i++) {
        cin >> B[i];
    }

    sort(A+1, A+1+n);
    sort(B+1, B+1+k);

    

    for(int i=1; i<=n; i++) {
        dist[i][i-1] = 1000000000000;
        for(int j=i; j<=k; j++) {
            ll d = abs(A[i]-B[j]) + abs(B[j] - p);
            dist[i][j] = min(dist[i][j-1], max( dist[i-1][j-1], d) );
        }
    }

    cout << dist[n][k] <<endl;
}
