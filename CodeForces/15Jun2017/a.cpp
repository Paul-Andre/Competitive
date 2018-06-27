#include <bits/stdc++.h>
using namespace std;


int main() {
    int x1, y1, x2, y2;
    int x,y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

    x2 -= x1;
    y2 -= y1;


    if ( x2 % x == 0 && y2 % y == 0 && ((x2/x)%2+2)%2 == ((y2/y)%2+2)%2 ) {
            cout << "YES\n";
            exit(0);
    }
            cout << "NO\n";
}


