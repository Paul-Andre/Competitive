#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
ll A[2000];
ll B[2000];


int main() {
    cin >>k>>n;
    for(int i=0; i<k; i++) {
        cin >>A[i];
    }
    for(int i=0; i<n; i++) {
        cin >>B[i];
    }

    for(int i=1; i<k;i++) {
        A[i] += A[i-1];
    }

    sort(A, A+k);
    sort(B, B+n);

    set<ll> res;

    for(int i=0; i<k; i++) {
        ll diff = B[0] - A[i];


        int ii = i;
        int jj = 0;

        bool good = true;
        while(true){
            if (A[ii] + diff == B[jj]) {
                ii++;
                jj++;
            }
            else if (A[ii] + diff < B[jj]) {
                ii++;
            }
            else {
                good = false;
                break;
            }

            if (jj==n) break;
            if (ii==k) {
                good = false;
                break;
            }

        }

        if (good) {
            res.insert(diff);
            //cerr << diff <<endl;
        }
    }

    cout << res.size() <<endl;
}
