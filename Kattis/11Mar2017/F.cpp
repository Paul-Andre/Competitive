#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> c(10);
    for(int i=0; i<s.size(); i++) {
        c[s[i]-'0'] ++;
    }

    for(int i=0; i<1000; i++) {
        for (int j=1; j<=9; j++) {
            if (c[j]==i) {
                for (int k=0; k<i+1; k++) {
                    cout << j;
                }
                cout <<'\n';
                return 0;
            }
        }
        if (c[0]==i) {
            cout << 1;
            for (int k=0; k<i+1; k++) {
                cout << 0;
            }
            cout <<'\n';
            return 0;
        }
    }
}
