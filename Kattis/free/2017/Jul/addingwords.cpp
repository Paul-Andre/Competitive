#include <bits/stdc++.h>
using namespace std;


int main() {

    map<string, int> sti;
    map<int, string> its;

    string instr;
    while(cin >> instr) {
        if (instr == "clear") {
            sti.clear();
            its.clear();
        }
        else if ( instr == "def") {
            string w;
            cin >>w;
            int n;
            cin >>n;
            if ( sti.find(w) != sti.end()) {
                its.erase(sti[w]);
            }
            sti[w] = n;
            its[n] = w;
        }
        else if ( instr == "calc") {
            char ops[20];
            string words[20];

            string f;
            cin >>f;


            int n = 0;
            for(int i=0; true; i++) {

                char op;
                cin >>op;

                string f;

                if ( op == '=') break;
                ops[i] = op;
                cin >>f;
                words[i] = f;
                n ++;
            }

            int tot = 0;

            bool known = true;

            if (sti.find(f) == sti.end()) {
                known = false;
                goto end;
            }

            tot += sti[f];

            

            for (int i=0; i<n; i++) {
                if (sti.find(words[i]) == sti.end()) {
                    known = false;
                    goto end;
                }
                else if (ops[i] == '+') {
                    tot += sti[words[i]];
                }
                else if (ops[i] == '-') {
                    tot -= sti[words[i]];
                }

            }

            if (its.find(tot) == its.end()) {
                known = false;
                goto end;
            }


end:
            cout << f <<" ";
            for(int i=0; i<n; i++) {
                cout << ops[i] << " " <<words[i] << " ";
            }
            cout << "= ";
            if ( !known) {
                cout << "unknown";
            }
            else cout << its[tot];
            cout <<endl;
        }
    }
}






