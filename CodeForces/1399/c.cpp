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
    vector<int> W(n);
    for(int i=0;i<n;i++){
      cin>>W[i];
    }
    sort(W.begin(), W.end());
    int bestCnt=0;
    for(int tot=2;tot<=100;tot++){
      int cnt=0;
      int i=0;
      int j=n-1;
      while(i<j){
        int t=W[i]+W[j];
        if(t==tot){
          cnt++;
          i++;
          j--;
        }else if(t<tot){
          i++;
        }else{
          j--;
        }
      }
      bestCnt=max(bestCnt, cnt);
    }
    cout<< bestCnt<<endl;
  }



}

