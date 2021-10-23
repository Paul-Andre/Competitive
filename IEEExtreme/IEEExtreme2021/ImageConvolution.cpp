#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename K> using hset = gp_hash_table<K, null_type>;
template <typename K, typename V> using hmap = gp_hash_table<K, V>;

typedef long long ll;

int T;
int R,C;
int A,B;
char pic[500][500];
char pattern[500][500];

int main() {
  cin>>T;
  while(T--){
    cin>>R>>C;
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        cin>>pic[i][j];
      }
    }
    cin>>A>>B;
    for (int i=0; i<A; i++) {
      for (int j=0; j<B; j++) {
        cin>>pattern[i][j];
      }
    }
    int tot = 0;
    for (int i=0; i<R-A+1; i++) {
      for (int j=0; j<C-B+1; j++) {
        int subtot = 0;
        for (int ii=0; ii<A; ii++) {
          for (int jj=0; jj<B; jj++) {
            int x = i+ii;
            int y = j+jj;
            if (pattern[ii][jj] == '?' || pic[x][y] == pattern[ii][jj]) {
              subtot++;
            }
          }
        }
        if (subtot == A*B) {
          tot++;
        }
      }
    }
    cout <<tot<<endl;
  }

}






