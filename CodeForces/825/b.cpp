#include <bits/stdc++.h>
using namespace std;

char G[10][10];

char row[10];

void test() {
    for(int i=0; i<=5; i++) {
        map<char, int> m;
        for(int j=0; j<5; j++) {
            m[row[i+j]]++;
        }
        if (m['X']==4 && m['.']==1) {
            cout << "YES\n";
            exit(0);
        }
    }
}

char row2[5];

void test2() {
    int i=0;
    map<char, int> m;
    for(int j=0; j<5; j++) {
        m[row[i+j]]++;
    }
    if (m['X']==4 && m['.']==1) {
        cout << "YES\n";
        exit(0);
    }
}


int main(){
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cin >> G[i][j];
        }
    }

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            row[j] = G[i][j];
        }
        test();
    }
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            row[j] = G[j][i];
        }
        test();
    }

    for(int i=0; i<=5; i++) {
        for(int j=0; j<=5; j++) {
            for(int k=0; k<5; k++) {
                row[k] = G[i+k][j+k];
            }
            test2();
        }
    }

    for(int i=4; i<=9; i++) {
        for(int j=0; j<=5; j++) {
            for(int k=0; k<5; k++) {
                row[k] = G[i-k][j+k];
            }
            test2();
        }
    }

    cout << "NO\n";
}







