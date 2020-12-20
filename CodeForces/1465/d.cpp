#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int n;
int x, y;

ll interLeft[154321];
ll interRight[154321];

int main() {
  cin>>s;
  n = s.size();
  cin>>x>>y;

  if(x > y) {
    string t;
    for (char c: s){
      if (c=='1'){
        t.push_back('0');
      }else if (c=='0') {
        t.push_back('1');
      }else {
        t.push_back(c);
      }
    }
    s = move(t);
    int tmp = x;
    x = y;
    y = tmp;
  }
  ll tot0 = 0;
  ll tot1 = 0;
  ll totQ = 0;
  for(char c: s) {
    if (c=='0'){
      tot0++;
    }else if (c=='1') {
      tot1++;
    }else {
      totQ++;
    }
  }

  {
  ll n0 =0;
  ll n1 =0;
  ll acc = 0;
  for (int i=0; i<n;i++) {
    char c = s[i];
    if (c == '0' || c == '?') {
      acc += y*n1;
      n0++;
    } else if (c == '1') {
      acc += x*n0;
      n1++;
    }
    interLeft[i] = acc;
  }
  }
  {
  ll n0 =0;
  ll n1 =0;
  ll acc = 0;
  for (int i=n-1; i>=0;i--) {
    char c = s[i];
    if (c == '0') {
      acc += x*n1;
      n0++;
    } else if (c == '1' || c == '?') {
      acc += y*n0;
      n1++;
    }
    interRight[i] = acc;
  }
  }

  ll n0 =0;
  ll n1 =0;
  ll nQ =0;
  ll best = interRight[0];
  for (int i=0; i<n;i++) {
    char c = s[i];
    if (c == '0'){
      n0++;
    } else if (c == '1') {
      n1++;
    } else {
      nQ++;
    }

    ll l0 = n0 + nQ;
    ll l1 = n1;

    ll r0 = tot0 - n0;
    ll r1 = tot1 - n1 + totQ - nQ;
    
    ll curr = interLeft[i] + interRight[i+1] + l0*r1*x + l1*r0*y;
    //cerr << i << " " << curr << endl;
    best = min(best, curr);
  }
  cout << best <<endl;
}
