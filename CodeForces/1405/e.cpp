#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int B[1654321];
int totB=0;
int gett(int i){
  int tot=0;
  while(i!=0){
    tot+=B[i];
    i-=(i&-i);
  }
  return tot;
}
void sett(int i, int a){
  while(i<1654321){
    B[i]+=a;
    i+=(i&-i);
  }
  totB+=a;
}
int findd(int a){
  int acc=0;
  int l=0;
  while(l<1654321){
    int ll=1;
    while(l+ll<1654321){
      if(acc+B[l+ll] > a){
        if(ll==1) return l;
        acc+=B[l+(ll>>1)];
        l=l+(ll>>1);
        break;
      }else{
        ll<<=1;
      }
    }
  }
  assert(l<1654321);
  return -1;
}


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n,q;
  cin>>n>>q;
  vector<int> A(n+1);
  for(int i=1; i<n+1; i++){
    int x;
    cin>>x;
    A[i]=i-x;
  }
  /*
  cerr<<endl;
  for(int i=1; i<n+1; i++){
    cerr<<A[i]<<" ";
  }cerr<<endl;
  */

  map<int,vector<pair<int, int>>> queries;
  vector<int> answers(q,-1);
  for(int i=0; i<q; i++){
    int x,y;
    cin>>x>>y;
    queries[y].push_back(pair<int,int>(x,i));
  }

  int dumb=0;
  for(int i=1; i<=n; i++){
    int a=A[i];
    if(a<0){dumb++;}else{
      if (a==0) {
        sett(i,1);
      }else if(a<=totB) {
        int f = findd(totB-a)+1;
        sett(f,1);
      }
    }
    /*
    for(int j=1;j<=i;j++){
      cerr<<(totB-gett(j-1))<<" ";
    } cerr<<endl;
    */

    int y = (n-i);
    for(auto &p: queries[y]){
      int x=p.first;
      //cerr<<"processing " << x<<" "<<y<<endl;
      int answer_i=p.second;
      answers[answer_i]=totB-gett(x+1-1);
    }
  }
  for(int a: answers){
    cout<<a<<endl;
  }
}

