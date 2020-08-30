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
    vector<int> A(n);
    for(int i=0;i<n;i++){
      cin>>A[i];
    }
    int tot=0;
    for(int a:A){
      tot+=a;
    }
    bool figured=false;
    for(int a:A){
      if(a>tot-a){
        cout<<"T\n";
        figured=true;
        break;
      }
    }
    if(!figured){
      if(tot%2==0){
        cout<<"HL\n";
      }else{
        cout<<"T\n";
      }
    }
  }
}
