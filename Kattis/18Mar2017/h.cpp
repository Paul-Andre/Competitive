#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int llog10(int i){
    int c = -1;
    while(i!=0){
        i/=10;
        c++;
    }
    return c;
}

int makeNumber(string &s, int beg, int len) {
    int res = 0;
    int pow = 1;
    for(int i=0; i<len; i++) {
        res+=pow*(s[beg+i]-'0');
        pow*=10;
    }
    return res;
}

void writeNumber(string &s, int beg, int len, int num) {
    for(int i=0; i<len; i++) {
        s[beg+i] = '0' + num%10;
        num /= 10;
    }
}

int main(){
    //string asdf = "0010";
    //cout << makeNumber(asdf, 1, 2) << '\n';

    string s;
    cin >> s;

    int l = s.size();

    if (s=="0") {
        cout << "0" << '\n';
        return 0;
    }

    int a = 0;
    int b = 10000000;

    while(true){
        int c = (a+b)/2;
        int v = llog10(c+1)+c+1;
        if (v == l){
            a = b = c;
            break;
        }
        else if(v<l){
            a = c;
        }
        else {
            b = c;
        }
    }

    a++;
    b++;

    //cout << a << '\n';

    int ls = llog10(a)+1;


    reverse(s.begin(), s.end());

    s.push_back('0');


    for (int iii=0; iii<4; iii++) {
        a = b-iii;
        string ret= "";
        string ss = s;

        bool trailing = true;
        for(int i = ss.size()-1-ls; i>=0; i--) {
            //cout << ss << " , " << ret << '\n'; 

            int n= makeNumber(ss, i, ls+1);
            //cout << n << "\n";

            int mult = -1;
            for (int j=9; j>=0; j--) {
                if (a*j<=n) {
                    mult = j;
                    break;
                }
            }
            writeNumber(ss, i, ls+1, n-a*mult);
            //cout << mult << '\n';
            if (!trailing || mult!=0) {
                ret.push_back('0'+mult);
                trailing = false;
            }
        }
        if ( makeNumber(ss, 0, ls+1) !=0 || ret.size() != a) {
                //cout << "XXSXXXXXXXXXXXXXXXXXXX\n";
            continue;
        }
        else {
            for (int i=0; i<ret.size(); i++) {
                cout << ret[i];
            }
            cout << '\n';
            return 0;
        }
    }
    cout << "THis shouldn't happen\n";
}

