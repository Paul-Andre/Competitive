#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Entry{
  int parent;
  //int rank;

  int value;

  int count;
  int sum;
};

vector<Entry> entries;

int find(int a){
  if (entries[a].parent == -1) {
    return a;
  }
  int p = entries[a].parent;
  int par = find(p);
  entries[a].parent = par;
  entries[p].count-=entries[a].count;
  entries[p].sum-=entries[a].sum;
}

int join(int a, int b){
  int ap = 




int main(){
  ll n,m;
  while(cin>>n>>m){
    vector<
    for (int iii=0; iii<n; iii++) {
      int command;
      cin>>command;
      if 

