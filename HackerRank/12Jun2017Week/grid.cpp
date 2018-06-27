#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// [n][m]
char G[318][100001];

int zct[318][100001];

int sum[318][100001];

int parod[318][100001];

int org[1024];

int bbb[11];

int getParod(int l, int r, int t, int b) {
    return parod[r][b] ^ parod[r][t-1] ^ parod[l-1][b] ^ parod[l-1][t-1];
}

bool getCorrect(int l, int r, int t, int b) {
    int z = zct[r][b] - zct[r][t-1] - zct[l-1][b] + zct[l-1][t-1];
    int o = sum[r][b] - sum[r][t-1] - sum[l-1][b] + sum[l-1][t-1];
    return ((z<=1) || o>=2);
}

void printBin(int b) {
    while(b!=0) {
        cerr<<(b&1);
        b = b>>1;
    }
}


int main() {
    int n;
    int m;
    cin >> n >> m;
    bool inv = false;

    for (int i=0; i<10; i++) {
        bbb[i] = 1<<i;
    }

    if (n < m)  {

        for(int table_i = 0;table_i < n;table_i++){
            for(int table_j = 0;table_j < m;table_j++){
                cin >> G[table_i+1][table_j+1];
            }
        }

    }
    else {
        inv = true;
        for(int table_i = 0;table_i < n;table_i++){
            for(int table_j = 0;table_j < m;table_j++){
                cin >> G[table_j+1][table_i+1];
            }
        }
        int tmp = n;
        n = m;
        m = tmp;
    }
    for(int table_i = 0;table_i <= n;table_i++){
        for(int table_j = 0;table_j <= m;table_j++){
            G[table_i][table_j] -= '0';
        }
    }


    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
                zct[i][j] = zct[i-1][j] + zct[i][j-1] - zct[i-1][j-1] + (int)(G[i][j] == 0);
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (int)(G[i][j] != 0);

                parod[i][j] = parod[i-1][j] ^ parod[i][j-1] ^ parod[i-1][j-1] ^ bbb[(int)G[i][j]];
                
        }
    }

    ll best = 1;
    int bl = 1;
    int br = 1;
    int bt = 1;
    int bb = 1;

    /*
    cerr << "n " << n << endl;

    cerr << "m " << m << endl;
    */

    for(int l=1; l<=n; l++) {
        for (int r=l; r<=n; r++) {
            //cerr << "l r " << l << " "<< r << endl;

            for(int k=0; k<1024; k++) {
                org[k] = -1;
            }
            org[0] = 0;

            for (int b=1; b<=m; b++) {
                //cerr << "b " << b << endl;

                int get = getParod(l, r, 1, b);
                //cerr << "get  ";
                //printBin(get);
                //cerr <<endl;

                for(int i=0; i<11; i++) {
                    int search = get^bbb[i];
                    if (org[search] != -1) {
                        int t = org[search]+1;
                        if (getCorrect(l, r, t, b)) {
                            ll newA = ll(r-l+1) * (b-t + 1);
                            if (newA > best) {
                                /*
                                cerr << "Found good " << l << " "<< r << " " << t << " " << b << " with mask ";
                                printBin(bbb[i]);
                                cerr << " searched as ";
                                printBin(search);
                                cerr <<endl;
                                */
                                best = newA;
                                bl = l;
                                br = r;
                                bt = t;
                                bb = b;
                            }
                        }
                    }
                }

                if (org[get] == -1) {
                    org[get] = b;
                }
            }
        }
    }

    bb--;
    bt--;
    bl--;
    br--;

    cout << best << endl;
    if (!inv) {
        //cerr << "!inv\n";
        cout << bl << " "<< bt << " " << br << " " << bb << endl;
    }
    else {
        cout << bt << " "<< bl << " " << bb << " " << br << endl;
    }

    return 0;
}
