#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 2000001

int n;
ll x,y;

bool seive[2000001];

ll up[2000001];
ll cnt[2000001];


int main() {
    cin >>n>>x>>y;

    for(int i=0; i<n; i++) {
        int e;
        cin>>e;
        cnt[e] ++;
        up[e] +=e;
    }

    for(int i=2; i<N; i++) {
        if (!seive[i]) {
            for(int ii=i*2; ii<N; ii+=i) {
                seive[ii] = true;
            }
        }
    }
    for(int i=1; i<N; i++) {
        up[i] += up[i-1];
        cnt[i] += cnt[i-1];
    }

    int untilDelete = x/y;

    ll best = ((unsigned long long)(-1))>>1;
    //cerr << best <<endl;

    for(int i=2; i<N; i++) {
        if (!seive[i]) {
            ll totVal = 0;
            ll totX = 0;
            ll totY = 0;
            for(ll ii=i; ii<N; ii+=i) {
                ll inseg = cnt[ii] - cnt[ii-i];

                int inch = min(i, untilDelete + 1);
                ll ininch = cnt[ii] - cnt[ii-inch];
                ll inchD = up[ii] - up[ii-inch];
                ll tD = ininch*ii - inchD;

                ll val = (inseg - ininch)*x + tD*y;
                totX += (inseg - ininch);
                totY += tD;
                totVal += val;
            }
            best = min(best, totVal);
            //cerr << totVal << " " << i << "     ";
            //cerr << totX << " " << totY << endl;
        }
    }

    cout << best;
}

