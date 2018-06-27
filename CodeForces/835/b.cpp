#include <bits/stdc++.h>
using namespace std;


int k;
string NNN;
int N[100005];

int main() {
    cin>>k>>NNN;
    int tot = 0;
    int l=NNN.size();
    for(int i=0; i<l; i++) {
        N[i] = NNN[i]-'0';
        tot += NNN[i]-'0';
    }

    sort(N, N+l);

    //cerr <<tot<<endl;
    int tt = 0;
    for(int i=0; i<l && tot<k; i++) {
        tot += 9 - N[i];
        tt ++;
    }

    cout<<tt<<endl;
}

    
