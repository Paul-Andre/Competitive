#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a,b,h,w,n;
vector<int> exps;

#define oo 1000000

bool rev(int a, int b){
    return a>b
        ;
}

int proc(int ptr, int h, int w) {
    if (h>=a && w>=b) return ptr;
    if (ptr>=exps.size()) return oo;
    
    int x1 = proc(ptr+1, h*exps[ptr], w);
    int x2 = proc(ptr+1, h, w*exps[ptr]);

    return min(x1, x2);
}


int main(){
    cin >> a >> b >> h >> w>>n;
    for (int i=0; i<n; i++) {
        int x;
        cin >>x;
        exps.push_back(x);
    }

    sort(exps.begin(), exps.end(), rev);

    int p = min(proc(0, h, w), proc(0, w, h));

    if (p==oo)
        p=-1;

    cout << p << '\n';
}
