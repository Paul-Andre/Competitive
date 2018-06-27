#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> SofaCoord; // (x1, x2) (y1, y2)
typedef pair<SofaCoord, pair<bool, int> > Sofa;

Sofa mk_sofa(int x1, int y1, int x2, int y2, int i) {
    return Sofa(SofaCoord(pii(x1, x2), pii(y1, y2)), make_pair(true, i));
}

#define fst first
#define snd second

int d;

int cl, cr, ct, cb;

Sofa S[100000];

void sortAndMark(int cnt) {
    sort(S, S+d);

    pii prev = S[0].fst.fst;
    int tot = 0;
    if(prev.fst == prev.snd) {
        if (tot == cnt) {
            for(int j=0; j<d; j++) {
                if(S[j].fst.fst != prev) {
                    S[j].snd.fst = false;
                }
            }
            return;
        }
    }

    for(int i=1; i<d; i++) {
        if(S[i].fst.fst != prev) {
            if(prev.fst != prev.snd) {
                if (tot == cnt) {
                    for(int j=0; j<d; j++) {
                        if(S[j].fst.fst != prev) {
                            S[j].snd.fst = false;
                        }
                    }
                    return;
                }
            }
        }
        prev = S[i].fst.fst;
        tot ++;
        if(prev.fst == prev.snd) {
            if (tot == cnt) {
                for(int j=0; j<d; j++) {
                    if(S[j].fst.fst != prev) {
                        S[j].snd.fst = false;
                    }
                }
                return;
            }
        }

    }

    if(prev.fst != prev.snd) {
        if (tot == cnt) {
            for(int j=0; j<d; j++) {
                if(S[j].fst.fst != prev) {
                    S[j].snd.fst = false;
                }
            }
            return;
        }
    }

    for(int j=0; j<d; j++) {
        S[j].snd.fst = false;
    }
}


void reverse() {
    for(int i=0; i<d; i++) {
        int x1, x2;
        x1 = S[i].fst.fst.fst;
        x2 = S[i].fst.fst.snd;
        S[i].fst.fst.fst = - x2;
        S[i].fst.fst.snd = -x1;
    }
}

void flip() {
    for(int i=0; i<d; i++) {
        pii x, y;
        x = S[i].fst.fst;
        y = S[i].fst.snd;
        S[i].fst.fst = y;
        S[i].fst.snd = x;
    }
}




int main() {
    int dummy;
    cin >> d >> dummy>> dummy;

    for(int i=0; i<d; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x2< x1) {
            int tmp = x2;
            x2 = x1;
            x1 = tmp;
        }
        if (y2< y1) {
            int tmp = y2;
            y2 = y1;
            y1 = tmp;
        }
        S[i] = mk_sofa(x1, y1,x2, y2, i+1);
    }
    cin >> cl >> cr >> ct >> cb;

    sortAndMark(cl);

    reverse();
    sortAndMark(cr);

    reverse();

    flip();

    sortAndMark(ct);
    reverse();
    sortAndMark(cb);

    for(int i=0; i<d; i++) {
        if( S[i].snd.fst == true) {
            cout<< S[i].snd.snd << endl;
            return 0;
        }
    }

    cout << "-1\n";
}
    










