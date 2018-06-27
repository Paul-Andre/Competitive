#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

pair<int, pair<int, int> > mT(int x, int y, int z) {
    return make_pair(x, make_pair(y, z));
}

typedef pair<int, pair<int, int> > T;

map<T, vector<T> > ds;
map<T, vector<T> > ts;

map<T, int> dv;
map<T, int> tv;

bool visit(T d,  map<T, vector<T> > &ds, map<T, int> &dv) {

    for (int i=0; i< ds[d].size(); i++) {
        T dd = ds[d][i];
        int vdd = dv[dd];
        int vd = dv[d];

        if (vdd == 0) {
            dv[dd] = vd+1;
            bool v = visit(dd, ds, dv);
            if (v) {
                return true;
            }
        }
        else if ( vdd < vd - 1) {
            return true;
        }
    }

    return false;
}

bool inspect( map<T, vector<T> > &ds, map<T, int> &dv) {
    for (auto it = ds.begin(); it != ds.end(); it++) {
        T d = it->first;
        if (dv[d] == 0) {
            dv[d] = 1;
            bool v = visit(d, ds, dv);
            if (v) return true;
        }
    }
    return false;
}


int main() {
    int K;
    cin >> K;

    for (int i=0; i< K; i++) {
        int ax, ay, az, bx, by, bz;
        cin >> ax >> ay >> az >> bx >> by >> bz;
        T at = mT(ax,ay, az);
        T bt = mT(bx,by, bz);
        T ad = mT(ax,ay, 0);
        T bd = mT(bx,by, 0);

        ds[ad].push_back(bd);
        ds[bd].push_back(ad);

        ts[at].push_back(bt);
        ts[bt].push_back(at);
    }


    if (inspect(ts,tv)) {
        cout << "True closed chains\n";
    }
    else {
        cout << "No true closed chains\n";
    }

    if (inspect(ds,dv)) {
        cout << "Floor closed chains\n";
    }
    else {
        cout << "No floor closed chains\n";
    }
}

