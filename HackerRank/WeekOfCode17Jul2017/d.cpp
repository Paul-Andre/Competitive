#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;


struct Mat{
    ll a,b,c,d;
};

Mat operator+(Mat A, Mat B){
    Mat ret =  {
        (A.a+B.a) % MOD,
        (A.b+B.b) % MOD,
        (A.c+B.c) % MOD,
        (A.d+B.d) % MOD,
    };
    return ret;
}

Mat operator*(ll s, Mat A) {
    Mat ret =  {
        (s*A.a) % MOD,
        (s*A.b) % MOD,
        (s*A.c) % MOD,
        (s*A.d) % MOD,
    };
    return ret;
}

Mat operator*(Mat A, Mat B){
    Mat ret = {
        (A.a*B.a + A.b*B.c) % MOD,
        (A.a*B.b + A.b*B.d) % MOD,
        (A.c*B.a + A.d*B.c) % MOD,
        (A.c*B.b + A.d*B.d) % MOD,
    };
    return ret;
}

Mat expMat(Mat A, int e) {
    Mat acc = {1,0,0,1};
    while(e!=0){
        if(e%2==0){
            A = A*A;
            e/=2;
        }
        else{
            acc = acc*A;
            e--;
        }
    }
    return acc;
}


int n;
vector<int> GNotRooted[200001];
vector<int> G[200001];

bool vis[200001];

void root(int i) {
    vis[i] = true;

    for(int j=0; j<GNotRooted[i].size(); j++) {
        int u = GNotRooted[i][j];
        if (!vis[u]) {
            G[i].push_back(u);
            root(u);
        }
    }
}



Mat C[200001];
Mat total;

Mat withRoot[200001];


void trav(int i) {

    for(int j=0; j<G[i].size(); j++) {
        int u = G[i][j];
        trav(u);
    }

    Mat acc = {1,0,0,1};
    Mat tot = {0,0,0,0};


    for(int j=0; j<G[i].size(); j++) {
        int u = G[i][j];
        acc = acc + 2*withRoot[u];
        tot = tot + withRoot[u];
    }
    withRoot[i] = C[i];
    withRoot[i] = withRoot[i] + tot*C[i];


    for(int j=0; j<G[i].size(); j++) {
        int u = G[i][j];
        Mat t = tot + (-1)*withRoot[u];
        acc = acc + (t * withRoot[u]);
    }

    acc = acc*C[i];

    total = total + acc;
}



int main() {
    cin >>n;

    for(int i=0; i<n-1; i++) {
        int x,y;
        cin>>x>>y;
        GNotRooted[x].push_back(y);
        GNotRooted[y].push_back(x);
    }

    root(1);


    Mat base = {1,1,1,0}; 

    for(int i=1; i<=n; i++) {
        int c;
        cin >>c;
        C[i] = expMat(base, c);
    }

    trav(1);

    /*
    for(int i=1; i<=n; i++) {
        cout << withRoot
    */

    cout << (total.a + MOD) % MOD  <<endl;

}

