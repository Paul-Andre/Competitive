#include <bits/stdc++.h>
using namespace std;

// Please don't do any more stupid things like this.

bool traverseStandard(vector<vector<int> > &out, vector<bool> &vis, int i, int nemo) {
    if(i==nemo) return true;
    if(vis[i] == true) return false;


    vis[i] = true;
    for (int j= 0; j< out[i].size(); j++) {
        int v = out[i][j];
        if (traverseStandard(out, vis, v, nemo)) {
            return true;
        }
    }

    return false;
}

bool trav1(vector<vector<int> > &out, vector<bool> &vis, int i, int fish, int nemo, bool found_fish, vector<int> &fill) {
    //cout << "vis ?" << i << endl;

    //cout << "vis " << i << endl;


    if ( i == fish) {
        found_fish = true;
    }
    if (i == nemo && found_fish) {
        return true;
    }

    if (vis[i] == true){
    //fill.push_back(i);
        return false;
    }
    vis[i] = true;

    for (int j= 0; j< out[i].size(); j++) {
        //cout << "j " << j;
        int v = out[i][j];

        //cout << " v " << v << endl;
        vector<int> fille;
        if (trav1(out, vis, v, fish, nemo, found_fish, fille)) {
            return true;
        }
                /*
                fille.insert(fille.end(), fill.begin(), fill.end());
                fill = move(fille);
                */
                fill.insert(fill.end(), fille.begin(), fille.end());
    }

    fill.push_back(i);
    return false;
}


bool traverseFunny(vector<vector<int> > &out, vector<vector<int> > &in, int fish, int nemo) {
    int n = out.size();
    vector<int> fill;
    {
        //cout << "IN \n";
        vector<bool> vis(n, false);
        for (int i=n-1; i>=0; i--) {
            if (!vis[i]) {
                vector<int> fille;
                if (trav1(out, vis, i, fish, nemo, false, fille)) {
                    return true;
                }
                /*
                fille.insert(fille.end(), fill.begin(), fill.end());
                fill = move(fille);
                
                */
                fill.insert(fill.end(), fille.begin(), fille.end());
            }
        }
    }
    cout << "fill: ";
    for (int i=0; i< fill.size(); i++) {
        cout << fill[i] << " " ;
    }
    cout << endl;
    vector<bool> vis2(n, false);
    vector<int> fill2;
        //cout << "OUT \n";
    for (int ii=0; ii<n; ii++) {
        int i = fill[ii];
        //cout << "do " << i << endl;
        if (!vis2[i]) {
            if (trav1(in, vis2, i, nemo, fish, false,fill2 )) {
                return true;
            }
        }
    }

    return false;
}


int main() {
    srand(time(NULL));
    int n = 5;
    while (true) {
        for (int iii=1; iii<=n; iii++) {

            for (int i_=0; i_<100; i_++) {
                vector<int> perm(n);
                for (int i=0; i<n; i++) {
                    perm[i] = i;
                }
                //random_shuffle(perm.begin(), perm.end());

                vector<vector<int> > in(n);
                vector<vector<int> > out(n);

                cout << "===================================\n";
                cout << n << endl;
                cout << iii*3/2 << endl;
                for (int i=0; i<iii*3/2; i++) {
                    int rr1 = rand() % n;
                    int rr2 = rand() % n;

                    int r1 = perm[rr1];
                    int r2 = perm[rr2];

                    if ( r1== r2) {
                        i --;
                        continue;
                    }
                    else if ( rr1 < rr2 ) {
                        cout << r2 << " -> " << r1 << endl;
                        in[r1].push_back(r2);
                        out[r2].push_back(r1);
                    }
                    else {
                        cout << r1 << " -> " << r2 << endl;
                        in[r2].push_back(r1);
                        out[r1].push_back(r2);
                    }

                }
                for (int i=0; i<n; i++) {
                    reverse(in[i].begin(), in[i].end());
                }
                cout << "************************************\n";

                for (int r1 = 0; r1<n; r1++) {
                    for (int r2 = 0; r2<n; r2++) {
                        vector<bool> vis(n, false);

                        bool a1 = 
                            traverseStandard(out, vis, r1, r2);
                        bool a2 = 
                            traverseFunny(out, in, r1, r2);

                        cout << r1 << " -> " << r2  << "   ";
                        if (a1) {
                            cout << "yes  ";
                        }
                        else {

                            cout << "no  ";
                        }

                        if (a2) {
                            cout << "yes\n";
                        }
                        else {

                            cout << "no\n";
                        }

                        if ( a1 != a2 ) {
                            exit(0);
                        }
                    }
                }
            }


        }
    }
}






