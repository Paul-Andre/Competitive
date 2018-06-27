#include <bits/stdc++.h>
using namespace std;



int N,Q;

int parent[1000001];
int rnk[1000001];

int get(int a) {
    int p = parent[a];
    if (p == 0) return a;
    int g = get(p);
    parent[a] = g;
    return g;
}

void unite(int a, int b) {
    int ra = get(a);
    int rb = get(b);
    if (ra == rb) return;
    if (rnk[ra] > rnk[rb]) {
        parent[rb] = ra;
    }
    else if (rnk[ra] < rnk[rb]) {
        parent[ra] = rb;
    }
    else {
        parent[ra] = rb;
        rnk[rb] ++;
    }
}


int main() {
    cin>>N>>Q;
    for(int iii; iii<Q; iii++) {
        char c;
        int a, b;
        cin >>c >>a>>b;
        a++;
        b++;
        if (c=='=') {
            unite(a,b);
        }
        else {
            if (get(a) == get(b)) {
                cout <<"yes\n";
            }
            else 
                cout <<"no\n";
        }
    }
}

