//#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    // your code goes here
    vector<long> tn(s.size());
    vector<vector<long> > td(3,vector<long> (s.size()));

    td[0][0] = td[1][0] = td[2][0] = 0;
    if (s[0] != '0') {
        td[(s[0]-'0')%3][0] = 1;
    }
    if (s[0] == '0' || s[0] == '6') {
        tn[0] = 1;
    }
    for (int i=1; i<s.size(); i++) {
        int v = s[i] - '0';
        for (int j=0;  j<3; j++) {
            td[(j+v)%3][i] = td[j][i-1];
        }
        if (s[i] != '0') {
            td[(v)%3][i] ++;
        }
        tn[i] = tn[i-1];
        if ((v%2)==0) {
            tn[i] += td[0][i];
        }
        if (v==0) {
            tn[i]++;
        }
    }
        
    cout << tn[s.size()-1]<< '\n';

    return 0;
}

