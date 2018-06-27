#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 4096*4096;
    vector<int> a(N);
    for (int i=0; i<N; i++) {
        a[i] = rand();
    }
    cout << "Starting sorting\n";
    sort(a.begin(), a.end());
    cout << "Ended sorting\n";
}

