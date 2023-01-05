#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


#define SS 40000
bool seive[SS];

vector<int> primes;

int main() {
  for (int i=2; i<SS; i++) {
    if (not seive[i]){
      primes.push_back(i);
    }
    for (int j=i+i; j<SS; j+=i) {
      seive[j] = true;
    }
  }
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> A(n);
    for(auto &a: A)cin>>a;
    set<int> seen;
    bool dub = false;
    /* for (int a:A){ */
    /*   cerr<<a<<" "; */
    /* }cerr<<"\n"; */
    for (int a:A){
      for (int p:primes){
        if (a%p==0){
          if (seen.count(p)) {
            dub = true;
          }
          seen.insert(p);

          a/=p;
          while(a%p==0){
            a/=p;
          }
        }
      }

      if (a!=1){
        if (seen.count(a)) {
          dub = true;
        }
        seen.insert(a);
      }
    }

    if (dub){
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }
  }
}








    
  
