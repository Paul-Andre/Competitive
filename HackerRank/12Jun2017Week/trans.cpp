#include <bits/stdc++.h>

using namespace std;


int n, k, m;

int parent[100001];
int rk[100001];

int find(int i) {
    if (parent[i] == 0) {
        return i;
    }
    else {
        int par = find(parent[i]);
        parent[i] = par;
        return par;
    }
}

void join(int a, int b) {
    int pa =find(a);
    int pb =find(b);
    if (pa != pb) {
        if (rk[pa] > rk[pb]) {
            parent[pb] = pa;
        }
        else if (rk[pb] > rk[pa]) {
            parent[pa] = pb;
        }
        else {
            parent[pa] = pb;
            rk[pb] ++;
        }
    }
}

int a[1000];

int t[1000][1000];

int main() {
    int n;
    int k;
    int m;
    cin >> n >> k >> m;
    for(int a0 = 0; a0 < k; a0++){
        int x;
        int y;
        cin >> x >> y;
        join(x,y);
    }
    for(int a_i = 0; a_i < m; a_i++){
       cin >> a[a_i];
       a[a_i] = find(a[a_i]);
       //cout << a[a_i] << " ";
    }
    cout << endl;
    for (int i=0; i<m; i++) {
        t[i][i] = 1;
    }
    for (int i=1; i<m; i++) {
        if (a[i-1] == a[i]) {
            t[i-1][i] = 2;
        }
        else {
            t[i-1][i] = 1;
        }
    }
    for (int s = 3; s<=m; s++) {
        for (int i=0; i<=m-s; i++) {
            t[i][i+s-1] = max(max(t[i+1][i+s-2] + 2*(int)(a[i] == a[i+s-1]), t[i][i+s-2]), t[i+1][i+s-1]);
        }
    }

    cout << t[0][m-1] << endl;
}
