#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int R[100000];
int T[100000];
int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> R[i];
    }
    if ( N == 1) {
        cout << 1 << endl;
        exit(0);
    }

    int m = 0;
    for (int i=1; i<N; i++) {
        T[i] = T[i-1];
        if (R[i] > R[i-1]) {
            T[i] = T[i-1] + 1;
        }
        if (R[i] < R[i-1]) {
            T[i] = T[i-1] - 1;
        }
        m = min(m, T[i]);
    }

    for (int i=0; i<N; i++) {
        T[i] -= m-1;
    }

    for (int i=0; i<N; i++) {
        T[i] = 1;
        if (i-1 >= 0 && R[i-1] < R[i]) {
            T[i] = max(T[i], T[i-1]+1);
        }
        if (i+1 < N && R[i+1] < R[i]) {
            T[i] = max(T[i], T[i+1]+1);
        }
    }

    for (int i=N-1; i>=0; i--) {
        T[i] = 1;
        if (i-1 >= 0 && R[i-1] < R[i]) {
            T[i] = max(T[i], T[i-1]+1);
        }
        if (i+1 < N && R[i+1] < R[i]) {
            T[i] = max(T[i], T[i+1]+1);
        }
    }

    long tot = 0;
    for (int i=0; i<N; i++) {
        tot += T[i];
    }
    cout << tot << endl;
    
    return 0;
}
