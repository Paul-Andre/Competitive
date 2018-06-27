#include <bits/stdc++.h>

using namespace std;

int wA[1000001];
int wB[1000001];

int n;

int maximumGcdAndSum(vector <int> &A, vector <int> &B) {

    for(int i=0; i<n; i++) {
        wA[A[i]] = A[i];
        wB[B[i]] = B[i];
    }

    for(int i=1; i<=1000000; i++) {
        int res = wA[i];
        for(int j=i; j<=1000000; j+=i) {
            res = max(res, wA[j]);
        }
        wA[i] = res;
    }

    for(int i=1; i<=1000000; i++) {
        int res = wB[i];
        for(int j=i; j<=1000000; j+=i) {
            res = max(res, wB[j]);
        }
        wB[i] = res;
    }

    for(int i=1000000; i>=1; i--) {
        if (wA[i] != 0 && wB[i] != 0){
            cerr << i <<endl;
            cerr << wA[i] << ' ' <<wB[i] <<endl;
            return wA[i] + wB[i];
        }
    }

    return -1;
}

int main() {
    cin >> n;
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
       cin >> A[A_i];
    }
    vector<int> B(n);
    for(int B_i = 0; B_i < n; B_i++){
       cin >> B[B_i];
    }
    int res = maximumGcdAndSum(A, B);
    cout << res << endl;
    return 0;
}
