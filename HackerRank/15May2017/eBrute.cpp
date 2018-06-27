#include <bits/stdc++.h>
using namespace std;

int n,m;
int A[40];
int B[40];
int C[40][40];

#define sqr(x) ((x)*(x))

int coutBits( long a) {
    int tot = 0;
    while(a != 0) {
        tot += a&1;
        a = a>>1;
    }
    return tot;
}


struct Chain {
    int choosen;
    Chain *next;
};

struct Ret{
    int val;
    Chain *chain;
};

Ret brute(int ii, vector<int> &B_fill) {
    if (ii == n) {
        Ret ret;
        ret.val = 0;
        ret.chain = nullptr;
        return ret;
    }
    int best = -12343453;
    Chain * bestChain = new Chain;

    for (long i=0; i<(1<<m); i++) {
        if (coutBits(i) <= A[ii]) {
        //cout << ii << " " << i << " ii i \n";
            int gain = 0;
            for (int j=0; j<m; j++) {
                if ((i>>j)&1) {

                    gain += C[ii][j];

                    if ( B_fill[j] >= B[j]) {
                        gain += - sqr(B_fill[j]-B[j]+1) + sqr(B_fill[j] - B[j]);
                    }

                    B_fill[j] += 1;
                }
            }

            Ret rec = brute(ii+1, B_fill);

            gain += rec.val;

            if ( best < gain) {
                best = gain;
                bestChain->choosen = i;
                bestChain->next = rec.chain;
            }

            for (int j=0; j<m; j++) {
                B_fill[j] -= ((i>>j)&1);
            }
        }
    }
    //cout << best << " best\n";

    Ret ret;
    ret.val = best;
    ret.chain = bestChain;
    return ret;
}
        


int main() {
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> A[i];
    }
    for (int i=0; i<m; i++) {
        cin >> B[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> C[i][j];
        }
    }


    vector<int> B_fill(m, 0);
    Ret candy = brute(0, B_fill);

    /*
    while(tot_balls > 0) {
        int best_col = -1;
        int best_box = -1;
        int best_gain = -1243453;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!in[i][j] && A_fill[i] < A[i]) {
                    int gain = C[i][j];
                    if ( B_fill[j] >= B[j]) {
                        gain += - sqr(B_fill[j]-B[j]+1) + sqr(B_fill[j] - B[j]);
                    }
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
    }
    */

    Chain *c = candy.chain;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << (((c->choosen)>>j)&1);
        }
        c = c->next;
        cout << endl;
    }



    cout << candy.val << endl;
}



