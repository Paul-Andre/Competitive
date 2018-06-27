#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;

    int rank = 25;
    int stars = 0;
    int conseq = 0;

    int spr[] = {
        0, 5,5,5,5,5,5,5,5,5,5,
        4,4,4,4,4,
        3,3,3,3,3,
        2,2,2,2,2};


    /*
    cout << "adfa ";
    cout << sizeof(spr) / sizeof(int) <<'\n';
    */

    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'W') {
            conseq++;
            if (rank>=6 && conseq>=3) {
                stars+=2;
            }
            else {
                stars+=1;
            }
            if (stars>spr[rank]) {
                stars -= spr[rank];
                rank--;
                if (rank==0) {
                    cout << "Legend\n";
                    return 0;
                }
            }
        }
        else {
            conseq = 0;
            if (rank<=20) {
                if (stars==0 && rank!=20) {
                    rank++;
                    stars = spr[rank]-1;
                }
                else if (stars!=0) {
                    stars--;
                }
            }
        }
    }
    cout << rank <<'\n';
    return 0;

}
