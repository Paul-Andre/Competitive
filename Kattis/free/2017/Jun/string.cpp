#include <bits/stdc++.h>
using namespace std;


int AA[100];
int A[100];

int main() {
    int n;
    cin >> n;
    int par = 0;
    for(int i=0; i<n; i++) {
        cin >> AA[i];
        par += AA[i];
    }

    if (par%2) {
        cout << "no quotation\n";
        exit(0);
    }

    for(int k=100; k>=1; k--) {
        for(int i=0; i<n; i++) {
            A[i] =  AA[i];
        }

        int kk = k;
        int bi = 0;
        int ei = n-1;
        while(kk!=0 && bi<=ei) {
            if(A[bi] >= kk) {
                A[bi] -= kk;
            }
            else {
                goto continue_outer;
            }
            if(A[ei] >= kk) {
                A[ei] -= kk;
            }
            else {
                goto continue_outer;
            }
            if (A[bi] == 0) {
                bi++;
            }
            if (A[ei] == 0) {
                ei--;
            }
            kk --;
        }

        if(kk == 0) {
            if (k == 1 && par != 2) {
                cout << "no quotation\n";
                exit(0);
            }
            cout << k << '\n';
            exit(0);
        }


continue_outer:;
    }
}







