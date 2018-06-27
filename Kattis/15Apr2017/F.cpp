#include <iostream>
using namespace std;
#define MOD 1000000007

long t[10001][101];

int main() {
    int n,w,h;
    cin >> n >> w >> h;
    for (int i=0; i<=n && i<=w; i++) {
        t[i][1] = 1;
    }
    for(int i=0; i<=n; i++) {
        for(int j=2; j<=w; j++) {
            long sum = 0;
            for (int k=0; k<=h; k++) {
                if (i-k >=0) {
                    sum += t[i-k][j-1];
                    sum %= MOD;
                }
            }
            t[i][j] = sum;
        }
    }
    for(int i=0; i<=n; i++) {
        for(int j=1; j<=w; j++) {
            cout << t[i][j] << ' ';
        }
    cout <<'\n';
    }
    cout  << t[n][w] - (n/w + 1) << '\n';
}




