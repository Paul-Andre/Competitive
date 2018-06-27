#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<int,int> pii;
typedef pair<pii,int > piii;

set<piii> found;

int n;
ll geometricTrick(string s){
    ll tot = 0;
    for (int i=1; i*i<=n; i++) {
        for (int j=1; j*j<=n; j++) {
            int ii = i*i;
            int jj = j*j;
            for(int k=1; k*ii<=n && k*jj<=n; k++){
                int b = i*j*k-1;
                int a = ii*k-1;
                int c = jj*k-1;
                    //cout << a+1 << " " << b+1 << " " << c+1 << endl;
                if (s[a]=='a' && s[b]=='b' && s[c] == 'c'){
                    piii pp = piii(pii(a,b), c);
                    if (found.find(pp) == found.end()) {
                        found.insert(pp);
                        tot ++;
                    }
                }
            }
        }
        
    }
    
    return tot;
}

int main() {
    cin >> n;
    string s;
    cin >> s;
    ll result = geometricTrick(s);
    cout << result << endl;
    return 0;
}

