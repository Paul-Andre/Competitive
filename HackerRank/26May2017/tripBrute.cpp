#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll,ll> pll;

ll W[200000];
ll G[200000];
ll P[200000];

class Seg {
    public:
    int a;
    int b;
    ll req;
    ll ret;

    Seg *left;
    Seg *right;

    Seg() {}

    Seg(int a_, int b_) {
        a = a_;
        b = b_;
        if ( a == b) {
            if (G[a] >= W[a]) {
                req = 0;
                ret = G[a]-W[a];
            }
            else {
                req = W[a] - G[a];
                ret = 0;
            }
        }
        else {
            int c = (a+b)/2;

            left = new Seg(a,c);
            right = new Seg(c+1,b);

            if (right->req >= left->ret) {
                req = left->req + right->req - left->ret;
                ret = right->ret;
            }
            else {
                req = left->req;
                ret = right->ret + left->ret - right->req;
            }
        }
    }

    pll query(int aa, int bb) {
        if (bb< a || aa> b) {
            return pll(0,0);
        }
        //cout << "aa bb " << aa << " " << bb << endl;
        //cout << "a b " << a << " " <<b << endl;
        if (aa<= a && bb>=b) {

            //cout << "wew\n";
            return pll(req, ret);
        }
        
        pll l = left->query(aa, bb);
        pll r = right->query(aa, bb);

        ll q, t;

        if (r.first >= l.second) {
            q = l.first + r.first - l.second;
            t = r.second;
        }
        else {
            q = l.first;
            t = r.second + l.second - r.first;
        }

        return pll(q,t);
    }

};

Seg seg;
pll Q[200000];
int reord[200000];

int n, q;

int sqrtN;

/*
bool ssort(int a, int b) {
    //true if A comes before B
    //
    pll A = Q[a];
    pll B = Q[b];

    int as = A.second / sqrtN;
    int bs = B.second / sqrtN;

    if (as!= bs) {
        return as > bs;
    }
    return A.first > B.first;
}


*/
int main() {
    cin >> n >> q;

    sqrtN = (int)(sqrt(n));

    for (int i=0; i<n-1; i++) {
        cin >> W[i];
    }
    for (int i=0; i<n; i++) {
        cin >> G[i] >> P[i];
    }

    seg = Seg(0, n-2);

    for (int ii=0; ii<q; ii++) {
        ll a;
        ll b;
        cin >> a >> b;
        a--;
        b--;

        if(a==b) {
            cout << 0 << endl;
        }
        else {
            ll payed = 0;
            ll gas = 0;
            int prev_best = P[a];
            int prev_best_i = a;
            for (int i=a+1; i<=b; i++) {
                if (P[i] < prev_best || i==b) {

                    pll q = seg.query(prev_best_i, i-1);

                    if (gas < q.first) {
                        ll needGas = q.first - gas;
                        gas += needGas;
                        payed += prev_best*needGas;
                    }

                    gas -= q.first;
                    gas += q.second;

                    prev_best = P[i];
                    prev_best_i = i;

                }
            }

            cout << payed << endl;
        }
    }
}
