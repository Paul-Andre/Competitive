#include <bits/stdc++.h>
using namespace std;

int m, start, x;


int betterRand() {
    return rand()*RAND_MAX + rand();
}


int main() {
    srand(time(nullptr) + 29222);
    cin>>m>>start>>x;

    int ii = -1;
    int vv = -1;
    int nn = -1;
    for(int i=0; i<999 && i<m; i++) {
        int get = (betterRand()%m+m)%m + 1;
        assert(get >= 1 && get <= m);

        cout << "? " << get << endl;
        fflush(stdout);
        int v, n;
        cin >>v>>n;
        if (v == x) {
            cout << "! " << x << endl;
            fflush(stdout);
            return 0;
        }

        if (v < x && v > vv) {
            vv = v;
            ii = get;
            nn = n;
        }
    }

    if (ii == -1) {
        cout << "? " << start << endl;
        fflush(stdout);
        int v, n;
        cin >>v>>n;
        ii = start;
        vv = v;
        nn= n;
    }

    while(true) {
        if (vv >= x) {
            cout << "! " << vv << endl;
            fflush(stdout);
            return 0;
        }

        ii = nn;
        if (ii == -1) break;
        cout << "? " << ii << endl;
        fflush(stdout);
        cin >>vv>>nn;
    }

    cout << "! -1"<<endl;
    fflush(stdout);
}
