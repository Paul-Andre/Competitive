#include <bits/stdc++.h>
using namespace std;

#define SQR(x) ((x)*(x))

int main() {
    vector<int> all;
    int m = -100;
    string s;
    while(getline(cin, s)) {
        if (s.size() == 0) break;
        all.push_back(s.size());
        m = max(m, (int) (s.size()));
    }

    int tot = 0;
    for(int i=0; i<all.size()-1; i++) {
        tot += SQR(all[i] - m);
    }
    cout <<tot <<endl;
}



    


