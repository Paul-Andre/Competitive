#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >>n;
    vector<pii> xv(n);

    for(int i=0; i<n; i++) {
        cin >> xv[i].first;
    }

    for(int i=0; i<n; i++) {
        cin >> xv[i].second;
    }

    double a=1;
    double b=1000000000;

    double maxx = 0;

    for(int i=0; i<200; i++){
        //cout << i<< "\n";

        double c = (a+b)/2;
        maxx = 0;
        int maxj = -1;
        for (int j=0; j<n; j++) {
            double f = fabs(xv[j].first - c);
            double ev = f/xv[j].second;
            //cout << j<< " " << ev <<" " << f <<'\n';
            if (ev>maxx) {
                maxx = ev;
                maxj = j;
            }
        }

        if (c>xv[maxj].first) {
            b = c;
        }
        else {
            a = c;
        }
    }

    printf("%.11f\n",maxx);

    return 0;
}
