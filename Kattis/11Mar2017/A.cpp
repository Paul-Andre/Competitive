#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int B;
    cin >> B;
    vector<double> s(B);
    vector<double> p(B+1);
    for(int i=0; i<B; i++) {
        cin >> s[i] >> p[i];
    }
    cin >> p[B];

    double income[B+1];
    double kept[B+1];
    income[0] = kept[0] = 0;

    income[1] = s[0];
    kept[1] = s[0]*(1-p[0]*0.01);

    for (int i = 1; i<B; i++) {
        income[i+1] = income[i] + s[i];
        kept[i+1] = kept[i] + s[i]*(1-p[i]*0.01);
        //cout << " adf "<< s[i]*(1-p[i]*0.01)<<'\n';
    }

    /*
    for (int i = 0; i<B+1; i++) {
        cout << "income: " << income[i] << "  kept: " << kept[i] << '\n';
    }
    */

    int F;
    cin >> F;
    //cout << "\n\n" ;

    for (int iii=0; iii<F; iii++) {
        double e, m;
        cin >> e >> m;

        int i=0;
        while (i+1<B+1 && income[i+1] <= e) {
            i++;
        }

        //cout << "i " << i << '\n';

        double target = kept[i] + (e-income[i])*(1-p[i]*0.01) + m;
        //cout << "target " << target <<'\n';
        int j=0;

        while (j+1<B+1 && kept[j+1] <= target) {
            j++;
        }
        //cout << "j " << j <<'\n';

        double res = income[j] + (target-kept[j])/(1-p[j]*0.01) - e;
        //cout << res <<'\n';
        printf("%.7f\n", res);
    }
}
