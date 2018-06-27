#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--) {
        double Rf, Bf, Mf;
        cin >> Rf >> Bf >> Mf;
        long R, B, M;
        R = round(Rf*100);
        B = round(Bf*100);
        M = round(Mf*100);
        //cout << R << " " << B << " " << M << '\n';

        int i;
        for (i=1; i<=1200; i++) {
            long inter = ((10000+R)*B + 5000)/10000;
            //cout << "i inter "<< i << " " << inter << "\n";
            long intt = inter - M;
            if (intt <= 0) break;
            if (intt > 10000000000) {
                i = 1201; break;
            }
            B = intt;
        }
        if (i==1201) {
            cout << "impossible\n";
        }
        else {
            cout << i << '\n';
        }
    }
}

