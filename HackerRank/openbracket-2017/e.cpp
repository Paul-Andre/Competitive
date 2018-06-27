#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> G[200001];
int P[200001];

int unp=1;
int unfolded[400005];
int down[200001];
int up[200001];

int first[100001];
int second[100001];

bool vis[200001];
void unfold(int i) {
    vis[i] = true;
    unfolded[unp] = i;
    down[i] = unp;
    up[i] = unp;
    unp++;
    
    int p = P[i];
    if (first[p] == 0) {
        first[p] = i;
    }
    else {
        second[p] = i;
    }

    for(int j=0; j<G[i].size(); j++) {
        int u = G[i][j];

        if (!vis[u]) {

            unfold(u);

            unfolded[unp] = i;
            up[i] = unp;
            unp++;
        }
    }

}


int allocSeg(int a, int b);

typedef pair<int,int> pii;

struct Seg {
    int cnt;
    map<pii, int> subtracted;
    int a, b;
    int left;
    int right;

    
    Seg() {
    }

    int get(int aa, int bb);


    int chop(int aa, int bb);


    void unchop(int aa, int bb);
};



int segsPt = 1;
Seg segs[800009];

    int Seg::get(int aa, int bb) {

        if (aa > bb) return 0;
        if (bb < a) return 0;
        if (aa > b) return 0;

        int ret;
        if (aa<=a && b<=bb) {
            ret = cnt;
        }
        else if (cnt == 0) {
            ret = 0;
        }
        else {
            ret = segs[left].get(aa, bb) + segs[right].get(aa, bb);
        }

        return ret;

    }

    int Seg::chop(int aa, int bb) {

        if (aa > bb) return 0;
        if (bb < a) return 0;
        if (aa > b) return 0;

        int ret;
        if (aa<=a && b<=bb) {
            ret = cnt;
        }
        else if (cnt == 0) {
            ret = 0;
        }
        else {
            ret = segs[left].chop(aa, bb) + segs[right].chop(aa, bb);
        }

        subtracted[pii(aa, bb)] = ret;

        cnt-=ret;
        return ret;
    }

    void Seg::unchop(int aa, int bb) {

        if (aa > bb) return;
        if (bb < a) return;
        if (aa > b) return;

        auto it = subtracted.find(pii(aa,bb));
        assert(it!= subtracted.end());

        cnt += it->second;
        subtracted.erase(it);

        if (aa<=a && b<=bb) {
        }
        else if (cnt == 0) {
        }
        else {
            segs[left].unchop(aa, bb); segs[right].unchop(aa, bb);
        }
    }


void chop(int aa, int bb) {
    segs[1].chop(aa, bb);
}

void unchop(int aa, int bb) {
    segs[1].unchop(aa, bb);
}


int allocSeg(int a, int b) {
    int ret  = segsPt;
    segsPt ++;

    segs[ret].a = a;
    segs[ret].b = b;
    
    if (a==b) {
        segs[ret].cnt = down[unfolded[a]] == a;
        segs[ret].left = 0;
        segs[ret].right = 0;
    }
    else {
        int c = (a+b)/2;
        segs[ret].left = allocSeg(a, c);
        segs[ret].right = allocSeg(c+1, b);
        segs[ret].cnt = segs[segs[ret].left].cnt + segs[segs[ret].right].cnt;
    }
    return ret;
}


set<int> parents;

ll tot;

int lastOcc[200001];
int excluded[200001];

Seg *seg;

int main() {
    cin>>n;
    for(int i=0; i<n-1; i++) {
        int x;
        cin>>x;
        G[x].push_back(i+2);
        G[i+2].push_back(x);
    }

    for(int i=1; i<=n; i++) {
        cin>>P[i];
    }

    unfold(1);

    cerr << tot <<endl;
    cerr << "Makeseg\n";
    allocSeg(1, 400004);
    seg = &segs[1];

    cerr << "end makeseg " << segsPt << " \n";

    cerr << tot <<endl;

    for(int i=1; i<unp; i++) {
        int u = unfolded[i];
        int p = P[u];

        lastOcc[u] = i;

        cerr << "i u p " << i << " " << u << " " << p << endl;


        if (down[u] == i) {
            parents.insert(u);

            if(u == second[p]) {
                if (parents.find(first[p]) != parents.end()) {
                    chop(1, lastOcc[first[p]]);
                }
                else {
                    chop(down[first[p]], up[first[p]]);
                    excluded[first[p]] = true;
                }
            }
            else if(u == first[p]) {

            }

            int got = seg->get(1, i);

            cerr << "seg count is " << got << " out of " << seg->cnt <<endl;
            tot += got;
        }
        if (up[u] == i) {
            parents.erase(u);

            if(u == second[p]) {
                if (parents.find(first[p]) != parents.end()) {
                    unchop(1, lastOcc[first[p]]);
                }
                else {
                    assert(excluded[first[p]]);
                    unchop(down[first[p]], up[first[p]]);
                    excluded[first[p]] = false;
                }
            }
        }
        if (u == first[p] && up[second[p]]< i) {
            if (!excluded[second[p]]) {
                cerr << "The clause \n";
                cerr << "second[p] " << second[p] <<endl;
                chop(down[second[p]], up[second[p]]);
                excluded[second[p]] = true;
            }
        }

        /*
        cerr << "We have:\n";
        for(int i = 1; i<=n ;i++) {
            int d = down[i];
            cerr << i << " " << seg->get(d,d) << endl;
        }
        */
    }

    cout << tot*2 - n <<endl;
}
