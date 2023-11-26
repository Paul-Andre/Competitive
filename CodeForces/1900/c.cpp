#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;

int L[312345];
int R[312345];
ll best[312345];

string s;

void recurse(int i) {
  if (i==0) {
    return;
  }
  int l = L[i];
  int r = R[i];
  if (l==0 and r==0){
    best[i] = 0;
    return;
  }
  recurse(l);
  recurse(r);

  char c = s[i];
  ll l_add =c!='L';
  ll r_add =c!='R';
  best[i] = min(best[l]+l_add, best[r]+r_add);
}
  


int main() {
  int t;
  cin>>t;
  for (int ttt=0; ttt<t;ttt++) {
    int n;
    cin>>n;
    cin>>s;
    s = " "+s;

    for (int i=1; i<=n; i++) {
      int l,r;
      cin>>l>>r;
      L[i] = l;
      R[i] = r;
      best[i] = 312345;
    }
    best[0] = 312345;

    recurse(1);
    /* for (int i=0; i<=n; i++) { */
    /*   cerr<<L[i]<<R[i]<<best[i]<<" "; */
    /* } */
    /* cerr<<endl; */
    cout <<best[1]<<endl;
  }
}







