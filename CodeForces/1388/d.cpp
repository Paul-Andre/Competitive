#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tot = 0;
vector<int> out;

int n;
ll A[254321];

int B[254321];
vector<int> C[254321];

bool D[254321];

void v1(int i) {
  for(int j=0; j<C[i].size(); j++){
    int u = C[i][j];
    v1(u);
  }
  if (A[i] > 0) {
    tot+=A[i];
    if (B[i] != -1) {
      A[B[i]]+=A[i];
    }
    D[i] = true;
    out.push_back(i);
  }
}

void v2(int i){
  if (!D[i]) {
    tot+=A[i];
    if (B[i] != -1) {
      A[B[i]]+=A[i];
    }
    D[i] = true;
    out.push_back(i);
  }
  for(int j=0; j<C[i].size(); j++){
    int u = C[i][j];
    v2(u);
  }
}


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>A[i+1];
  }
  for(int i=0; i<n; i++){
    int v;
    cin>>v;
    B[i+1]=v;
    if (v!=-1){
      C[v].push_back(i+1);
    }
  }
  for(int i=1; i<=n; i++){
    if(B[i] == -1){
      v1(i);
      v2(i);
    }
  }
  cout << tot <<endl;
  for(int i=0; i<n; i++) {
    cout<<out[i]<< " ";
  }
  cout <<endl;
}

