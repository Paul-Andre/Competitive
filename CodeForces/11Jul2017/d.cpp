#include <bits/stdc++.h>
using namespace std;


int n, k;

typedef pair<int,int> pii;


int main() {
    cin>>n>>k;

    vector<pii> out;


    int res = n%k;

    vector<int> beg;
    int at = 1;

    int tot = 2*n/k-2;


    for(int i=0;i<k;i++) {
        beg.push_back(at);
        int l = n/k;
        for(int j=1;j<l; j++) {
            out.push_back(pii(at+j-1, at+j));
        }
        at +=l;
    }


    if(res==0) {
        for(int i=0; i<beg.size()-1; i++) {
            out.push_back(pii(beg[i], beg.back()));
        }
        if(k==2)tot++;
        else tot+=2;
    }
    else if (res==1) {
        for(int i=0; i<beg.size(); i++) {
            out.push_back(pii(beg[i], at));
        }
        tot+=2;
    }
    else {
        tot+=2;
        if(res ==2) tot++;
        else tot+=2;
        for(int i=1; i<res; i++) {
            out.push_back(pii(at, at+i));
            out.push_back(pii(beg[i-1], at+i));
        }
        for(int i=res-1; i<k; i++) {
            out.push_back(pii(at, beg[i]));
        }
    }
    cout << tot <<endl;
    for(int i=0; i<out.size(); i++) {
        cout << out[i].first << " "<< out[i].second <<endl;
    }
}
