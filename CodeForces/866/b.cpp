#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, S;
ll A[100000];
ll B[100000];
ll tot[100000];

typedef pair<int,int> pii;

/*
struct  ss {
    pii;
    int a;
    int b;

    ss(int i, int j, int aa, int bb) {
        first = i;
        second = j;
        a = aa;
        b = bb;
    }
};

bool operator< (ss x, ss y) {
    return x.first < y.first;
}
*/

pii dt[100010];


ll mmin;

ll mmax;

ll ttot;

int main() {
    cin>>N>>S;
    for(int i=0; i<N; i++) {
        cin >> tot[i] >> A[i] >> B[i];
        mmax += (max(A[i], B[i]) *tot[i]);
        dt[i] = pii(-A[i]+B[i], tot[i]);
        ttot += tot[i];
    }

    sort(dt, dt+N);

    for(int i=0; i<N; i++) {
        dt[i].first *=-1;
    }


    ll wantA = 0;

    for(int i=0; i<N; i++) {
        if (dt[i].first >= 0) {
            wantA += dt[i].second;
        }
    }

    ll wantB = ttot - wantA;

    ll lest = (wantA / S) * S;
    ll rest = ttot - (wantB / S) * S;

    //cerr << "rlest "<< rest-lest <<endl;
    if (wantB == 0 || wantA == 0 || rest - lest > S) {
        // perfect world
        //
        //
        cout << mmax <<endl;
        return 0;

    }
    else {
        ll li;
        ll ltook;
        {
            ll covered = 0;
            ll i = 0;
            ll took = 0;
            while(i<N) {
                if (covered + dt[i].second <= lest) {
                    covered += dt[i].second;
                    i ++;
                }
                else {
                    took = lest - covered;
                    break;
                }
            }
            li = i;
            ltook = took;
        }
        ll ri;
        ll rtook;
        {
            ll covered = 0;
            ll i = 0;
            ll took = 0;
            while(i<N) {
                if (covered + dt[i].second <= rest) {
                    covered += dt[i].second;
                    i ++;
                }
                else {
                    took = rest - covered;
                    break;
                }
            }
            ri = i;
            rtook = took;
        }

        //cerr << li << " " <<ltook << "    " << ri << " " <<rtook <<endl;

        ll i = li;
        ll took = ltook;

        ll penalA = 0;
        ll penalB = 0;

        while(true) {
            if (i == ri && took >= rtook) break;
            if (took >= dt[i].second) {
                i++;
                took = 0;
            }
            else {
                penalA += min(dt[i].first, 0);
                penalB += min(-dt[i].first, 0);
                took++;
            }
        }

            cout << mmax + max(penalA, penalB) <<endl;
            return 0;
    }
}
