#include <bits/stdc++.h>

using namespace std;

int n;
int q;

string p;
string rp;
int ps;


char letters[100001];
vector<int> novel[100001];


// KMP table
int T[101];


int countSub(vector<char> &s) {

    /*
    cerr << "Searching whithin ";
    for(int i=0; i<s.size(); i++) {
        cerr << s[i];
    }
    cerr << endl;
    */


    int m = 0;
    int i = 0;
    int count = 0;
    while(m+i < s.size()) {
        if (p[i] == s[m+i]) {
            i++;
            if (i == ps) {
                count++;
                m = m+i - T[i];
                i = T[i];
            }
        }
        else {
            if (T[i] > -1) {
                m = m + i - T[i];
                i = T[i];
            }
            else {
                m = m + i + 1;
                i = 0;
            }
        }
    }

    return count;
}

vector<char> goingDown;

int vis[100001];

bool go(int i, int goal) {
    vis[i] = true;
    goingDown.push_back(letters[i]);

    if (i == goal) {
        return true;
    }

    for(int j=0; j<novel[i].size(); j++) {
        int u = novel[i][j];
        if (!vis[u]) {
            if (go(u, goal) ){
                return true;
            }
        }
    }

    goingDown.pop_back();
    return false;
}



int main() {
    cin >> n >> q;

    for(int i=1; i<=n; i++) {
        cin >> letters[i];
    }

    cin >> p;
    ps = p.size();

    rp = p;
    reverse(rp.begin(), rp.end());

    //cerr << "Looking for " << p << endl;

    for(int a0 = 0; a0 < n-1; a0++){
        int u;
        int v;
        cin >> u >> v;
        novel[u].push_back(v);
        novel[v].push_back(u);
    }



    T[0] = -1;
    int pos = 1;
    int cnd = 0;

    while(pos< p.size()) {
        if (p[pos] == p[cnd]) {
            T[pos] = T[cnd];
            pos++;
            cnd++;
        }
        else {
            T[pos] = cnd;

            while( cnd >= 0 && p[pos] != p[cnd]) {
                cnd = T[cnd];
            }

            pos ++;
            cnd ++;
        }
    }

    T[pos] = cnd;

    assert(T[pos] != -1);

    /*
    for(int i=0; i<=p.size(); i++) {
        cerr << T[i] << " ";
    }
    cerr << endl;
    */



    for(int a0 = 0; a0 < q; a0++){
        int u;
        int v;
        cin >> u >> v;

        for(int i=1; i<=n; i++) {
            vis[i] = false;
        }
        goingDown = vector<char>();

        assert(go(u, v));

        int tot = countSub(goingDown);

        cout << tot << endl;
    }
    return 0;
}

