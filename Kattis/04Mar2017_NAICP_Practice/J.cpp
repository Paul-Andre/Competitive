#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int current, correct;

    cin >> current;
    cin >> correct;

    int d = correct - current;

    if (d<=-180) {
        cout << (d+360) << '\n';
    }
    else if (d>180) {
        cout << d-360 << '\n';
    }
    else {
        cout << d <<'\n';
    }
    return 0;
}
