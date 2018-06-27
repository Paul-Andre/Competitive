#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;


int main() {
    int d;
    cin >> d;

    ll money = 100;
    ll stocks = 0;

    ll prev;
    bool up = false;

    cin >> prev;

    for (int i=1; i<d; i++) {
        ll price;
        cin >> price;

        if (!up) {
            if (price>prev) {
                ll bought = min(100000-stocks, money/prev);
                money -= bought*prev;
                stocks += bought;
                up = true;
                //cout << "bought " << bought << " for " << prev << '\n';
            }
        }
        else {
            if (price<prev) {
                //cout << "sold " << stocks << " for " << prev << '\n';
                money += stocks*prev;
                stocks = 0;
                up = false;
            }
        }
        prev = price;
    }
    //cout << "sold " << stocks << " for " << prev << '\n';
    money += stocks*prev;
    cout << money << '\n';

}
