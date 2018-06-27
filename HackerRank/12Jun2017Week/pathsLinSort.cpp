#include <bits/stdc++.h>

using namespace std;

int n;
int q;

string p;
string rp;
int ps;


char letters[100001];
vector<int> novel[100001];


bool visr[100001];

vector<int> goDown;

int parent[100001][18];
int depth[100001];

vector<int> childs[100001];

void root(int i, int d) {
    ////cerr << "While rooting visiting " << i << " at depth " << d << endl;
    visr[i] = true;
    depth[i] = d;
    for(int n = 0; (1<<n) <= goDown.size(); n++) {
        parent[i][n] = goDown[goDown.size() - (1<<n)];
    }
    goDown.push_back(i);

    for(int j=0; j< novel[i].size(); j++) {
        int u = novel[i][j];
        if (!visr[u]) {
            root(u, d+1);
            childs[i].push_back(u);
        }
    }
    goDown.pop_back();
}


int goUp(int u, int s) {
    for(int n=17; s>0 && n>=0; n--) {
        if ((1<<n)<=s) {
            u = parent[u][n];
            s -= (1<<n);
        }
    }
    return u;
}



int lca(int u, int v) {
    //cerr << "The lca of " << u << " and " << v;
    //cerr << " of depth " << depth[u] << ", " << depth[v];
    if (depth[u] < depth[v]) {
        int tmp = v;
        v = u;
        u = tmp;
    }

    u = goUp(u, depth[u]-depth[v]);

    //cerr << " ( " << u << " and " << v << " ) " << " is: " ;

    if (u == v) {
        //cerr << u <<endl;
        return u;
    }

    for(int n=17; n>=0; n--) {
        if ( parent[u][n] != parent[v][n]) {
            u = parent[u][n];
            v = parent[v][n];
            //cerr << " (do " << u << " " << v  << ") ";
        }
    }

    //cerr << parent[u][0] <<endl;
    return parent[u][0];
}

typedef pair<int, int> pii;

int suffixArr[100000];
int ordering[100000];

int invOrd[100001];

pii pairs[100001];

bool firstSort(int a, int b) {
    return letters[a] < letters[b];
}


bool afterWards(int a, int b) {
    return pairs[a] < pairs[b];
}


int cmpString(string &s, int u) {
    for(int i=0; i<s.size(); i++, u = parent[u][0]) {
        if (s[i] < letters[u]) {
            return -1;
        }
        else
        if (s[i] > letters[u]) {
            return 1;
        }
    }
    if (letters[u] != '\0') {
        return -1;
    }
    return 0;
}



int markUp[100001];
int markDown[100001];


int findPlace(string &s) {
    if (cmpString(s, suffixArr[n-1]) > 0) {
        return n;
    }
    int a = 0;
    int b = n-1;
    while(a!=b) {
        int c= (a+b)/2;
        int res = cmpString(s, suffixArr[c]);
        if ( 0 < res ) {
            a = c+1;
        } else {
            b = c;
        }
    }
    return a;
}


void doMarking(string &s, int *ar) {
    int l = findPlace(s);
    s[s.size()-1] ++;
    int r = findPlace(s)-1;
    s[s.size()-1] --;

    for(int i=l; i<=r; i++) {
        int r = suffixArr[i];
        ar[r]++;
        /*
        cerr << r  << " marking this: ";
        while(r != 0) {
            cerr << letters[r];
            r = parent[r][0];
        }
        cerr << endl;
        */
    }
}


void stretchMarkings(int i, int *ar, int ft) {
    ar[i] += ft;
    for(int j=0; j<childs[i].size(); j++) {
        int u = childs[i][j];
        stretchMarkings(u, ar, ar[i]);
    }
}

// KMP table
int T[101];


