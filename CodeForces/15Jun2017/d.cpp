#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int A[1000000];

struct SegmentTree {
    int m;
    int mi;
    int a, b;
    SegmentTree *left = nullptr;
    SegmentTree *right = nullptr;

    SegmentTree() {
    }

    SegmentTree(int aa, int bb) {
        a = aa;
        b = bb;
        if (a == b) {
            mi = a;
            m= A[mi];
        }
        else {
            int c = (a+ b) /2;
            left = new SegmentTree(a, c);
            right = new SegmentTree( c+1, b);

            if (left->m > right->m) {
                m = left->m;
                mi = left->mi;
            }
            else {
                m = right->m;
                mi = right->mi;
            }
        }
    }



    int q(int aa, int bb) {

        if (bb < a || aa > b || aa > bb) {
            return -1;
        }
        if ( aa <= a && b <= bb) {
            return mi;
        }
        else {
            int il = left->q(aa, bb);
            int ir = right->q(aa, bb);

            if (il == -1 || ir == -1) {
                return max(il, ir);
            }

            else if ( A[il] > A[ir] ) {
                return il;
            }else {
                return ir;
            }
        }
    }

    /*
    ~SegmentTree() {
        if ( left != nullptr) {
            delete left;
        }
        if ( right != nullptr) {
            delete right;
        }
    }
    */
};

SegmentTree segmentTree;
int n;


int maxInRange(int aa, int bb) {
    if (aa == bb) {
        return aa;
    }
    if ((bb-aa) > 100) {
        return segmentTree.q(aa, bb);
    }
    else {
        int ii = -1;
        int mm = -10000000;
        for (int i=aa; i<=bb; i++) {
            if (A[i] > mm) {
                mm= A[i];
                ii= i;
            }
        }
        return ii;
    }
}



typedef pair<int ,int> pii;

ll getSumOfMaxes() {

    stack<pii> q;
    q.push(pii(0,n-1));
    
    ll tot = 0;

    while(!q.empty()) {

        pii ab = q.top();
        q.pop();

        int a = ab.first;
        int b = ab.second;

        if ( a > b) continue;
        if ( a >=n) continue;
        if ( b < 0) continue;

        //cerr  << " Query " << a << " " << b << endl;

        int maxI = maxInRange(a,b);
        assert(maxI != -1);
        ll m = A[maxI];
        //cerr  << " It is " << m << endl;
        //

        tot += m*(b-maxI+1)*(maxI-a+1);

        q.push(pii(a, maxI-1));
        q.push(pii(maxI+1, b));
    }

    return tot;
}



int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> A[i];
    }

    segmentTree = SegmentTree(0, n-1);

    ll m = getSumOfMaxes();

    for(int i=0; i<n; i++) {
        A[i] *= -1;
    }
    segmentTree = SegmentTree(0, n-1);

    ll mm = getSumOfMaxes();

    cout << (m + mm) << endl;
}


