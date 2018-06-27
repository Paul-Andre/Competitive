
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll,ll> pll;

ll W[200000];
ll G[200000];
ll P[200000];




bool check(int a, int b, ll payy, ll gass, int topp, deque<int> &dq) {
    return true;
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
    deque<pll> dqSeg;

    int a, b;
    ll payed;
    ll gas;
    int toppestLow;

    pll globist;

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

        

        //cerr << "aa bb " << aa << " " << bb << "=======================" << endl;

        int sec = bb / sqrtN;

        if ( sec != prevSec) {
            //cerr << "new secc !!!!!!!!!!!\n";
            a = b = sec * sqrtN;
            dq = deque<int>();
            dqSeg = deque<pll>();

            pll q  = getSome(a);
            payed = q.first*P[a];
            gas = q.second;

            globist = q;

            dq.push_back(a);
            dqSeg.push_back(q);

            toppestLow = a;
            prevSec = sec;
            assert(check(a,b, payed, gas,toppestLow, dq));

        }

        {
            int b = sec*sqrtN;
            int bb = b;

            while(a>aa) {
                //cerr << "a <<\n";
                a--;

                //cerr << W[a+1] << " " << G[a+1] << " " << P[a+1] << " prev w g b\n";
                //cerr << W[a] << " " << G[a] << " " << P[a] << " w g b\n";

                globist = join(getSome(a), globist);

                ll hasPayed = 0;
                ll hadGas = 0;

                pll comb = getSome(a);

                while(!dq.empty() && P[dq.front()] >= P[a]) {
                    int i = dq.front();
                    pll iSeg = dqSeg.front();

                    dq.pop_front();
                    dqSeg.pop_front();

                    pll q = iSeg;

                    if (hadGas < q.first) {
                        //cerr << "weeeeeeee\n";
                        ll needGas = q.first - hadGas;
                        hadGas += needGas;
                        hasPayed += P[i]*needGas;
                    }

                    hadGas -= q.first;
                    hadGas += q.second;

                    comb = join(comb, iSeg);
                }


                //cerr << "substracting " << hasPayed << endl;
                payed -= hasPayed;

                while(true) {

                    if (!dq.empty() && dq.front() != a+1) {
                        //cerr << "Making sure removing what was reused\n";
                        int i = dq.front();
                        pll iSeg = dqSeg.front();

                        pll q = iSeg;
                        //cerr << "hadGas = " << hadGas << endl;
                        assert(q.first > hadGas);

                        payed += hadGas*P[i];

                    }


                    pll q = comb;

                    if ( dq.empty() ) {
                        //cerr << "dq.empty add " << q.first*P[a] << endl;
                        payed += q.first*P[a];
                        gas = q.second;
                        break;
                    }

                    else {
                        int i = dq.front();
                        pll iSeg = dqSeg.front();


                        pll qq = iSeg;


                        //cerr << "i j " << i << " " << j << endl;
                        //cerr << "q " << q.first << " " << q.second << endl;
                        //cerr << "qq " << qq.first << " " << qq.second << endl;

                        if (qq.first <= q.second) {
                            dq.pop_front();
                            dqSeg.pop_front();

                            //cerr << "Removing what would be freeby\n";
                            payed -= qq.first*P[i];
                            hadGas = qq.second;

                            comb = join(comb, iSeg);

                        }
                        else {
                            //cerr << "dq.not empty sub " << (q.second)*P[i]<< endl;
                            //cerr << "dq.not empy add " << q.first*P[a] << endl;

                            payed -= (q.second) * P[i];
                            payed += q.first*P[a];
                            break;
                        }
                    }
                }




                if (P[toppestLow] >= P[a]) {
                    toppestLow = a;
                }

                dq.push_front(a);
                dqSeg.push_front(comb);

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

                ////cerr << W[b-1] << " " << G[b-1] << " " << P[b-1] << " prev w g b\n";
                //cerr << W[b] << " " << G[b] << " " << P[b] << " w g b\n";

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


