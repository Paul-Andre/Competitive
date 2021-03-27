#include <bits/stdc++.h>
using namespace std;

double sigmoid(double x){
  return 1./(1. + exp(-x));
}

double inv_sigmoid(double y){
  return log(y/(1-y));
}

void solve(){
  string wins[100];
  for(auto&a:wins)cin>>a;

  double S[100] = {};
  double Q[10000] = {};

  double worst_llh = 0;
  int worst_i = 0;

  for(int i=0; i<100; i++) {
    int tot = 0;
    for(int j=0; j<10000; j++) {
      if (wins[i][j]=='1') tot++;
    }
    double prob = tot/10000.;
    S[i] = inv_sigmoid(prob);
  }

  for(int i=0; i<100; i++) {
    for(int j=0; j<10000; j++) {
      double a = -3;
      double b = 3;



      for(int tt=0; tt<50; tt++) {
        double q = (b+a)/2.;

        double acc = 0;
        for(int ii=0; ii<100; ii++) {
          if (i == ii) continue;
          if (wins[ii][j]=='0') {
            acc +=1;
          }
          acc -= sigmoid(q - S[ii]);
        }
        if (acc >= 0) {
          a = q;
        }else {
          b = q;
        }
      }

      Q[j] = (b+a)/2.;
    }

    double llh = 0;
    for(int j=0; j<10000; j++) {
      double prob = sigmoid(S[i] - Q[j]);
      if (wins[i][j]=='1') {
        llh+=log(prob);
      } else {
        llh+=log(1-prob);
      }
    }
    if (llh < worst_llh) {
      worst_llh = llh;
      worst_i = i;
    }
  }

  cout<<(worst_i+1);
}



int main(){
  int t;
  cin>>t;
  int p;
  cin>>p;
  for(int ttt=1; ttt<=t; ttt++){
    cout << "case #"<<ttt<<": ";
    solve();
    cout <<endl;
  }
}
