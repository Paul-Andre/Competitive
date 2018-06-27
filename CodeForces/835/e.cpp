#include <bits/stdc++.h>
using namespace std;


int n,x,y;

int xy;


vector<int> ans;

int ask(int a, int b, vector<int> &v) {
    cout << "? " << (b-a+1) << " " ;
    for(int i=a; i<=b; i++) {
        cout << v[i];
        if ( i!=b) cout << " ";
    }
    cout << endl;
    fflush(stdout);

    int ret;
    cin>>ret;
    return ret;
}


void single(int a, int b, vector<int> &v) {
    if (a == b) {
        ans.push_back(v[a]);
        return ;
    }

    int c = (a+b)/2;
    int l = ask(a, c, v);
    if ((c - a+1)%2 == 1 && l == y) single(a, c, v);
    else if ((c - a+1)%2 == 0 && l == xy) single(a, c, v);
    else single(c+1, b, v);
}



bool askBits(int a) {
    vector<int> as;
    for(int i=1; i<=n; i++) {
        if ((i) & a) as.push_back(i);
    }
    cout<< "? " << as.size() << " ";
    for(int i=0; i<as.size(); i++) {
        cout << as[i];
        if ( i!=as.size()-1) cout<< " ";
    }
    cout << endl;
    fflush(stdout);
    int r;
    cin>>r;
    if( as.size() % 2 == 1 && r == y) return true;
    if( as.size() % 2 == 0 && r == xy) return true;
    return false;
}



int main() {
    cin>>n>>x>>y;
    xy = x^y;

    int flip = 0;
    int flask = -1;
    {
        int mask = 1;
        while(mask<=n) {
            if (askBits(mask)) {
                if ( flask == -1) {flask = mask;}
                flip |= mask;
            }
            mask*=2;
        }
    }

    vector<int> A;
    cerr << flask << " flask\n";
    cerr << flip << " flip\n";

    assert(flask != -1);

    for(int i = 1; i<=n; i++) {
        if (flask & (i)) {
            A.push_back(i);
        }
    }

    single(0, A.size()-1, A);

    assert(ans.size() == 1);
    cerr << ans[0] << " first answer"<<endl;

    //cwee << (ans[0] ^ flip)
    ans.push_back(((ans[0]) ^ flip));

    sort(ans.begin(), ans.end());

    cout<< "! " << ans[0] << " " << ans[1] << endl;
    fflush(stdout);
}
