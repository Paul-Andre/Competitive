#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;

int main() {

  cin>>n>>s;

  if (n == 1) {
    if (s[0] == '1') cout << "Yes\n";
    else cout << "No\n";
  } else {

    bool no_neigh = true;
    for(int i=1;i<n;i++) {
      if (s[i] == '1' && s[i-1] == '1') no_neigh = false;
    }

    bool maxi = true;
    if (s[0] == '0' && s[1] == '0') maxi = false;
    if (s[n-2] == '0' && s[n-1] == '0') maxi = false;

    for(int i=1;i<n-1;i++) {
      if (s[i-1] == '0' && s[i] == '0' && s[i+1] == '0') maxi = false;
    }

    if (no_neigh && maxi) {
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }
  }

}



