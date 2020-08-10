#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Entry{
  int amount;
};


map<int,int> M; //lenght -> amount
multiset<pair<int,int> > P;  //(amount, length)

void ajoute(int x){
  if(M.find(x) == M.end()){
    M[x]=1;
    P.emplace(1,x);
  }else{
    P.erase(make_pair(M[x], x));
    M[x]++;
    P.emplace(M[x],x);
  }
}

void enleve(int x){
  assert(M.find(x) != M.end());
  P.erase(make_pair(M[x], x));
  M[x]--;
  P.emplace(M[x],x);
}


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    ajoute(x);
  }
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    char c;
    cin>>c;
    int x;
    cin>>x;
    if(c=='-'){
      enleve(x);
    }else if(c=='+'){
      ajoute(x);
    }else{
      assert(false);
    }


    /*
    for(auto const &it : P){
      cerr<<it.first<< " " <<it.second <<"   ";
    }
    */

    {
      int a=0,b=0,c=0;
      auto it=P.crbegin();
      if(it!=P.crend()){
        a=it->first;
        it++;
      }
      if(it!=P.crend()){
        b=it->first;
        it++;
      }
      if(it!=P.crend()){
        c=it->first;
        it++;
      }

      if(a>=8 || (a>=6 && b>=2) || (a>=4 && b>=4) || (a>=4 && b>=2 && c>=2)){
        cout << "YES";
      }else{
        cout << "NO";
      }
      cout <<endl;
    }

  }
}

