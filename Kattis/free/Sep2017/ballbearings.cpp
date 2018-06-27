#define _USE_MATH_DEFINES
#include <math.h>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;cin>>n;

    for(int iii=0; iii<n; iii++) {
        double D,d,s;
        cin>>D>>d>>s;
        double r = (D-d)/2;
        double p = (d+s)/2;
        double ang = asin(p/r);
        double wew = M_PI/ang;
        //cerr.precision(12);
        //cerr << wew <<endl;
        wew += 1e-7;
        int ret = floor(wew);
        cout << ret <<endl;
    }
}


