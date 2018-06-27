#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

typedef long long ll;

int n,k;

int cnt[201][2];



#define width ((60+26+1)*200)
#define neg ((26)*200)

// [m][k] for all sets of k elements, what is the maximum a st b = a+ m
ll t[width][201];

int main() {
    cin>>n>>k;
    for(int i=1; i<=n; i++) {
        ll l;
        cin>>l;
        while(l%2==0) {
            l/=2;
            cnt[i][0]++;
        }
        while(l%5==0) {
            l/=5;
            cnt[i][1]++;
        }
    }

    for(int i=-sub; i<=sub; i++) {
        t[i+sub][0] == -1;
    }

    for(int i=1; i<=n; i++) {
        int diff = cnt[i][1] - cnt[i][0];

        for(int s=-sub; s<=sub; s++) {
            t[s+ sub][i] = max(





    
}





