#include <bits/stdc++.h>
using namespace std;

int palin(string s,int m) {
    int j=s.size()-1;
    int count = 0;
    for (int i=m; i<m+(s.size()-m)/2; i++, j--) {
        count+= int(s[i]!=s[j]);
    }
    return count;
}

int main(){
    string s;
    cin >> s;

    int m = 100000000;
    for (int i=0; i<s.size(); i++) {
        int mm = palin(s,i);
        //cout << mm << '\n';
        m = min (m, mm+i);
    }
   cout << m << '\n';
}
