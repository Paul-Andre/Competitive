#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ll n, p;
    cin >> n >> p;

    ll m = ((1+n-p)/(p-1))+1;

    double calc = double(m*p) / (double) (m+n-p+1);

    for (int i = 0; i<=p-2; i++) {
        //cout << " adsfasd " << i <<'\n';
        calc *= double(n-p+2+i)/double(m+n-p+2+i);
    }

    //cout << m <<'\n';
    printf("%.11f\n", calc);

}
