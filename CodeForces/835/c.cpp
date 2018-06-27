#include <bits/stdc++.h>
using namespace std;


int n,q,c;

int cnt[101][101][12];


int main() {
    cin>>n>>q>>c;
    for(int i=0;i<n;i++) {
        int x,y,s;
        cin>>x>>y>>s;
        for(int i=0; i<=c; i++) {
            cnt[x][y][i] += s;
            s+=1;
            if (s>c) s=0;
        }
    }

    for(int k=0; k<=c; k++) {
        for(int i=1; i<=100; i++) {
            for(int j=1; j<=100; j++) {
                cnt[i][j][k] = cnt[i][j][k] + cnt[i-1][j][k] + cnt[i][j-1][k] - cnt[i-1][j-1][k];
            }
        }
    }

    /*
        cerr<<endl;
    for(int i=0; i<=5; i++){
        for(int j=0; j<=5; j++){
            cerr<<cnt[i][j][0] << " " ;
        }
        cerr<<endl;
    }
    */

    for(int i=0; i<q; i++) {
        int t,x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;

        t %= (c+1);

        int res = cnt[x2][y2][t] - cnt[x2][y1-1][t] - cnt[x1-1][y2][t] + cnt[x1-1][y1-1][t];
        cout<<res<<endl;
    }
}
