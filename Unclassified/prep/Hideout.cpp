//https://www.cs.rit.edu/~icpc/questions/2016/NENA_Final_2016.pdf

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Frac {
    ll num;
    ll denom; //denom isn't negative (but might be 0 to represent inf
    Frac(ll a, ll b) {
        num = a;
        denom = b;
    }
};

bool operator== (Frac a, Frac b) {
    return a.num*b.denom == b.num*a.denom;
}

bool operator< (Frac a, Frac b) {
    return a.num*b.denom < b.num*a.denom;
}

Frac operator* (Frac a, Frac b) {
    return Frac(a.num * b.num, a.denom* b.denom);

}
        

map<Frac, string> m;

int main() {
    m[Frac(10, 5)] = "yes";
    m[Frac(2, 1)] = "no";

    cout << m[Frac(4,2)] <<endl;
}

