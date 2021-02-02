#include<bits/stdc++.h>
using namespace std;

struct Town{
  int worst;
  int ballots;
  int people;
};

bool operator<(const Town &a,const Town &b){
  return a.worst < b.worst;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(true){
    int n,b;
    cin>>n>>b;
    if (n==-1) break;
    vector<int> a(n);
    for(auto &aa:a)cin>>aa;
    priority_queue<Town> q;
    int rem = b-n;
    for(auto aa:a){
      Town t;
      t.worst = aa;
      t.ballots = 1;
      t.people = aa;
      q.push(t);
    }

    while(rem){
      Town t = q.top();
      q.pop();
      t.ballots++;
      rem--;
      t.worst = (t.people-1)/t.ballots + 1;
      q.push(t);
    }
    cout << q.top().worst<<endl;
  }
}
