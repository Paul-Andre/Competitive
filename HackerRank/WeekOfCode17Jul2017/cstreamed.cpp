#include <bits/stdc++.h>

using namespace std;

int n;
int q;

int A[8000];

unordered_map<int, vector<int>> pos;

vector<int> empty;

typedef pair<int,int> pii;

map<pii, int> cached;

vector<int>& getVec(int x) {
    auto it = pos.find(x);
    if (it == pos.end()) return empty;
    else return it->second;
}

int getFromVec(vector<int> &v, int i) {
    if (i >= v.size()) return n;
    else return v[i];
}


int main() {


    cin >> n >> q;

    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> A[arr_i];
    }

    for(int i = 0; i<n; i++) {
        pos[A[i]].push_back(i);
    }


    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        cin >> x >> y;

        if (x == y) {
            x = y = -1;
        }

        if (cached.find(pii(x,y)) != cached.end()) {
            cout << cached[pii(x,y)] <<endl;
            continue;
        }


        vector<int>& X = getVec(x);
        vector<int>& Y = getVec(y);

        int m = X.size() + Y.size();


        int i=0, j=0;



        int b = max( X.size(), Y.size() );
        vector<int> found(b*2 + 1, 0);


        int first = min(getFromVec(X, 0), getFromVec(Y, 0));

        int tot = 0;
        int acc = 0;

        found[b + 0] = first + 1;
        tot += first*(first+1)/2;
        

        while(i<X.size() && j<Y.size() ) {
            int beep;
            if (X[i] < Y[j]) {
                
                acc --;
                i++;
                beep = min(getFromVec(X,i), getFromVec(Y,j)) - X[i-1];
            }
            else {
                acc ++;
                j++;
                beep = min(getFromVec(X,i), getFromVec(Y,j)) - Y[j-1];
            }

            tot += found[b + acc] * beep;
            tot += beep*(beep-1)/2;
            found[b + acc] += beep;
        }

        while(i<X.size()) {
            acc --;
            i++;

            int beep = getFromVec(X,i) - X[i-1];

            tot += found[b + acc] * beep;
            tot += beep*(beep-1)/2;
            found[b + acc] += beep;

        }

        while(j<Y.size()) {

            acc ++;
            j++;

            int beep = getFromVec(Y,j) - Y[j-1];

            tot += found[b + acc] * beep;
            tot += beep*(beep-1)/2;
            found[b + acc] += beep;
        }


        cached[pii(x,y)] = tot;
        cached[pii(y,x)] = tot;

        cout << tot <<endl;
    }

    return 0;
}

