#include <bits/stdc++.h>
using namespace std;


int n;
typedef long long ll;

ll pos[2502][2];

#define SQR(X) ((X)*(X))

ll dist[2502];
bool vis[2502];
int parent[2502];


ll cost(int i, int j) {
        ll d = (SQR(pos[i][0] - pos[j][0]) + SQR(pos[i][1] - pos[j][1]));
        return d;
}



int main() {
    cin>>n;

    for(int i=1; i<=n; i++) {
        cin >> pos[i][0] >> pos[i][1];
    }

    cin >> pos[0][0] >> pos[0][1];
    cin >> pos[n+1][0] >> pos[n+1][1];

    for(int i=0; i<=n+1; i++) {
        dist[i] = cost(0, i);
        parent[i] = 0;
    }

    vis[0] = true;


    while(true) {
        ll mc = ((unsigned long long)(-1))>>1;
        int mi = -1;
        for(int i=0; i<=n+1; i++) {
            if (!vis[i]) {
                if (dist[i] < mc) {
                    mi = i;
                    mc = dist[i];
                }
            }
        }

        vis[mi] = true;

        for(int i=0; i<=n+1; i++) {
            if (!vis[i]) {
                ll nd = cost(mi, i) + dist[mi];
                if ( nd < dist[i]) {
                    dist[i] = nd;
                    parent[i] = mi;
                }
            }
        }

        if (mi == n+1) break;
    }

    vector<int> ret;

    int x = n+1;
    while(x!= 0) {
        x = parent[x];
        ret.push_back(x);
    }

    if (ret.size() > 1) {

        for(int i=ret.size()-2; i>=0; i--) {
            cout << ret[i]-1 <<endl;
        }
    }
    else {
        cout << "-\n";
    }


}



    


