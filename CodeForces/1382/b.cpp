#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
      cin>>A[i];
    }
    bool prevWin=false;
    int turns=0;
    for(int i=n-1;i>=0;i--){
      int a=A[i];

      if(prevWin){
        if(a>1){
          turns+=2;
          prevWin=true;
        }else{
          turns+=1;
          prevWin=false;
        }
      }else{
        turns+=1;
        prevWin=true;
      }
      //cerr << "a pw t " << a << " " << prevWin << " " << turns << endl;
    }

    if(prevWin){
      cout<<"First\n";
    }else{
      cout<<"Second\n";
    }
  }

}

