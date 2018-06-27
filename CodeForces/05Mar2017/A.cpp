#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<bool> onTable(n,false);
    int maxx = 0;
    int current =0;
    for(int i=0; i<2*n; i++) {
        int j;
        cin>> j;
        if (onTable[j]) {
            current--;
            onTable[j]=false;
        }
        else {
            current++;
            onTable[j]=true;
        }
        maxx = max(maxx, current);
    }
    cout << maxx <<'\n';

    return 0;
}
