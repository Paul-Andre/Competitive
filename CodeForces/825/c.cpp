#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
ll A[1000];

int main() {
    cin >> n>>k;
    for(int i=0; i<n;i++) {
        cin >>A[i];
    }


    sort(A, A+n);


    ll tot = 0;
    int i = 0;

    while(i<n) {
        if (2*k >= A[i]) {
            k = max(k, A[i]);
            i++;
        }
        else {
            tot ++;
            k*=2;
        }
    }

    cout << tot <<endl;
}
