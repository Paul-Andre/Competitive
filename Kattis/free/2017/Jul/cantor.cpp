#include <bits/stdc++.h>
using namespace std;

#define mil 1000000



int main() {
    while(true) {
        string s;
        cin >> s;
        if (s == "END") return 0;

        stringstream ss(s);
        double fn;
        ss >> fn;

        //cout << fn << endl;

        int n;
        n = round(fn*mil);
        //cout << n << endl;

        set<int> prevSeen;


        for(int i=0; i<100000; i++) {

            if(prevSeen.find(n) != prevSeen.end()) {
                cout << "MEMBER";
                break;
            }
            prevSeen.insert(n);

            int r = n%mil;
            int q = n/mil;

            int nm;

            if (q == 1) {
                q = 0;
                r = n;
            }

            if (q == 3) {
                q = 2;
                r = n - 2*mil;
            }

            nm = r*3;

            //cout << q;
            
            if (q > 2 ) {
                cout << "NON-MEMBER";
                break;
            }


            n = nm;
        }
        cout<<endl;
    }
}



