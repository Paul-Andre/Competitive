#include <bits/stdc++.h>
using namespace std;


int main() {

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    if (n <=3) {
      cout<< "impossible\n";
      continue;
    }
    vector<vector<int>> G(n, vector<int>(n,0));
    int counter = 1;
    int pieceCounter = 0;
    auto thing = [&](int i, int j) {
      G[i][j] = counter;
      pieceCounter ++;
      if (pieceCounter == n) {
        pieceCounter = 0;
        counter ++;
      }
    };
    if (n % 2 == 0) {
      counter--;
    }
    for (int i=0; i<n;i ++){
      thing(i,0);
    }
    if (n % 2 == 0) {
      bool down = true;
      for (int i=0; i<n; i++) {
        if (down) {
          for (int j=1; j<n; j++) {
            thing(i,j);
          }
        }else {
          for (int j=n-1; j>=1; j--) {
            thing(i,j);
          }
        }
        down = !down;
      }
    }else {
      bool down = true;
      for (int i=0; i<n; i++) {
        if (down) {
          for (int j=1; j<n; j++) {
            thing(i,j);
            if (counter == (n-3)/2 + 2) goto end;
          }
        }else {
          for (int j=n-1; j>=1; j--) {
            thing(i,j);
            if (counter == (n-3)/2 + 2) goto end;
          }
        }
        down = !down;
      }
end:
      down = true;
      for (int i=n-1; i>=0; i--) {
        if (down) {
          for (int j=1; j<n; j++) {
            thing(i,j);
            if (counter == n-1) goto end2;
          }
        }else {
          for (int j=n-1; j>=1; j--) {
            thing(i,j);
            if (counter == n-1) goto end2;
          }
        }
        down = !down;
      }
end2:
      ;

      if (n %4 == 3) {
        for (int i=1; i<=n-2; i++) {
          thing(n/2, i);
        }
        thing(n/2+1, n/2);
        thing(n/2-1, n/2);
      } else {
        for (int i=2; i<=n-1; i++) {
          thing(n/2, i);
        }
        thing(n/2+1, n/2+1);
        thing(n/2-1, n/2+1);
      }
        
    }
    for (auto &c : G){
      for (auto b : c) {
        if (b <26) {
          cout<<char('a'+b);
        } else if (b<26+26){
          cout<<char('A'+(b-26));
        } else {
          cout<<char('0'+(b-26-26));
        }

      }
      cout << endl;
    }
  }
}

        



