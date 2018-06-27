#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int,int> pii;
string s[100000];
int occi;
pii occ[1000000];


char ret[5000000];

int main() {
    int n;
    cin >>n;


    for(int i=0; i<n;i++){
        cin >>s[i];
        int k;
        cin >>k;
        for(int j=0;j<k;j++) {
            int x;
            cin >> x;
            occ[occi] = pii(x, i);
            occi++;
        }
    }

    sort(occ, occ+occi);
    int now = 0;
    int i = 0;

    while(true) {

        if(occ[i].fi + s[occ[i].se].size() - 1< now) {
            i++;
        }
        else if(occ[i].fi > now) {
            ret[now] = 'a';
            now++;
        }
        else {
            ret[now] = s[occ[i].se][now-occ[i].fi];
            now++;
        }
        if (i==occi) break;
    }

    puts(ret+1);

}
