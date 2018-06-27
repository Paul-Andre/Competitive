#define _USE_MATH_DEFINES
#include <math.h>

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> kids[1000];

double ar[1000];

typedef pair<ll, ll> pii;

pair<ll, pair<ll, ll> > d[1000];

double t[1000][2][2];

ll n;

vector<ll> root;

#define sqr(x) ((x)*(x))

ll sqrdist(pii a, pii b) {
    return sqr(a.first - b.first) + sqr(a.second - b.second);
}

int main() {
    cin >> n;


    vector<ll> danc;

    for (ll i=0 ; i<n; i++) {
        ll x,y,r;
        cin >> x >> y >> r;
        pair<ll, pair<ll, ll> > p = make_pair(r, make_pair(x,y));
        d[i] = p;
    }

    sort(d, d+n);

    for (ll i=0; i<n ; i++){
        ar[i] = M_PI*sqr(d[i].first);
        for (ll j=i+1; j<n; j++) {
            if ( sqrdist( d[i].second, d[j].second) < sqr(d[j].first)) {
                kids[j].push_back(i);
                goto continue_outer;
            }
        }
        root.push_back(i);
continue_outer: ;
    }

    for (ll i=0; i<n ; i++){
        for (ll a=0; a<2; a++) {
            for (ll b=0; b<2; b++) {
                double mx = - numeric_limits<double>::infinity();
                for (ll c=0; c<2; c++) {
                    ll aa = 1-a;
                    ll bb = b;

                    double tot;
                    if ( a) {
                        tot = +ar[i];
                    }
                    else {
                        tot = -ar[i];
                    }


                    if ( c) {
                        aa = a;
                        bb = 1-b;
                        if ( b) {
                            tot = +ar[i];
                        }
                        else {
                            tot = -ar[i];
                        }
                    }

                    for (ll j=0; j<kids[i].size(); j++) {
                        ll u = kids[i][j];
                        tot += t[u][aa][bb];
                    }

                    mx = max(mx, tot);
                }
                t[i][a][b] = mx;
            }
        }
    }

    /*
    for (ll i=0; i<n; i++) {
        cout<< d[i].first << " " << d[i].second.first << " " << d[i].second.second << " : ";
        cout << t[i][0][0] << " " << t[i][0][1] << " " << t[i][1][0] << " " << t[i][1][1] << " : " << ar[i] << endl;
    }
    */

    double res = 0;
    for (ll i=0; i<root.size(); i++) {
        res += t[root[i]][1][1];
    }
    cout.precision(17);

    cout << res <<endl;
}
