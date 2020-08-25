#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int x;
string s;
string w;
int n;
vector<bool> doing;

bool thing(int i);
bool put(int i, char a);
bool put(int i, char a){
  if(w[i]==a)return true;
  if (w[i]!='_') return false;
  char prev=w[i];
  w[i]=a;
  if (thing(i+x) && thing(i-x)){
    return true;
  }else{
    w[i]=prev;
    return false;
  }
}

bool thing(int i){
  cerr << i << " " << w<<endl;
  bool ret;
  if(i<0 || i>=n) return true;
  if(doing[i])return true;
  doing[i]=true;

  char c=s[i];
  int j=i-x;
  int k=i+x;
  if(j<0 && k>=n){
    if(c!='0'){
      ret= false;
      doing[i]=false;
      return ret;
    }else{
      ret= true;
      doing[i]=false;
      return ret;
    }
  }else if(j<0){
    ret= put(k,c);
    doing[i]=false;
    return ret;
  }else if(k>=n){
    ret= put(j,c);
    doing[i]=false;
    return ret;
  }

  if(c=='0'){
    ret= put(k,'0') && put(j,'0');
    doing[i]=false;
    return ret;
  }else{
    ret= (put(k,'0') && put(j,'1'))
      || (put(k,'1') && put(j,'0'))
      || (put(k,'1') && put(j,'1'));
    doing[i]=false;
    return ret;
  }
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    cin>>s;
    cin>>x;
    w=string(s.size(),'_');
    n=s.size();
    doing=vector<bool>(n,false);
    bool good=true;
    for(int i=0;i<n;i++){
      int x = thing(i);
      cerr<<i<<" "<<x<<" "<<w<<endl;
      good&=x;
      //if(!good)break;
    }

    if(!good){
      cout<<"-1\n";
    }else{
      for(int i=0;i<n;i++){
        if(w[i]=='_'){
          w[i]='0';
        }
      }
      cout<<w<<endl;
    }
  }
}
