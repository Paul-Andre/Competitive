#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int den = 0;
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        if (t==1) {
            if (a>0) a--;
            else if(b>0) {b--; a++;}
            else den ++;
        }
        else {
            if(b>0) {b--;}
            else den +=2;
        }
    }
    cout << den <<endl;
}

