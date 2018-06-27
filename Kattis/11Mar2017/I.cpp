#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    double C;
    int L;
    cin >> C >> L;
    double tot = 0;
    while(L--) {
        double w, l;
        cin >> w >> l;
        tot += (w*l)*C;
    }

    printf("%.8f\n", tot);
}
