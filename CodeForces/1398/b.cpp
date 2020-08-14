#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    vector<int> A;
    int cnt=0;
    for(char c: s){
      if(c=='1'){
        cnt++;
      }else{
        if(cnt!=0){
          A.push_back(cnt);
        }
        cnt=0;
      }
    }
    if(cnt!=0){
      A.push_back(cnt);
    }
    sort(A.begin(),A.end());
    int tot=0;
    bool alice=true;
    for(int i=A.size()-1;i>=0;i--){
      int a=A[i];
      if(alice){
        tot+=a;
      }
      alice=!alice;
    }
    cout<<tot<<endl;
  }
}
