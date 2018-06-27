#include <bits/stdc++.h>
using namespace std;

int n,m;

typedef pair<int,int> pii;

vector<int> G[300001];

int type[300001];

map<pii,int> eg;
map<int,int> cnt;
map<int,int> last;

bool vis[300001];

set<pii> sel;

int inu(int i) {
    vis[i] = true;
    type[i] = !!type[i];
    for(int j=0; j<G[i].size(); j++) {
        int u = G[i][j];
        if (!vis[u]) {
            int k = inu(u);
            if (k) {
                sel.insert(pii(u,i));
                type[i] ++;
                type[i] %= 2;
            }
        }
    }
    return type[i];
}


int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin >> type[i];
        cnt[type[i]]++;
        last[type[i]] = i;
    }

    for(int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        eg[pii(x,y)] = i;
        eg[pii(y,x)] = i;
    }

    if (cnt[-1] == 0 && cnt[1] % 2 != 0) {
        cout<<"-1\n";
        exit(0);
    }

    if (cnt[-1] != 0) {
        inu(last[-1]);
    }
    else {
        inu(1);
    }

    cout << sel.size() <<endl;

    vector<int> out;
    for(auto it = sel.begin(); it != sel.end(); it++) {
        out.push_back(eg[*it]);
    }
    sort(out.begin(), out.end());
    for(int i=0; i<out.size(); i++) {
        cout << out[i] <<endl;
    }


}
