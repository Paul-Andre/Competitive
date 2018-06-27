#include <bits/stdc++.h>
using namespace std;


int n, A;
int C[100000];
int cnt[1000001];
int passed[1000001];

int main() {
    cin >> n >> A;
    for(int i=0; i<n; i++) {
        cin >> C[i];
    }

    int j = prevStop;
    for(int i=0; i<n; i++) {
        int c = C[i];
        if (c == A) {
            cnt[A] ++;
        }
        for(int j=prevStop; j<i; j++) {
            int d = C[j];
            if(passed[d] == prevStop) {
                cnd[d] ++;
    }



