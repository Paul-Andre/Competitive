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


set<int> have;


int main() {


    cin >> n >> q;

    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> A[arr_i];
    }

    for(int i = 0; i<n; i++) {
        pos[A[i]].push_back(i);
        have.insert(A[i]);
    }


    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        cin >> x >> y;

        if (x == y) {
            x = y = -1;
        }

        if (have.find(x) == have.end()) x = -1;
        if (have.find(y) == have.end()) y = -1;

        if (cached.find(pii(x,y)) != cached.end()) {
            cout << cached[pii(x,y)] <<endl;
            continue;
        }


        vector<int>& X = getVec(x);
        vector<int>& Y = getVec(y);

        int m = X.size() + Y.size();


        vector<int> mergedPos(m + 1);
        vector<char> mergedNum(m + 1);

        int i=0, j=0;
        int k = 0;

        while(i<X.size() && j<Y.size() ) {
            if (X[i] < Y[j]) {
                mergedPos[k] = X[i];
                mergedNum[k] = 'x';
                i++;
            }
            else {
                mergedPos[k] = Y[j];
                mergedNum[k] = 'y';
                j++;
            }
            k++;
        }

        while(i<X.size()) {
            mergedPos[k] = X[i];
            mergedNum[k] = 'x';
            i++;
            k++;
        }

        while(j<Y.size()) {
            mergedPos[k] = Y[j];
            mergedNum[k] = 'y';
            j++;
            k++;
        }

        mergedPos[k] = n;
        mergedNum[k] = 'b';


        int tot = 0;
        int acc = 0;

        int b = max( X.size(), Y.size() );

        vector<int> found(b*2 + 1, 0);

        found[b + 0] = mergedPos[0] + 1;
        tot += mergedPos[0]*(mergedPos[0]+1)/2;

        for(int i=0; i<mergedPos.size()-1; i++) {

            if (mergedNum[i] == 'x') {
                acc --;
            }
            else {
                acc ++;
            }

            int beep = mergedPos[i+1] - mergedPos[i];

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

