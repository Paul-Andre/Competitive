#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void d(int n) {
    //cout << "n is " << n << "      asdfadfas\n";
    if (n<=3) {
        cout << "ST X\n";
        cout << "PH X\n";
        cout << "PH X\n";
        cout << "AD\n";
        cout << "PL Y\n";
        if (n==1) {
            cout << "PH X\n";
        }
        else if (n==2) {
            cout << "PH Y\n";
        }
        else if (n==3) {
            cout << "PH X\n";
            cout << "PH Y\n";
            cout << "AD\n";
        }
    }
    else {
        d(n/3);
        cout << "PL A\n";
        cout << "PH A\n";
        cout << "PH A\n";
        cout << "PH A\n";
        cout << "AD\n";
        cout << "AD\n";
        if (n%3==1) {
            cout << "PH X\n";
            cout << "AD\n";
        }
        if (n%3==2) {
            cout << "PH Y\n";
            cout << "AD\n";
        }
    }
}

int main() {
    int N;
    cin >> N;
    if (N==0) {
        cout << "ZE A\n";
        cout << "DI A\n";
    }

    d(N);
    cout << "PL A\n";
    cout << "DI A\n";
}
