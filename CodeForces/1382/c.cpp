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
    string A;
    string B;
    cin>>A>>B;
    //cerr<<A << " asdfasdf " << B <<endl;
    vector<int> out;
    bool prev=(A[0]=='1');
    for(int i=1;i<n;i++){
      bool c = A[i]=='1';
      if(c!=prev){
        out.push_back(i-1);
      }
      prev=c;
    }
    if(prev){
      out.push_back(n-1);
    }
    prev=false;
    vector<int> out2;
    for(int i=n-1;i>=0;i--){
      bool c=B[i]=='1';
      if(c!=prev){
        out2.push_back(i);
      }
      prev=c;
    }
    cout<<(out.size()+out2.size())<<"   ";
    for(int a:  out){
      cout<<a+1<<" ";
    }
    cout << "  ";
    for(int a:  out2){
      cout<<a+1<<" ";
    }
    cout<<endl;
  }
}

