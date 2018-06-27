#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;


/*
int biggerThan(vector<long> &v, long m, int a, int b) {
    while (a!= b) {
        int c = (a+b)/2;
        if (v[c]>=long) {
            a = c+1;
            b = b;
        }
        else {
            a = a;
            b = c;
        }
    }
    return a;
}
*/

typedef unsigned long long ull;

ull fastExp(ull n, ull a) {
    ull cum = 1;
    while(a!=0) {
        //cout << "a " << a << "\n";
        if (a%2 == 0) {
            a/=2;
            n = (n*n) %MOD;
        }
        else {
            a-=1;
            cum *= n;
            cum %= MOD;
        }
    }
    return cum;
}

ull inv(ull n) {
    return fastExp(n, MOD-2);
}


ull choose(ull n, ull k) {
    ull top = 1;
    ull bot = 1;
    for (int i=0; i<k; i++) {
        top *= (n-i);
        top %= MOD;
        bot *= (i+1);
        bot %= MOD;
    }
    return (top * inv(bot)) %MOD;
}


vector < ull > solve(int n, int k, vector < ull > &v){
    ull res = 0;
    for (int i=62; i>=0; i--) {
        //cout << i << "... \n";
        vector<ull> w;
        ull ex = 1ULL<<i;
        //cout << ex << " ex\n";
        for (int j=0; j<v.size(); j++) {
            if (v[j] & ex) {
                w.push_back(v[j]);
            }
        }
        if (w.size() >= k) {
            res |= ex;
            v = w;
        }
    }

    vector<ull> ret;
    ret.push_back(res);
    ret.push_back(choose(v.size(), k));
    return ret;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<ull> a(n);
    for(int n_i = 0; n_i < n; n_i++){
       cin >> a[n_i];
    }
    vector < ull > result = solve(n, k, a);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != n - 1 ? "\n" : "");
    }
    cout << endl;
    return 0;
}
