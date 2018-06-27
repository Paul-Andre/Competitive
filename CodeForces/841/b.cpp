#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    int t = 0;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        t += a;
        t %= 2;
        if (t) {
            cout << "First\n";
            exit(0);
        }
    }
    cout << "Second\n";
}


