#include <bits/stdc++.h>
using namespace std;

int n;

int A[100000];
int nxt[100000];

bool ss(int i, int j) {
    return A[i] < A[j];
}

int cnt;
bool vis[100000];

vector<vector<int>> out;

int main() {
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>A[i];
        nxt[i] = i;
    }
    sort(nxt, nxt+n, ss);

    for(int i=0; i<n; i++) {
        if (!vis[i]) {
            out.push_back(vector<int>());
            int j = i;
            while(!vis[j]) {
                vis[j] = true;
                out[cnt].push_back(j+1);
                j = nxt[j];
            }
            cnt++;
        }
    }
    cout << cnt <<endl;
    for(int i=0; i<cnt; i++) {
        cout << out[i].size() << " ";
        for(int j=0; j<out[i].size(); j++) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
}




    

