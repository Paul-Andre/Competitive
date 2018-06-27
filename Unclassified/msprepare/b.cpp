#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    cout <<n <<endl;
    for(int i=0; i<n ;i++) {
        string s;
        cin>>s;
        s.push_back(0);
        char prev = s[0];
        int cnt = 1;
        for(int j=1; j<s.size(); j++) {
            char cur = s[j];
            if (cur != prev) {
                if (cnt == 1) {
                    cout << prev;
                }
                else {
                    cout << cnt << prev;
                }
                prev = cur;
                cnt = 1;
            }
            else {cnt ++;}
        }
        cout << endl;
    }
}


