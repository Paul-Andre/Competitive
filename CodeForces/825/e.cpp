#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> G[100001];
int par_cnt[100001];

bool vis[100001];


int ass[100001];



int main() {
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int u,v;
        cin>>u>>v;
        G[v].push_back(u);
        par_cnt[u]++;
    }

    priority_queue<int> q;

    for(int i=1; i<=n; i++) {
        if (par_cnt[i] == 0 ) q.push(i);
    }


    int i = n;
    while(i!=0) {
        int j = q.top();
        q.pop();
        ass[j] = i;
        for(int k=0; k<G[j].size(); k++) {
            int u = G[j][k];
            par_cnt[u]--;
            if(par_cnt[u] == 0) {
                q.push(u);
            }
        }
        i--;
    }

    for(int i=1; i<=n; i++) {
        cout << ass[i] << ' ' ;
    }
    cout <<endl;
}
