#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

double fastExp(double a, int p) {
    if (n%2==0) {
        double aa = fastExp(a, p/2);
        return aa*aa;
    }
    else {
        return a*fastExp(a, p);
    }
}

int main(){
    int n, s, k;

    //cin >> n >> s >> k;

    vector<double> e(k);

    e[0] = 0;

    for (int i=1; i<k; i++) {
        double a = fastExp((double(i))/s, n);

        double a = 1;


        for (int j=0; j<i; j++) {
            e[j] *= double(i)/(j+1);
            a -= e[j];
        }



        
}

