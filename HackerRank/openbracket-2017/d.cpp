#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int allocSeg(int a, int b);

typedef pair<ll, int> pli;

struct Seg {
    ll cnt;
    int cnt2;
    bool nulled;

    int a, b;
    int left;
    int right;

    
    Seg() {
    }


    int nullify(int aa, int bb);

    void inc(int aa, ll v);

};



int segsPt = 1;
Seg segs[8000099];

void Seg::inc(int aa, ll v) {

    cnt += aa*v;
    cnt2 += v;

    if (a == b) {
        nulled = false;
        return;
    }

    int c = (a+b)/2;

    int toNull, toInc;
    if(aa <= c) {
        toNull = right;
        toInc = left;
    }
    else {
        toNull = left;
        toInc = right;
    }

    if (nulled) {
        nulled = false;
        segs[toNull].nulled = true;
        segs[toNull].cnt = 0;
        segs[toNull].cnt2 = 0;
        segs[toInc].nulled = true;
        segs[toInc].cnt = 0;
        segs[toInc].cnt2 = 0;
    }

    segs[toInc].inc(aa, v);
}

int Seg::nullify(int aa, int bb) {
    if (aa> bb) return 0;
    if(aa > b) return 0;
    if(bb < a) return 0;

    //cerr << "nullify " << aa << " " << bb  << "   " << a << " " <<b  << "  cnt: " <<cnt << "   cnt2: "<< cnt2<<endl;

    if(nulled) return 0;

    int ret;

    if(aa<=a && b <=bb) {
        nulled = true;
        ret = cnt2;
        cnt = 0;
        cnt2 = 0;
    }
    else{
        ret =  segs[left].nullify(aa, bb) + segs[right].nullify(aa, bb);

        cnt = segs[left].cnt + segs[right].cnt;
        cnt2 = segs[left].cnt2 + segs[right].cnt2;
    }

    //cerr << "nullified " << aa << " " << bb  << "   " << a << " " <<b << "   r: " << ret << "  cnt: " <<cnt << "   cnt2: "<< cnt2<<endl;
    return ret;
}

int allocSeg(int a, int b) {
    int ret  = segsPt;
    segsPt ++;

    segs[ret].nulled = false;

    segs[ret].a = a;
    segs[ret].b = b;
    
    segs[ret].cnt = 0;
    segs[ret].cnt2 = 0;

    if (a==b) {
        segs[ret].left = 0;
        segs[ret].right = 0;
    }
    else {
        int c = (a+b)/2;
        segs[ret].left = allocSeg(a, c);
        segs[ret].right = allocSeg(c+1, b);
    }
    return ret;
}


int n, m;
vector<vector<int>> G;

vector<vector<int>> horiz;
vector<vector<int>> trans;

ll tot;

Seg *seg;

int main() {
std::ios::sync_with_stdio(false);


    cin>>n>>m;
    G = vector<vector<int>>(n+1, vector<int>(m+1, 0));
    horiz = vector<vector<int>>(m+1, vector<int>(n+1, 0));
    trans = vector<vector<int>>(m+1, vector<int>(n+1, -1));

    seg = &segs[allocSeg(1, m)];
    //seg = &segs[allocSeg(1, 3)];

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >>G[i][j];
        }
    }

    for(int i = 1; i<=n; i++) {
        for(int j=m-1; j>=1; j--) {
            if (G[i][j] <= G[i][j+1]) {
                horiz[j][i] = horiz[j+1][i] + 1;
            }
        }
    }

    /*
    cerr << "horiz:\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cerr << horiz[i][j] << " ";
        }
        cerr <<endl;
    }
    */

    for(int i = 2; i<=n; i++) {

        int a = 1;
        int b = 1;

        while(true) {
            if (G[i-1][a] <= G[i][b]) {
                trans[b][i] = (a-b);
            }

            if (horiz[a][i] && horiz[a][i-1] && G[i-1][a+1] <= G[i][b]) {
                a++;
            }
            else if (b<a) {
                b++;
            }
            else {
                //assert(b==a);
                b++;
                a++;
            }
            if(b>m || a>m) break;
        }
    }

    /*
    cerr << "trans:\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cerr << trans[i][j] << " ";
        }
        cerr <<endl;
    }
    */

    int contained = 0;
    for(int j=1; j<=m; j++) {

        //cerr << contained <<  " contained\n";
        int nnn = seg->nullify(1, m);
        //cerr << "nnn " <<nnn<<endl;
        contained -= nnn;

        for(int i = 1; i<=n; i++) {

            //cerr << "Doing " << i << " " << j <<endl;

            int unfit = seg->nullify(trans[j][i]+1+1, m);
            //cerr << unfit <<endl;
            contained -= unfit;


            seg->inc(trans[j][i] + 1, unfit);
            seg->inc(horiz[j][i] + 1, 1);
            contained += unfit + 1;

            tot += seg->cnt;
        }
    }

    cout << tot <<endl;
}
