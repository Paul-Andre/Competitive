#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
int n;

typedef pair<int, int> pii;

vector<int> tree[1000];
int currentC;
int ord[1000];

pii points[1000];
int ass[1000];

bool assSort(int a, int b) {
    if (points[a].x == points[b].x) {
        return points[a].y < points[b].y;
    }
    else {
        return points[a].x < points[b].x;
    }
}


bool switched[1000][1000];
bool vis[1000];

vector<int> ordTree[1000];
int invOrd[1000];

void order(int i) {
    vis[i] = true;
    ord[i] = currentC;
    invOrd[currentC] = i;
    currentC++;
    for (int j=0; j<tree[i].size(); j++) {
        int u = tree[i][j];
        if (!vis[u]) {
            ordTree[i].push_back(u);
            order(u);
        }
    }
}

/*
void order(int i) {

    queue<int> q;
    

    vis[i] = true;
    ord[i] = currentC;
    currentC++;
    q.push(i);

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        for (int j=0; j<tree[i].size(); j++) {
            int u = tree[i][j];
            if (!vis[u]) {

                vis[u] = true;
                ord[u] = currentC;
                currentC++;
                q.push(u);

                //order(u);
            }
        }
    }
}
*/


struct segm {
    pii u;
    pii v;
    segm(pii u_, pii v_) {
        u=u_;
        v=v_;
    }
};

bool operator==(segm a, segm b) {
    return (a.u==b.u && a.v==b.v) || (a.u==b.v && a.v==b.u);
}


bool ccw(pii a, pii b, pii c) {
    return ((b.x-a.x)*(c.y-a.y) > (b.y-a.y)*(c.x-a.x));
}

bool intersecting(segm a, segm b) {
    pii A = a.u;
    pii B = a.v;
    pii C = b.u;
    pii D = b.v;
    return ccw(A,C,D)!=ccw(B,C,D) && ccw(A,B,C)!=ccw(A,B,D);
}

int main() {
    cin >> n;
    for(int a0 = 0; a0 < n-1; a0++){
        // An edge connects nodes 'u' and 'v':
        int u;
        int v;
        cin >> u >> v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int a0 = 0; a0 < n; a0++){
        // Cartesian coordinate:
        int x;
        int y;
        cin >> x >> y;
        points[a0] = pii(x,y);
        ass[a0] = a0;
    }
    /*
        cout << "==================\n";
        for (int i=0; i<n; i++) {
            cout << ass[i] << ": "<< points[ass[i]].x/100 << " " << points[ass[i]].y/100 << '\n';
        }
        */
    //cout << "It is intersecting: " << intersecting(segm(pii(233,829),pii(202,426)), segm(pii(837,952), pii(607,76))) << '\n';
    //
    bool chain = true;
    int leaf;
    for (int i=0; i<n; i++) {
        if (tree[i].size() == 1) {
            leaf = i;
        }
        if (tree[i].size() > 2) {
            chain = false;
            break;
        }
    }
    if ( chain) {
        vector<bool> vis(n,false);
        vector<int> reordering(n);
        int i = leaf;
        int count = 0;
        vis[i] = true;
        reordering[i] = 0;
        do {
            for(int j=0; j<tree[i].size(); j++) {
                int u = tree[i][j];
                if (!vis[u]) {
                    vis[u] = true;
                    i = u;
                    count ++;
                    reordering[i] = count;
                }
            }
        }
        while (tree[i].size() != 1);
        sort(ass, ass+n, assSort);

        for (int i=0; i<n-1; i++) {
            cout << 1+ass[reordering[i]] << " ";
        }
        cout <<1+ ass[reordering[n-1]] << "\n";
        return 0;
    }


    else {

        order(0);

        bool broken = true;
        while (broken) {
            broken = false;
            bool made_improvement = false;
            for (int iia=n; iia>=0; iia--) {
                int ia = invOrd[iia];
                for (int ja=0; ja<tree[ia].size(); ja++) {
                    int ua = tree[ia][ja];
                    for (int iib=iia; iib>=0; iib--) {
                        int ib = invOrd[iib];
                        for (int jb=0; jb<tree[ib].size(); jb++) {
                            int ub = tree[ib][jb];

                            segm a(points[ass[ia]], points[ass[ua]]);
                            segm b(points[ass[ib]], points[ass[ub]]);
                            if ((ia!=ib && ia!=ub && ua!=ib && ua!=ub) && intersecting(a, b)) {
                                /*
                                   cout << "intersection of " << ass[ia] << " " << ass[ua] << " " << ass[ib] << " " << ass[ub] << '\n';

                                   cout << "intersection of:; " << points[ass[ia]].x << " " << points[ass[ia]].y << "   "
                                   << points[ass[ua]].x << " " << points[ass[ua]].y << "\n      "
                                   << points[ass[ib]].x << " " << points[ass[ib]].y << "   "
                                   << points[ass[ub]].x << " " << points[ass[ub]].y << "\n"
                                   ;
                                   */
                                broken = true;

                                int qa;
                                int qb;
                                if (ord[ia]>ord[ua]) {
                                    qa = ia;
                                }
                                else {
                                    qa = ua;
                                }
                                if (ord[ib]>ord[ub]) {
                                    qb = ib;
                                }
                                else {
                                    qb = ub;
                                }

                                int tmp = ass[qa];
                                ass[qa] = ass[qb];
                                ass[qb] = tmp;
                                made_improvement = true;
                            }
                        }
                    }
                }
            }
            if (broken && !made_improvement) {
                cout << "nothing\n";
                return -1;
            }
        }
    }


    for (int i=0; i<n-1; i++) {
        cout << 1+ass[i] << " ";
    }
    cout <<1+ ass[n-1] << "\n";
}
