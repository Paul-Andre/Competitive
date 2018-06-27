#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[100000];

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int a1 = a[0];
    int a2 = a[1];
    int a3 = a[2];

    ll a3count = 0;
    for (int i=0; i<n; i++) {
        a3count += (a[i] == a3);
    }

    if (a2 != a3) {
        cout << a3count << endl;
    }
    else if (a1 != a3) {
        cout << (a3count * (a3count-1))/2 << endl;
    }
    else {
        cout << (a3count * (a3count-1) * (a3count-2))/6 << endl;
    }
    
}


