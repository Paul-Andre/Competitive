#include <bits/stdc++.h>
using namespace std;


int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>A(n+1,0);
    vector<vector<int>>B(n+1);
    for (int i=1; i<=n; i++){
      int p;
      cin>>p;
      A[i] = p;
      B[p].push_back(i);
    }
    vector<int [2]>PP(n+1);

    /* for (int i=1; i<=n; i++) { */
    /*   cerr<<i<<":"; */
    /*   for (int j=0; j<B[i].size(); j++) { */
    /*     cerr<<B[i][j]<<" "; */
    /*   }cerr<<endl; */
    /* }cerr<<endl; */

    vector<int> crap;
    bool poss = true;
    for (int i=1; i<=n; i++) {
      vector<int> &v = B[i];
      if(v.size()>2){
        poss = false;
        break;
      }else if(v.size()==2){
        if(crap.size()<2){
          poss = false;
          break;
        }
        int c1 = crap.back();
        crap.pop_back();
        int c2 = crap.back();
        crap.pop_back();
        PP[v[0]][0] = i;
        PP[v[1]][0] = c1;
        PP[v[0]][1] = c2;
        PP[v[1]][1] = i;
      }else if(v.size()==1){
        PP[v[0]][0] = i;
        PP[v[0]][1] = i;
      }else{
        crap.push_back(i);
        crap.push_back(i);
      }
    }
    if (!poss){
      cout<<"NO\n";
    }else {
      cout<<"YES\n";
      for (int i=1; i<=n; i++) {
        cout<<PP[i][0]<<" ";
      } cout<<endl;
      for (int i=1; i<=n; i++) {
        cout<<PP[i][1]<<" ";
      } cout<<endl;
    }
  }
}

