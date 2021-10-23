#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int m,x,y,q;
ll grades[1321][1321];

const ll WORST = -1000ll*1000*1000*2;

//  period/only 1, period day, ammount acquired, consecutive days
//  1    , x         , y               , q
//  i     , j         , k               , l
//  <     , <=        , <=              , <=

vector<vector<vector<vector<ll> > > > a;
int main() {
  cin>>t;
  while(t--) {

    memset(grades, 0, sizeof(grades));

    cin>>m>>x>>y>>q;
    for(int i=0; i<m; i++) {
      for(int j=0; j<x; j++) {
        cin>>grades[i][j];
      }
    }

    a.clear();

    for(int i=0; i<1; i++) {
      a.emplace_back();
      for(int j=0; j<=x; j++) {
        a[i].emplace_back();
        for(int k=0; k<=y; k++) {
          a[i][j].emplace_back();
          for(int l=0; l<=q; l++) {
            a[i][j][k].emplace_back(WORST);
            //a[i][j][k][l] = WORST;
          }
        }
      }
    }

    for(int ii=0; ii<m; ii++) {
      int i = 0;
      auto cop = a;

      for(int j=0; j<=x; j++) {
        for(int k=0; k<=y; k++) {
          for(int l=0; l<=q; l++) {
            a[i][j][k][l] = WORST;
          }
        }
      }

      if (ii == 0) {
        a[0][0][0][0] = 0;
      } else {
        for(int l=0; l<=q; l++) {
          a[i][0][0][l] = cop[i][x][y][l];
        }
      }
      for(int j=1; j<=x; j++) {
        for(int k=0; k<=y; k++) {
          ll ifTakeBreak  = WORST;
          for(int l=0; l<=q; l++) {
            ifTakeBreak = max(ifTakeBreak, a[i][j-1][k][l]);
          }
          a[i][j][k][0] = ifTakeBreak;
          for(int l=1; l<=q; l++) {
            if (k > 0) {
              a[i][j][k][l] = a[i][j-1][k-1][l-1] + grades[i][j-1];
            } 
          }
        }
      }
    }
    ll best =  WORST;
    for(int l=0; l<=q; l++) {
      best = max( best, a[0][x][y][l]);
    }
    if (best >= 0) {
      cout << best <<endl;
    } else {
      cout << "IMPOSSIBLE" <<endl;
      cerr << best <<endl;
    }
  }
}






