#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> pii;

bool seive[50000];

map<int, vector<pii>> s;

int main() {

    for(int i=2; i<50000; i++) {
        if (!seive[i]) {
            for(int j=i*2; j<50000; j+=i) {
                seive[j] = true;
            }
        }
    }

    int n;

    while(cin>>n) {
        vector<int> A(n);

        for(int i=0; i<n; i++) {
            cin >> A[i];
        }

        for(int i=2; i<50000; i++) {
            if (!seive[i]) {
                int cnt = 0;
                for(int j=0; j<n; j++) {
                    if (A[j]%i == 0) {
                        cnt ++;
                    }
                }
                if (cnt >= 2) {
                    for(int j=0; j<n; j++) {
                        while(A[j] %i == 0) {
                            A[j] /= i;
                        }
                    }
                }
            }
        }

        sort(A.begin(), A.end());

        for(int j=0; j<A.size(); j++) {
            cout << A[j] << " ";
        }
        cout << endl;

        vector<int> rep;

        int prev = -10;
        int cnt = 10;
        for(int j=0; j<A.size(); j++) {
            if (A[j] != prev) {
                if (cnt == 1) {
                    rep.push_back(prev);
                }
                cnt = 1;
                prev = A[j];
            }
            else {
                cnt ++;
            }
        }

        if (cnt == 1) {
            rep.push_back(A.back());
        }

        cout << rep.back() << endl;

    }
}

