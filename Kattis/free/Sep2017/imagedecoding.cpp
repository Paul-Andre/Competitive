#include <bits/stdc++.h>
using namespace std;


int main() {
    bool non = false;
    while(true) {

        int n;
        cin >> n;
        if (n == 0) {
            //cerr << "Wew\n";
            
            return 0;
        }
        std::cin.ignore(100, '\n');
        if (non) cout <<endl;
        non = true;


        int prev = -1;

        bool error = false;

        for(int i=0; i<n ;i++) {
            string s;
            getline(cin, s);

            stringstream ss(s);
            char c;
            ss >> c;

            int k;
            int tot =0;


            while(ss >> k) {
                tot += k;
                for(int j=0; j<k; j++) {
                    cout << c;
                }
                if (c == '#') c = '.';
                else c = '#';
            }

            cout << endl;

            if (prev != -1 && tot != prev) error = true;

            prev = tot;
        }

        if (error) cout << "Error decoding image\n";
    }
}

