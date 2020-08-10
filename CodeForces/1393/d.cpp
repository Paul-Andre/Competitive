#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

  int n,m;
void printCerr(vector<vector<int> > &up){
  return;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cerr<<up[i][j]<<" ";
    }
    cerr<<endl;
  }
  cerr<<endl;
}



int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n>>m;
  vector<string> A(n);
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  vector<vector<int>> down(n, vector<int>(m, 1));
  vector<vector<int>> up(n, vector<int>(m, 1));

  for(int i=1; i<n; i++){
    for(int j=0; j<m; j++){
      if(A[i-1][j]==A[i][j]){
        up[i][j]=up[i-1][j]+1;
      }
    }
  }
  for(int i=n-2; i>=0; i--){
    for(int j=0; j<m; j++){
      if(A[i+1][j]==A[i][j]){
        down[i][j]=down[i+1][j]+1;
      }
    }
  }

  printCerr(up);
  printCerr(down);

  vector<vector<int>> leftTri(n, vector<int>(m, 1));
  vector<vector<int>> rightTri(n, vector<int>(m, 1));

  for(int i=0; i<n; i++) {
    for(int j=1; j<m; j++) {
      if(A[i][j]==A[i][j-1]){
        leftTri[i][j]=min(min(leftTri[i][j-1]+1, up[i][j]), down[i][j]);
      }
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=m-2; j>=0; j--) {
      if(A[i][j]==A[i][j+1]){
        rightTri[i][j]=min(min(rightTri[i][j+1]+1, up[i][j]), down[i][j]);
      }
    }
  }
  printCerr(leftTri);
  printCerr(rightTri);
  ll tot =0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      tot += ll(min(rightTri[i][j], leftTri[i][j]));
    }
  }
  cout<<tot<<endl;
}

