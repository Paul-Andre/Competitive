#include <bits/stdc++.h>

using namespace std;

int getMaxMonsters(int n, int hit, int t, vector < int > &h){
    for(int i=0; i<n; i++) {
        h[i] = (h[i] + hit - 1)/hit;
        //cout << h[i] << " ";
    }
    sort(h.begin(), h.end());
    /*
    for(int i=0; i<n; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
    */
    int i=0;
    int tot = 0;
    while(t>0 && i<n) {
        if (t>=h[i]){
            t-=h[i];
            i++;
            tot++;
        }
        else {
            break;
        }
    }
    return tot;
}

int main() {
    int n;
    int hit;
    int t;
    cin >> n >> hit >> t;
    vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }
    int result = getMaxMonsters(n, hit, t, h);
    cout << result << endl;
    return 0;
}
