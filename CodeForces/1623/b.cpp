#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int ttt;
  cin>>ttt;
  while(ttt--){
    int n;
    cin>>n;
    vector<pair<int,int>> ran;
    for (int i=0; i<n; i++) {
      int l,r;
      cin>>l>>r;
      ran.emplace_back(l,r);
    }
    sort(ran.begin(), ran.end(), [](pair<int,int> a, pair<int,int> b){
        return (a.second-a.first)>(b.second-b.first);
        });
    //cerr<<ran[0].first<<" "<<ran[0].second<<endl;
    vector<bool> seen(n+1, false);
    for(int i=0; i<n; i++) {
      for(int j=i-1; j>=0; j--) {
        int al = ran[j].first;
        int ar = ran[j].second;
        int bl = ran[i].first;
        int br = ran[i].second;
        if (al<=bl && br<=ar) {
          int c;
          assert(al==bl || br==ar);
          if (al==bl) {
            c = br+1;
          } else {
            c = bl-1;
          }
          if (!seen[c]) {
            cout << al << " " << ar << " " << c <<endl;
            seen[c]=true;
          }
          break;
        }
      }
    }
    for(int i=0; i<n; i++) {
      int bl = ran[i].first;
      int br = ran[i].second;
      if (bl==br) {
        cout << bl<<" "<<bl<<" "<<bl<<endl;
      }
    }
    cout<<endl;
  }
}
