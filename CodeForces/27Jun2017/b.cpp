#define _USE_MATH_DEFINES
#include <math.h>

#include <bits/stdc++.h>

using namespace std;

int n;
double a;



int main() {
    cin >> n >> a;
    a = (a/180.)*M_PI;
    //cerr << a << endl;

    // TODO: if a is really small;


    vector<double> ang;
    for(int i=0; i<n+1; i++) {
        double C = M_PI*2/n*i;
        double r = asin( sin(C) / sqrt( 2 - 2*cos(C) ) );
        ///cerr << i << " " << r <<endl;
        ang.push_back(r);
    }

    for(int i=2; i<n; i++) {
        ///cout << (ang[i] - ang[i-1]) *180 /M_PI << endl;
    }

    double bestDiff = 1000000000000000.;
    double bestHave;
    int bestA = -1;
    int bestB = -1;


    for(int i=1; i<n; i++) {
        double got = ang[i];
        //cerr << "got " << got << endl;
        //cerr << "i " << i << endl;

        int l = 1;
        int r = n/2;
        while(l<r) {
            //cerr << l << " " << r << endl;
            int m = (l+r + 1 )/2;
            //cerr << m << " m\n";
            double res = ang[m] - got;
            //cerr << res << " res\n";
            if(res >= a) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }

        //cerr << l << " " << r << endl;


        for(int j =-10; j<=10; j++) {
            l = min(max(1, r+j), n-1);

            double have = ang[l] - got;
            double diff = abs(have - a);
            if( diff < bestDiff) {
                //cerr << have/M_PI*180 << " " << i << " " << l << " diff have i(bestA) l(bestB) \n";
                bestDiff = diff;
                bestHave = have;
                bestA = i;
                bestB = l;
            }
        }
    }

    assert(bestA != -1);

    if (bestA == bestB) {
        cout << "1 3 2\n";
        exit(0);
    }

    cout << bestA << " " << n << " " << bestB << endl;
    cerr.precision(20);
    cerr << bestHave /M_PI * 180;
}