int countSub(vector<char> &s) {
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


int main() {
    cin >> n >> q;

    for(int i=1; i<=n; i++) {
        cin >> letters[i];
    }

    cin >> p;
    ps = p.size();

    rp = p;
    reverse(rp.begin(), rp.end());

    //cerr << rp;

    for(int a0 = 0; a0 < n-1; a0++){
        int u;
        int v;
        cin >> u >> v;
        novel[u].push_back(v);
        novel[v].push_back(u);
    }

    root(1, 1);

    for(int i=0; i<n; i++) {
        suffixArr[i] = i+1;
    }

    sort(suffixArr, suffixArr+n, firstSort);

    ordering[0] = 1;
    for(int i=0; i<n; i++) {
        ordering[i] = ordering[i-1] + (int)(letters[ suffixArr[i] ] != letters[ suffixArr[i-1] ]);
    }
    for(int i=0; i<n; i++) {
        invOrd[suffixArr[i]] = ordering[i];
    }

    for (int l=0; l<=17; l++) {
        for(int i=1; i<=n; i++) {
            pairs[i] = pii(invOrd[i], invOrd[ parent[i][l] ] );
        }

        // TODO: linear sort
        // sort(suffixArr, suffixArr+n, afterWards);
        /*
           bool afterWards(int a, int b) {
            return pairs[a] < pairs[b];
           }
        */

        vector<int> ct1(n+1, 0);
        vector<int> ct2(n+1, 0);

        for(int i=1; i<=n; i++) {
            ct1[pairs[i].first] ++;
            ct2[pairs[i].second] ++;
        }

        /*
        for(int i=0; i<=n; i++) {
            cerr << ct1[i] << " " ;
        }
        cerr << endl;
        */


        ct1[0]--;
        ct2[0]--;
        for(int i=1; i<=n; i++) {
            ct1[i] += ct1[i-1];
            ct2[i] += ct2[i-1];
        }

        /*
        for(int i=0; i<=n; i++) {
            cerr << ct1[i] << " " ;
        }
        cerr << endl;
        */

        vector<int> swapper(n);

        for(int i=1; i<=n; i++) {
            pii p = pairs[i];
            int s = p.second;
            swapper[ ct2[s] ] = i;
            ct2[s]--;
        }

        /*
        cout << "Second:  ";
        for(int i=0; i<n; i++) {
            pii p = pairs[swapper[i]];
            cout << "("<<p.first << "," << p.second << ") ";
        }
        cout << endl;
        */

        for(int i=n-1; i>=0; i--) {
            pii p = pairs[swapper[i]];
            int s = p.first;
            suffixArr[ ct1[s] ] = swapper[i];
            ct1[s]--;
        }

        /*
        cout << "First:  ";
        for(int i=0; i<n; i++) {
            pii p = pairs[suffixArr[i]];
            cout << "("<<p.first << "," << p.second << ") ";
        }
        cout << endl;
        */



        ordering[0] = 1;
        for(int i=1; i<n; i++) {
            ordering[i] = ordering[i-1] + (int)(pairs[ suffixArr[i] ] != pairs[ suffixArr[i-1] ]);
        }

        for(int i=0; i<n; i++) {
            invOrd[suffixArr[i]] = ordering[i];
        }
    }

    
    

    doMarking(p, markUp);
    doMarking(rp, markDown);

    stretchMarkings(1, markUp, 0);
    stretchMarkings(1, markDown, 0);

    
    /*
    for (int i=0; i< n; i++) {
        int r = suffixArr[i];
        cerr << r  << " " << markUp[r] << " " << markDown[r] << " ";
        while(r != 0) {
            cerr << letters[r];
            r = parent[r][0];
        }
        cerr << endl;
    }
    */
    


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



    for(int a0 = 0; a0 < q; a0++){
        int u;
        int v;
        cin >> u >> v;

        int uv = lca(u, v);

        int ut = goUp(u, depth[u] - depth[uv] - ps + 2);
        int vt = goUp(v, depth[v] - depth[uv] - ps + 2);

        //cerr << " u v uv ut vt " << u << " " <<v << " "<< uv << " " << ut << " "<<  vt << endl;

        int tot = markUp[u] - markUp[ut] + markDown[v] - markDown[vt];

        int sss = depth[ut] - depth[uv]  + depth[vt] - depth[uv] + 1;
        vector<char> ss(sss);
        int i = 0;
        while(ut!= uv) {
            ss[i] = letters[ut];
            ut = parent[ut][0];
            i ++;
        }
        ss[i] = letters[uv];

        i = 0;
        while(vt!= uv) {
            ss[ss.size()-1 - i] = letters[vt];
            vt = parent[vt][0];
            i ++;
        }

        tot += countSub(ss);

        cout << tot << endl;

    }
    return 0;
}

