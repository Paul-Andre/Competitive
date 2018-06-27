#include <bits/stdc++.h>
using namespace std;

int n,m;
int A[100];
int B[100];
int C[100][100];

bool in[100][100];
int A_fill[100];
int B_fill[100];

#define sqr(x) ((x)*(x))

int main() {
    cin >> n >> m;

    int tot_balls;
    for (int i=0; i<n; i++) {
        cin >> A[i];
        tot_balls += A[i];
    }
    for (int i=0; i<m; i++) {
        cin >> B[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> C[i][j];
        }
    }

    int candy = 0;

    while(true) {
        int best_col = -1;
        int best_box = -1;
        int best_gain = -1243453;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!in[i][j] && A_fill[i] < A[i]) {
                    int gain = C[i][j];
                    /*
                    if ( B_fill[j] >= B[j]) {
                        gain += - sqr(B_fill[j]-B[j]+1) + sqr(B_fill[j] - B[j]);
                    }
                    */
                    if (gain > best_gain) {
                        best_gain = gain;
                        best_col = i;
                        best_box = j;
                    }
                }
            }
        }
        if (best_gain < 0) {
            break;
        }
        candy += best_gain;
        in[best_col][best_box] = true;
        A_fill[best_col] ++;
        B_fill[best_box] ++;
        //cout << "Put the color " << best_col << " in box " << best_box << " giving " << best_gain << " gains.\n";
    }

    //cout << candy << '\n';
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << in[i][j];
        }
        cout << endl;
    }

    bool changed = true;
    while(changed) {
        changed = false;

        for (int i=0; i<n; i++) {
            int best_no = -12341124;
            int best_yes = -12314124;
            int best_no_j;
            int best_yes_j;
            for (int j=0; j<m; j++) {
                int diff = B_fill[j] - B[j];
                if (in[i][j]){

                    int neww;
                    if (diff > 0) {
                        neww = sqr(diff) - sqr(diff-1) - C[i][j];
                    }
                    else {
                        neww = -C[i][j];
                    }

                    if ( best_yes < neww) {
                        best_yes = neww;
                        best_yes_j = j;
                    }
                }

                if (!in[i][j]) {
                    int neww;
                    if (diff < 0) {
                        neww = C[i][j];
                    }
                    else {
                        neww =  C[i][j] - sqr(diff+1) + sqr(diff);
                    }
                    if ( best_no < neww) {
                        best_no = neww;
                        best_no_j = j;
                    }
                }
            }
            int tot = best_no + best_yes;
            if ( tot > 0 ) {
                changed = true;
                candy += tot;
                B_fill[best_no_j]++;
                B_fill[best_yes_j]--;
                in[i][best_no_j] = true;
                in[i][best_yes_j] = false;
                //cout << "flipp color " << i << " from "<< best_yes_j << " to " << best_no_j << " with gain " << tot << ".\n";
            }
        }
    }
    cout << "==========================" << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << in[i][j];
        }
        cout << endl;
    }
    cout << "==========================" << endl;

    int newCandy = 0;

    for (int j=0; j<m; j++) {
        vector<pair<int,int>> these;
        for (int i=0; i<n; i++) {
            if ( in[i][j]) {
                these.push_back(pair<int,int>(C[i][j],i));
            }
        }
        sort(these.begin(), these.end(), greater<pair<int,int> >());
        int gain = 0;
        for (int i=1; i<these.size(); i++) {
                these[i].first += these[i-1].first;
        }
        for (int i=0; i<these.size(); i++) {
            if ( i+1>= B[j]) {
                these[i].first -= sqr(i+1-B[j]);
            }
        }
        int prev = -1223124;
        int i=0;
        for (; i<these.size(); i++) {
            if (these[i].first > prev) {
                prev = these[i].first;
            }
            else {
                break;
            }
        }
        for(; i<these.size(); i++) {
            in[these[i].second][j] = false;
        }

        newCandy += prev;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << in[i][j];
        }
        cout << endl;
    }

    cout << newCandy << endl;
}



