#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n; 
vector<pair<int,int>> vecs;
int grid[1000][1000];

int main() {
  cin>>n;
  for (int i=0; i<n; i++) {
    int x,y;
    cin>>x>>y;
    vecs.emplace_back(x,y);
  }
  int hn = n/2;
  for (ll k = 0; k < (1ll<<hn); k++) {
    int totx =0;
    int toty = 0;
    for (int i=0; i<hn; i++) {
      if (k&(1<<i)) {
        totx += vecs[i].first;
        toty += vecs[i].second;
      }
    }
    grid[totx+500][toty+500]++;
    //cerr <<k << " " << totx << " " << toty  <<endl;
  }
  ll tot = 0;
  int hhn = n-hn;
  for (ll k = 0; k < (1ll<<hhn); k++) {
    int totx =0;
    int toty = 0;
    for (int i=0; i<hhn; i++) {
      if (k&(1<<i)) {
        totx += vecs[i+hn].first;
        toty += vecs[i+hn].second;
      }
    }
    tot += grid[-totx+500][-toty+500];
    //cerr <<k << " " << totx << " " << toty  <<endl;
  }
  tot -= 1; // empty set
  cout << tot <<endl;
}



