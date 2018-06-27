#include <bits/stdc++.h>
using namespace std;


int n;

int A[100000];
vector<int> where[100010];

typedef long long ll;

ll bit[100001];

void add(int i) {
    i++;
    while(i<=n) {
        bit[i]++;
        i += i & -i;
    }
}

void sub(int i) {
    i++;
    while(i<=n) {
        bit[i]--;
        i += i & -i;
    }
}

ll qer(int i) {
    i++;
    ll res = 0;
    while(i>0) {
        res += bit[i];
        i -= i & -i;
    }
    return res;
}


ll quer(int a, int b) {
    if (a==0) return qer(b);
    return qer(b) - qer(a-1);
}

ll query(int start, int length) {
    if (start+ length <= n) {
        return quer(start, start+length-1);
    }
    else {
        return quer(start, n-1) + quer(0, start+length-n-1);
    }
}

ll querier(int a, int b) {
    int l = ((b-a)%n+n)%n+1;
    //cerr << a << " " << b << " " << l <<endl;
   return query(a, l);
}


int ss(int a, int b) {
    return A[a] < A[b];
}

int now = 0;

bool sss(int a, int b) {
    return ((a-now)%n+n)%n < ((b-now)%n+n)%n;
}

int main() {
    cin >>n;
    for(int i=0; i<n;i++) {
        cin>>A[i];
        where[A[i]].push_back(i);
        add(i);
    }


    ll tot = 0;


    for(int i=0; i<100010; i++) {
        sort(where[i].begin(), where[i].end(), sss);
        for(int j=0; j<where[i].size(); j++) {
            tot +=  querier(now, where[i][j]);
            //cerr << tot <<endl;
            sub(where[i][j]);
            now = where[i][j];
        }
    }

    cout <<tot<<endl;
}
