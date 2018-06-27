#include <bits/stdc++.h>
using namespace std;

vector<int> tree[10001];
int M[10001];

bool isNotRoot[10001];

int tot;



int trav(int i) {
    int def = M[i]-1;
    for(int j=0; j<tree[i].size(); j++) {
        int u = tree[i][j];
        def += trav(u);
    }
    tot += abs(def);
    //cerr << "Returning from node " << i << " with def " << def << endl;
    return def;
}



int main() {
    while(true) {
        int n;
        cin >> n;
        if(n==0) break;

        for(int i=0; i<n; i++) {
            tree[i].clear();
            isNotRoot[i] = false;
        }

        for(int i=0; i<n; i++) {
            int v, m, d;
            cin >> v >> m >>d;

            M[v] = m;

            for(int j=0; j<d; j++) {
                int u;
                cin >> u;
                tree[v].push_back(u);
                isNotRoot[u] = true;
            }
        }

        int root = -1;

        for(int i=1; i<=n; i++) {
            if(!isNotRoot[i]) {
                root = i;
                break;
            }
        }


        tot = 0;
        assert(trav(root) == 0);

        cout << tot << endl;
    }
}
