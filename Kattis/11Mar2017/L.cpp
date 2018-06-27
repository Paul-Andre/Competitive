#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    long N;
    cin >> N;

    if (N>1000) {
        N=1000;
    }

    double res = 0;
    double p = -1;
    for (int i=1; i<=N; i++) {
        p /= -i;
        res+= p;
    }

    printf("%.8f\n",res);
}
