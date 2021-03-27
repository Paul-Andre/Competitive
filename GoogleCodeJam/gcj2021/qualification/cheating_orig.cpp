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

  double s[100] = {};
  double q[10000] = {};

  for(int i=0; i<100; i++) {
    int tot = 0;
    for(int j=0; j<10000; j++) {
      if (wins[i][j]=='1') tot++;
    }
    double prob = tot/10000.;
    s[i] = inv_sigmoid(prob);
  }
  for(int j=0; j<10000; j++) {
    int tot = 0;
    for(int i=0; i<100; i++) {
      if (wins[i][j]=='1') tot++;
    }
    double prob = tot/100.;
    q[j] = -inv_sigmoid(prob);
  }
  double worst_llh = 0;
  int worst_i = 0;

  for(int i=0; i<100; i++) {
    double llh = 0;
    for(int j=0; j<10000; j++) {
      double prob = sigmoid(s[i] - q[j]);
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

