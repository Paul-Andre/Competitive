#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin>>k;
  int n = 1<<k;
  string s;
  {
    cin>>s;
    reverse(s.begin(), s.end());
    s = "_" + s;
  }
  vector<int> counts(s.size()*2);
  for(int i=0; i<counts.size(); i++) {
    if (i < s.size()) {
      counts[i]=0;
    } else {
      counts[i]=1;
    }
  }

  auto recalc = [&](int p) {
    char c = s[p];
    if (c == '?') {
      counts[p] = counts[p*2] + counts[p*2+1];
    } else {
      counts[p] = counts[p*2+ 1-(c-'0')];
    }
  };

  auto recalc_up = [&](int p) {
    while(p != 0) {
      recalc(p);
      p/=2;
    }
  };

  for (int i=n-1; i>=1; i--) {
    recalc(i);
  }

  int q;
  cin>>q;
  for (int qqq=0; qqq<q; qqq++) {
    int p;
    char c;
    cin>>p>>c;
    p=n-p;
    s[p] = c;
    recalc_up(p);
    cout<<counts[1] <<endl;
  }

}
