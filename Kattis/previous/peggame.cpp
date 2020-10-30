#include <bits/stdc++.h>
using namespace std;

int n;
int A[11][11];

// Th best I would get given
//  B[column][top_row][bot_row][top_angle+12][bot_angle+12]
int B[11][11][11][25][25];

int main(){
  int k;
  cin>>k;
  while(k--){
    cin>>n;
    memset(B, 0, sizeof(B));
    memset(A, 0, sizeof(A));
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){cin>>A[i][j];}
    for(int col = 1; col<=n; col++) {
      for(int tr = 1; tr<=n; tr++) {
        for (int br = tr; br<=n; br++) {
          for(int ptr = 1; ptr<=n; ptr++) {
            for (int pbr = ptr; pbr<=n; pbr++) {





