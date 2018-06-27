//Mo's algorithm y'all
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
        ////cerr << "aa bb " << aa << " " << bb << endl;
        ////cerr << "a b " << a << " " <<b << endl;
        if (aa<= a && bb>=b) {

            //cerr << "wew\n";
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


bool check(int a, int b, ll payy, ll gass, int topp, deque<int> &dq) {
    b++;
    ll payed = 0;
    ll gas = 0;
    vector<int> minns;

    int prev_best = P[a];
    int prev_best_i = a;
    //minns.push_back(a);

    for (int i=a+1; i<=b; i++) {
        if (P[i] < prev_best || i==b) {

            bool used = false;
            for (int j=prev_best_i; j<i; j++) {
                gas += G[j];
                if (gas < W[j]) {
                    ll needGas = W[j]-gas;
                    gas += needGas;
                    payed += prev_best*needGas;
                    used = true;
                }
                gas -= W[j];
            }
            if (used) {

                    minns.push_back(prev_best_i);
            }

            prev_best = P[i];
            prev_best_i = i;


        }
    }
    cerr << "a b: " << a << " " << (b-1) << endl;
    cerr << "Payed: " << payy << endl;
    cerr << "Gas: " << gass << endl;
    cerr << "ToppestLow: " << topp << endl;
    cerr << "Deque: ";
    for (int i=0; i<dq.size(); i++) {
        cerr << dq[i] << " ";
    }

    cerr << endl;

    bool ret = payed == payy && gas == gass
        && topp>=a && topp<b;

    if (!ret) {
        cerr << "Brute Payed: " << payed << endl;
        cerr << "Brute Gas: " << gas << endl;
        cerr << "Brute Deque: ";
        for (int i=0; i<minns.size(); i++) {
            cerr << minns[i] << " ";
        }
        cerr << endl;
    }

    return ret;
}


pll Q[200000];
int reord[200000];
ll ans[200000];

int n, q;

int sqrtN;

pll getSome(int a) {
    ll req, ret;
    if (G[a] >= W[a]) {
        req = 0;
        ret = G[a]-W[a];
    }
    else {
        req = W[a] - G[a];
        ret = 0;
    }
    return pll(req, ret);
}

pll join(pll l, pll r) {
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



bool ssort(int a, int b) {
    //true if A comes before B
    //
    pll A = Q[a];
    pll B = Q[b];

    int as = (A.second-1) / sqrtN;
    int bs = (B.second-1) / sqrtN;

    if (as!= bs) {
        return as > bs;
    }
    return A.first > B.first;
}


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

    for (int i=0; i<q; i++) {
        ll a;
        ll b;
        cin >> a >> b;
        a--;
        b--;
        /*
        pll q = seg.query(a,b);
        cerr << q.first << " " << q.second << endl;
        */
        Q[i] = pll(a,b);
        reord[i] = i;

        if ( b-a <= sqrtN + 2) {
            ll payed = 0;
            ll gas = 0;
            vector<int> minns;

            int prev_best = P[a];
            int prev_best_i = a;
            //minns.push_back(a);

            for (int i=a+1; i<=b; i++) {
                if (P[i] < prev_best || i==b) {

                    bool used = false;
                    for (int j=prev_best_i; j<i; j++) {
                        gas += G[j];
                        if (gas < W[j]) {
                            ll needGas = W[j]-gas;
                            gas += needGas;
                            payed += prev_best*needGas;
                            used = true;
                        }
                        gas -= W[j];
                    }
                    if (used) {

                        minns.push_back(prev_best_i);
                    }

                    prev_best = P[i];
                    prev_best_i = i;


                }
            }

            ans[i] = payed;
        }
        else {
            ans[i] = -1;
        }
    }


    sort(reord, reord+q, ssort);

    int prevSec = -1000;

    deque<int> dq;

    int a, b;
    ll payed;
    ll gas;
    int toppestLow;

    for (int ii = 0; ii<q; ii++) {

        pll query = Q[reord[ii]];
        ll aa = query.first;
        ll bb = query.second;

        if (ans[reord[ii]] != -1) {
            continue;
        }

        if (aa == bb) {
            ans[reord[ii]] = 0;
            continue;
        }


        bb-=1;

        

        cerr << "aa bb " << aa << " " << bb << "=======================" << endl;

        int sec = bb / sqrtN;

        if ( sec != prevSec) {
            cerr << "new secc !!!!!!!!!!!\n";
            a = b = sec * sqrtN;
            dq = deque<int>();

            pll q  = getSome(a);
            payed = q.first*P[a];
            gas = q.second;

            if ( q.first != 0) {
                dq.push_back(a);
            }

            toppestLow = a;
            prevSec = sec;
            assert(check(a,b, payed, gas,toppestLow, dq));
        }

        {
            int b = sec*sqrtN;
            int bb = b;

            while(a>aa) {
                cerr << "a <<\n";
                a--;

                int end = b;
                if (!dq.empty()) {

                    if ( dq.front() != a+1) {
                        dq.push_front(a+1);
                    }


                    ll hasPayed = 0;
                    ll hadGas = 0;
                    int prev_best = P[a+1];
                    int prev_best_i = a+1;


                    while(prev_best >= P[a] && prev_best_i != b+1) {
                        ////cerr << "Removing the unneeded\n";
                        //cerr << "dq size " << dq.size() << endl;
                        dq.pop_front();

                        int i;

                        if (!dq.empty()) {
                            i = dq.front();
                        }
                        else if (dq.empty()) {
                            i = b+1;
                        }

                        pll q = seg.query(prev_best_i, i-1);

                        if (hadGas < q.first) {
                            ll needGas = q.first - hadGas;
                            hadGas += needGas;
                            hasPayed += prev_best*needGas;
                        }

                        hadGas -= q.first;
                        hadGas += q.second;

                        prev_best = P[i];
                        prev_best_i = i;
                    }


                    //cerr << "substracting " << hasPayed << endl;
                    payed -= hasPayed;

                    while(true) {

                        if (!dq.empty() && dq.front() != a+1) {
                            //cerr << "Making sure removing what was reused\n";
                            int i = dq.front();
                            int j;
                            if (dq.size()>1) {
                                dq.pop_front();
                                j = dq.front();
                                dq.push_front(i);
                            }
                            else {
                                j = b+1;
                            }

                            pll q = seg.query(i, j-1);
                            //cerr << "hadGas = " << hadGas << endl;
                            assert(q.first > hadGas);

                            payed += hadGas*P[i];
                        }


                        pll q = seg.query(a, prev_best_i - 1);

                        if ( dq.empty() ) {
                            //cerr << "dq.empty add " << q.first*P[a] << endl;
                            payed += q.first*P[a];
                            end = prev_best_i - 1;
                            gas = q.second;
                            break;
                        }

                        else {
                            int i = dq.front();
                            assert(i==prev_best_i);
                            int j;
                            if (dq.size()> 1) {
                                dq.pop_front();
                                j = dq.front();
                                dq.push_front(i);
                            }
                            else {
                                j = b+1;
                            }

                            pll qq = seg.query(i, j-1);


                            //cerr << "i j " << i << " " << j << endl;
                            //cerr << "q " << q.first << " " << q.second << endl;
                            //cerr << "qq " << qq.first << " " << qq.second << endl;

                            if (qq.first <= q.second) {
                                dq.pop_front();
                                prev_best_i = j;
                                //cerr << "Removing what would be freeby\n";
                                payed -= qq.first*P[i];
                                hadGas = qq.second;

                            }
                            else {
                                //cerr << "dq.not empty sub " << -(q.second-qq.first)*P[i]<< endl;
                                //cerr << "dq.not empy add " << q.first*P[a] << endl;

                                payed -= (q.second) * P[i];
                                payed += q.first*P[a];
                                end = prev_best_i - 1;
                                break;
                            }
                        }
                    }
                }
                else {  // dq empty
                    pll q = seg.query(a, b);
                    payed = q.first*P[a];

                    gas = q.second;
                }



                pll q = seg.query(a, end);

                if (P[toppestLow] >= P[a]) {
                    toppestLow = a;
                }

                if (q.first != 0) {
                    dq.push_front(a);
                }

                assert(check(a, b, payed, gas,toppestLow, dq));
            }
        }

        {
            assert(check(a,b, payed, gas, toppestLow, dq));
            int _toppestLow = toppestLow;
            int toppestLow = _toppestLow;

            int b = sec*sqrtN;

            ll _gas = gas;
            ll gas = _gas;
            ll _payed = payed;
            ll payed = _payed;

            while(b<bb) {
                //cerr << "b >>\n";
                b++;

                cerr << W[b-1] << " " << G[b-1] << " " << P[b-1] << " prev w g b\n";
                cerr << W[b] << " " << G[b] << " " << P[b] << " w g b\n";

                gas += G[b];

                if (P[b] < P[toppestLow]) {
                    //cerr << "wheert?\n";
                    toppestLow = b;
                }

                if (gas < W[b]) {
                    ll needGas = W[b]-gas;
                    gas += needGas;
                    payed += P[toppestLow]*needGas;
                }

                gas -= W[b];
                assert(check(a,b, payed, gas, toppestLow, dq));
            }

        ans[reord[ii]] = payed;

        }

    }

    for (int i=0; i< q; i++) {
        cout << ans[i] << endl;
    }
}


