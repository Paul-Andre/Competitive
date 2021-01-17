#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--) {
    int n, k, d;
    cin>>n>>k>>d;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) {
      int k;
      cin>>k;
      a[i]=k;
    }
    int have=0;
    map<int,int> hh;
    int i=1;
    for(; i<=d; i++){
      int aa = a[i];
      if (hh[aa] == 0) {
        have++;
      }
      hh[aa]++;
    }
    int mm = have;
    for (; i<=n; i++) {
      int aa = a[i];
      if (hh[aa] == 0) {
        have++;
      }
      hh[aa]++;
      int bb = a[i-d];
      if (hh[bb] == 1) {
        have--;
      }
      hh[bb]--;
      mm = min(mm, have);
    }
    cout << mm << endl;
  }
}




