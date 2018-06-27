#include <bits/stdc++.h>
using namespace std;

#define SQR(x) ((x)*(x))

int main() {

    string s;
    while(getline(cin, s)) {
        for(int i=0; i<s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        //cerr << s << endl;
        size_t out = s.find("problem");
        if (out != string::npos) {
            cout << "yes\n";
        }
        else 
            cout << "no\n";
    }

}



    


