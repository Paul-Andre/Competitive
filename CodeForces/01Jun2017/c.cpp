#include <bits/stdc++.h>
using namespace std;

int n, S;

int A[100000];
int B[100000];

int main() {
    cin >> n >> S;

    for (int i=0; i<n; i++) {
        cin >> A[i];
    }

    int a = 0;
    int b = min(1300,n);
    long long tot = 0;

    while(true) {
        if (a == b) break;
        int c = (a+b+1)/2;

        for (int i=0; i<n; i++) {
            B[i] = A[i] + c*(i+1);
        }

        sort(B, B+n);

        tot = 0;
        for (int i=0; i<c; i++) {
            tot += B[i];
        }

        if (tot > S) {
            b = c-1;
        }
        else {
            a = c;
        }
    }

    int c = a;
    for (int i=0; i<n; i++) {
        B[i] = A[i] + c*(i+1);
    }

    sort(B, B+n);

    tot = 0;
    for (int i=0; i<c; i++) {
        tot += B[i];
    }

    cout << a << " " << tot << endl;
}






