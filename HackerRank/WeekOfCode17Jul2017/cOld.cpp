#include <bits/stdc++.h>

using namespace std;


int cnt[20000];

int main() {
    int n;
    int q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }


    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        cin >> x >> y;

        for(int i=0; i<20000; i++) cnt[i] = 0;

        cnt[10000 + 0] = 1;

        int acc = 0;

        long long tot = 0;

        for(int i=0; i<n; i++) {
            if (arr[i] == x) acc--;
            if (arr[i] == y) acc++;

            tot += cnt[10000 + acc];
            cnt[10000 + acc] ++;
        }

        cout << tot <<endl;
    }
    return 0;
}
