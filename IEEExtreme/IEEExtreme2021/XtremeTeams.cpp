#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=5050, maxm=20, maxs = 1<<20;
int T, n, m; 
char line[maxm];
int full, can[maxn]; 
int s1, s2, s3; 
int cnt[maxs]; 
long long ans ;


int main() {
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        full = (1 << m) - 1;
        s1 = s2 = s3 = 0;
        memset(cnt, 0 , sizeof(cnt)); 
        for (int i = 0; i < n; i++)
        {
            cin >> line; 
            
            for (int j = 0; j < m; j++)
                if (line[j] == 'y')
                    can[i] |= 1 << j;
            if (can[i] == full) s1++; 
            cnt[can[i]]++;
        }
        
        for (int i = 0; i<=full ; i++) {
          cerr << cnt[i] << " ";
        } cerr << endl;

        for (int i = full-1; i ; i--) {
            if (i & (-i)) {
                cnt[i - (i&(-i))] += cnt[i];  
            }
        }

        for (int i = 0; i<=full ; i++) {
          cerr << cnt[i] << " ";
        } cerr << endl;
        
        
        for (int i = 0; i < n; i++)
            //if (can[i] != full) 
                for (int j = 0; j < n; j++)
                    //if (can[j] != full)
                    {
                        int cur = can[i] | can[j];
                        if (cur == full) {
                            s2 += 1;
                        }
                        s3 += cnt[full-cur]; 
                    }
        
   
        ans = (s3 - s1 - s2*6)/6;
        cerr << s1 << " " << s2 << " " << s3 <<endl;
        cout << ans << endl; 
    }
    return 0;
}
