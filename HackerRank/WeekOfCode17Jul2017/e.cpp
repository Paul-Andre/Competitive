#include <bits/stdc++.h>
using namespace std;

int n, m, q;

int p;

vector<vector<bool>> front;

typedef long long ll;

long long results[1000000][25];

int main() {
    cin>>n>>m>>q;
    front = vector<vector<bool>>(n+1, vector<bool>(m+1,0));

    for(int i=0; i<n; i++) {
        int x;
        cin >>x;
        for(int j=0; j<x; j++) {
            int val;
            cin >> val;
            front[i][val] = true;
        }
    }

    ll total = 0;

    for(ll i=1; i<=m; i++) {
        total += (i*i);
    }


    while((1<<p) < m) p++;
    cerr << p <<" is p\n";;


    for(int i=1; i<=p; i++) {

        vector<int> part(m+1);
        memset(&part[0], 0, (m+1)*sizeof(int) );

        for(int j=0; j<i && j<n; j++) {
            for(int k=1; k<=m; k++) {
                part[k] |= (int)(front[j][k]) << j;
            }
        }

        vector<ll> acc((1<<i));

        for(int j = 0; j+i<=n; j++) {

            memset(&acc[0], 0, (1<<i)*sizeof(ll) );

            for(ll k=1; k<=m; k++) {
                acc[part[k]] += k*k;
            }

            ll mmin = total;
            for(ll k=0; k<(1<<i); k++) {
                mmin = min(mmin, acc[k]);
            }

            results[j][i] = total - mmin;

            for(int k=1; k<=m; k++) {
                part[k] = (part[k] >> 1) | ((int)(front[j+i][k]) << (i-1));
            }

        }


    }

    for(int i=0; i<q; i++) {
        int l,r;
        cin>>l>>r;
        int w = r-l+1;

        if (w > p) {
            //cerr << "wee\n";
            cout << total <<endl;
        }
        else {
            cout << results[l-1][w] <<endl;
        }
    }
}
