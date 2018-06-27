#include <bits/stdc++.h>
using namespace std;


string s,t;
int main(){
    int n,m;
    cin>>n>>m;
    cin >>s >> t;


    int least = n+m;
    int best = -1;

    for(int i=0;i<=m-n; i++) {
        int cnt = 0;
        for(int j=0;j<n; j++) {
            cnt += (int)(s[j] != t[i+j]);
        }
        if(cnt <least) {
            least = cnt;
            best = i;
        }
    }
    int i = best;
    cout<<least<<endl;
    for(int j=0;j<n; j++) {
        if (s[j] != t[i+j]) cout << j+1 <<" ";
    }
    cout<<endl;
}




