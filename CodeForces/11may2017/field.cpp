#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a,b,h,w,n;
vector<ll> exps;

#define oo 1000000

bool rev(ll a, ll b){
    return a>b ;
}

ll proc(ll ptr, ll h, ll w) {
    if (h>=a && w>=b) return ptr;
    if (ptr>=exps.size()) return oo;
    if (ptr<22) {
        ll x1 = proc(ptr+1, h*exps[ptr], w);
        ll x2 = proc(ptr+1, h, w*exps[ptr]);
        return min(x1, x2);
    }
    else {
        while (ptr<exps.size() && h<a) {
            h*=2;
            ptr++;
        }
        while (ptr<exps.size() && w<b) {
            w*=2;
            ptr++;
        }
        if (h>=a && w>=b) return ptr;
        return oo;
    }
}


int main(){
    cin >> a >> b >> h >> w>>n;
    for (ll i=0; i<n; i++) {
        ll x;
        cin >>x;
        exps.push_back(x);
    }

    sort(exps.begin(), exps.end(), rev);

    ll p = min(proc(0, h, w), proc(0, w, h));

    if (p==oo)
        p=-1;

    cout << p << '\n';
}
