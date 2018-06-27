
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long t[1000][1000];

int main() {
    int T;
    cin >> T;
    while(T--) {
        int M, N;
        cin >> M >> N;

        vector<int> a(N);
        vector<int> b(N);

        long nec = 0;
        for (int i=0; i<N; i++) {
            cin >> a[i] >> b[i];
            nec += abs(a[i] - b[i]);
        }


        //if 

        long cum = 0;

        for (int i=1; i<N; i++) {
            for (int j=0; j<i-1; j++) {
                t[i][j] = t[i-1][j] + abs(a[i]-b[i-1]);
            }
            long mn = 100000000;
            for (int j=0; j<i-1; j++) {
                mn = min(mn, t[i-1][j] + abs(a[i]-b[j]) );
            }

            mn = min(mn, cum);
            t[i][i-1] = mn;

            cum += abs(a[i]-b[i-1]);

        }

        
        long mn = 100000000;
        for (int i=0; i<N-1; i++) {
            mn = min(mn, t[N-1][i]);
        }
        if (N<=2) {
            mn = 0;
        }

        /*
        cout << '\n';
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                cout << t[i][j] << " " ;
            }
            cout << '\n';
        }

        cout << "nec: " << nec << '\n';
        */


        cout << mn + nec <<'\n';
    }
    return 0;
}
