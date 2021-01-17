#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a(n+1);
  vector<vector<int>> b(n+1);
  int m=0;
  for(int i=1; i<=n; i++) {
    int k;
    cin>>k;
    a[i]=k;
    if (b[k].size() ==0){
      m++;
    }
    b[k].push_back(i);
  }
  bool good = true;
  for(int i=1; i<=n; i++){
    if(a[a[i]]!=a[i]) {
      good=false;
      break;
    }
  }
  if(!good){
    cout << "-1\n";
    return 0;
  }
  cout <<m<<endl;
  map<int,int> mapping;
  map<int,int> unmapping;
  int counter=1;
  for (int i=1; i<=n; i++){
    int aa = a[i];
    if (mapping.count(aa) == 0) {
      mapping[aa] = counter;
      unmapping[counter] = aa;
      counter++;
    }
    cout << mapping[aa] << " ";
  }
  cout << endl;
  for (int i=1; i<=m; i++){
    cout << unmapping[i] << " ";
  }
  cout << endl;
}



  
