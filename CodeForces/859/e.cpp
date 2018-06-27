#include <bits/stdc++.h>
using namespace std;


#define MOD 1000000007

int N;


typedef long long ll;

ll tot =1;

int nxt[100000*2 +10];
vector<int> back[100000*2 +10];


bool into[100000*2 +10];
bool out[100000*2 +10];
bool vis[100000*2 +10];
int numb[100000*2 +10];
bool cyc[100000*2 +10];

vector<int> roots;


void travCyc(int i, int num) {
    if (vis[i]) {
        if( numb[i] == num) {
            if (nxt[i] != i) {
                tot *=2;
                tot %= MOD;
            }
            return;
        }
        else {
            return;
        }
    }

    vis[i] = true;
    numb[i]= num;
    if (nxt[i] == 0) {
        return;
    }
    return travCyc(nxt[i], num);
}

ll travTree(int i) {
    if (i == 0) return 0;
    ll toto = 0;
    for(int j=0; j<back[i].size(); j++) {
        toto += travTree(back[i][j]);
        toto %= MOD;
    }
    toto ++;
    toto %= MOD;
    return toto;
}


int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        int x,y;
        cin>>x>>y;
        nxt[x] = y;
        back[y].push_back(x);
        into[y] = true;
        out[x] = true;
    }


    for(int i=1; i<=N*2+1; i++) {
        if (!into[i]) {
            travCyc(i, i);
        }
    }

    for(int i=1; i<=N*2+1; i++) {
        if (!vis[i]) {
            travCyc(i, i);
        }
    }

    for(int i=1; i<=N*2+1; i++) {
        if (!out[i]) {
            tot *= travTree(i);
            tot %= MOD;
        }
    }

    cout << tot << endl;
}



