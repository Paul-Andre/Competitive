#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s;

    cin >> s;
    int c = 0;


    while(true) {
        bool changed = false;
        for (int i=2; i<s.size(); i++) {
            if (s[i]=='C' && s[i-1]=='C' && s[i-2]=='P') {
                s[i]='P';
                s[i-2]='C';
                c++;
                changed = true;
                break;
            }
            else if (s[i]=='C' && s[i-1]=='P' && s[i-2]=='P') {
                s[i]='P';
                s[i-2]='C';
                c++;
                changed = true;
                break;
            }
        }
        //cout << s << '\n';
        changed == false;
        if (!changed) {
            for (int i=2; i<s.size(); i++) {
                if (s[i]=='C' && s[i-1]=='P' && s[i-2]=='C') {
                    s[i]='P';
                    s[i-1]='C';
                    c++;
                changed = true;
                    break;
                }
                else if (s[i]=='P' && s[i-1]=='C' && s[i-2]=='P') {
                    s[i-1]='P';
                    s[i-2]='C';
                    c++;
                changed = true;
                    break;
                }
            }
        }
        //cout << s << '\n';
        if (!changed) break;
    }

    cout << c << '\n';
}

