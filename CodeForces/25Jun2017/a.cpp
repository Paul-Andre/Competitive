#include <bits/stdc++.h>
using namespace std;


int n;
int hor[50][50];
int orig[50][50];
int ver[50][50];


int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int in;
            cin >> in;
            orig[i][j] = in;
            hor[i][j] = in;
            ver[j][i] = in;
        }
    }

    for(int i=0; i<n; i++) {
        sort(hor[i], hor[i]+n);
        sort(ver[i], ver[i]+n);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int a = orig[i][j];
            if(a==1) continue;

            int x = 0;
            int y = n-1;

            while(x<n && y>=0) {
                int s = hor[i][x] + ver[j][y];
                if(s==a) {
                    goto continue_outer;
                }
                if(s< a) {
                    x++;
                }
                if(s>a) {
                    y--;
                }
            }

            cerr << i << " " << j << endl;
            cout << "No\n";
            exit(0);

continue_outer:;
        }
    }

    cout << "Yes\n";
    exit(0);


}
    

