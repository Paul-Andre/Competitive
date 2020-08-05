#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Op{
  ll op;
  ll weight;
  ll times;
  Op(ll w, ll t){
    weight=w;
    times=t;
    op=weight*times-(weight/2)*times;
  }
};

bool operator<(Op const &a, Op const &b){
  return a.op<b.op;
}

int n;
ll s;
vector<vector<pair<int,ll>>> G;
vector<bool> vis;
vector<int> numCh;
priority_queue<Op> q;
ll current=0;

void ccc(int i){
  vis[i]=true;
  for(int j=0;j<G[i].size();j++){
    int u=G[i][j].first;
    if(vis[u]) continue;
    ccc(u);
    Op op(G[i][j].second, numCh[u]);
    q.push(op);
    current+=op.weight*op.times;
    numCh[i]+=numCh[u];
  }
  if(numCh[i]==0){
    numCh[i]=1;
  }
}

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    cin>>n>>s;
    G = vector<vector<pair<int,ll>>>(n+1);
    vis = vector<bool>(n+1,false);
    numCh = vector<int>(n+1,0);
    current=0;
    q= priority_queue<Op>();
    for(int i=0;i<n-1;i++){
      ll x,y,w;
      cin>>x>>y>>w;
      G[x].emplace_back(y,w);
      G[y].emplace_back(x,w);
    }
    ccc(1);
    int cnt=0;
    while(current>s){
      Op op = q.top();
      q.pop();
      cnt++;
      current-=op.op;
      //cerr << "   op  " << op.weight<<" "<<op.times<<" "<<op.op <<" : " <<current<<endl ;
      op=Op(op.weight/2, op.times);
      q.push(op);
    }
    cout<<cnt<<endl;
  }
}

