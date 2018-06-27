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
        cout << "Put the color " << best_col << " in box " << best_box << " giving " << best_gain << " gains.\n";
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << in[i][j];
        }
        cout << endl;
    }

    cout << candy << endl;
}



