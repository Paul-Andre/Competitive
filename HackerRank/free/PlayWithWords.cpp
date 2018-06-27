#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

int main() {
    string s;
    cin >> s;

    // 
    vector<vector<int> > t(s.size(), vector<int>(s.size()));

    for (int i=0; i<s.size(); i++) {
        t[i][i] = 1;
    }
    for (int i=1; i<s.size(); i++) {
        t[i-1][i] = int(s[i-1] == s[i])+1;
    }

    for (int size=2; size<s.size(); size++) {
        for (int i = 0; i+size<s.size(); i++) {
            t[i][i+size] = max(t[i+1][i+size], max (t[i][i-1+size], t[i+1][i-1+size]+2*int(s[i]==s[i+size])));
        }
    }

    /*
    for (int i = 0; i<s.size(); i++) {
        for (int j=0; j<s.size(); j++) {
            cout << t[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    int max = 0;
    for (int i=0; i<s.size()-1; i++) {
        int aa = t[0][i]*t[i+1][s.size()-1];
        if (aa> max) {
            max = aa;
        }
    }

    cout << max << '\n';
}
