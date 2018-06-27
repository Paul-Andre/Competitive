#include <bits/stdc++.h>
using namespace std;

int n,m;
int A[100];


void out() {
    cout << "-1\n";
    exit(0);
}


int main() {
    cin >> n >>m;
    vector<int> ass(n+1, 0);
    vector<bool> used(n+1, false);
    int prev;
    cin >> prev;
    for(int i=0; i<m-1; i++) {
        int next;
        cin >> next;
        int get = ((next-prev-1) % n + n) % n + 1;
        cerr << "get " << get << endl;
        if(ass[prev] == 0) {
            if (!used[get]) {
                ass[prev] = get;
                used[get] = true;
            }
            else out();
        }
        else if (ass[prev] != get) out();

        prev = next;
    }

    vector<int> un;

    for(int i=1; i<=n; i++) {
        if(!used[i]) un.push_back(i);
    }

    for(int i=1; i<=n; i++) {
        if(ass[i] == 0) {
            ass[i] = un.back();
            un.pop_back();
        }
    }
    for(int i=1; i<=n; i++) {
        cout << ass[i] << " ";
    }
}

        

