#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef unsigned long long ull;

// [n][num unhappy]
ull unhappy[3001][3001];

// at most n-k unhappy
ull query(int n, int k){
    ull tot = 0;

    for (int i=n-k; i>=0; i--) {
        tot+=unhappy[n][i];
        tot%= MOD;
    }

    return tot;
}

int main() {

    unhappy[1][1] = 1;

    for (int i=2; i<=3000; i++) {
        for (int j=1; j<=3000; j++) {
            unhappy[i][j] = (unhappy[i-1][j-1]*(i-2*(j-1)))%MOD
                + (unhappy[i-1][j]*2*j) % MOD;
            unhappy[i][j] %= MOD;
        }
    }


    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int k;
        cin >> n >> k;
        // Find the number of ways to arrange 'n' people such that at least 'k' of them will be happy
        // The return value must be modulo 10^9 + 7
        ull result = query(n, k);
        cout << result << endl;
    }
    return 0;
}
