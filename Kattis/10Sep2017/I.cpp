#include <bits/stdc++.h>
using namespace std;


#define SQR(x) ((x)*(x))


int main() {
    double a[4];
    double b[4];
    while(cin>> a[0] >> a[1] >> a[2] >> a[3] >> b[0] >> b[1] >> b[2] >> b[3]) {
        double c[4];
        for(int i=0; i<4; i++) {
            c[i] = b[i] - a[i];
        }

        double d[3];
        for(int i=0; i<3; i++) {
            d[i] = c[i+1] * (i+1);
        }

        vector<double> pts = {0, 1};

        double delta = d[1]*d[1] - 4*d[2]*d[0];
        if (delta >= 0) {
            double p[2];
            p[0] = 0.5*(-sqrt(delta) -d[1])/d[2];
            p[1] = 0.5*(sqrt(delta) -d[1])/d[2];
            for(int i=0; i<2; i++) {
                if (p[i] <= 1 && p[i] >= 0) {
                    pts.push_back(p[i]);
                }
            }
        }

        double minval = numeric_limits<double>::infinity();
        double maxval = -numeric_limits<double>::infinity();

        for(int i=0; i<pts.size(); i++) {
            double p = pts[i];
            double val = c[0] + c[1]*p + c[2]*p*p + c[3]*p*p*p;
            if ( val < minval) {
                minval = val;
            }
            if ( val > maxval) {
                maxval = val;
            }
        }

        cout.precision(12);

        cout << maxval - minval <<endl;
    }

}



    


