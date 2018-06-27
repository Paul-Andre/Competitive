#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

string s;


typedef pair<int,int> pii;

priority_queue <pii, vector<pii>, greater<pii> > min_h;
priority_queue <pii, vector<pii>, less<pii> > max_h;

int main() {

  cin>>n;
  for (int i=1; i<=n; i++) {
    int w;
    cin >> w;
    min_h.push(pii(w,i));
  }
  cin >> s;

  for(int i=0; i<s.size(); i++) {
    if(s[i] == '0') {
      pii p = min_h.top();
      min_h.pop();
      cout << p.second << " ";
      max_h.push(p);
    } else {
      pii p = max_h.top();
      max_h.pop();
      cout << p.second << " ";
    }
  }
    cout << endl;
}



