#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll runningFire[254321];
ll runningLight[254321];

void set(int i, ll x, ll *a){
  while(i<254321){
    a[i]+=x;
    i+=i&-i;
  }
}
void get(int i, ll *a){
  int x=0;
  while(i!=0){
    x+=a[i];
    i-=i&-i;
  }
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  vector<pair<int,int>> changes(n);
  set<int> powers;
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    changes.emplace_back(x,y);
    if(y>0){
      powers.insert(y);
    }
  }
  map<int,int> powerToPlace;
  {
    int i=1;
    for(int y:powers){
      powerToPlace[y]=i;
      i++;
    }
  }

  for(int i=0;i<n;i++){
    int x=changes[i].first, y=changes[i].second;
    int place=powerToPlace[abs(y)];
    if(x==0){
      set(place, y, runningFire);
    }else{
      set(place, y, runningLight);
    }
  }
}
