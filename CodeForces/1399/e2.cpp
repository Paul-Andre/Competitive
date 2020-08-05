#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Op{
  ll op;
  ll weight;
  ll times;
  ll cost;
  Op(ll w, ll t, ll c){
    weight=w;
    times=t;
    cost=c;
    op=weight*times-(weight/2)*times;
  }
};

bool operator<(Op const &a, Op const &b){
  return b.cost*a.op<b.op*a.cost;
}

int n;
ll s;
vector<vector<tuple<int,ll,int>>> G;
vector<bool> vis;
vector<int> numCh;
priority_queue<Op> q;
ll current=0;

void ccc(int i){
  vis[i]=true;
  for(int j=0;j<G[i].size();j++){
    int u=get<0>(G[i][j]);
    if(vis[u]) continue;
    ccc(u);
    Op op(get<1>(G[i][j]), numCh[u], get<2>(G[i][j]));
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
    G = vector<vector<tuple<int,ll,int>>>(n+1);
    vis = vector<bool>(n+1,false);
    numCh = vector<int>(n+1,0);
    current=0;
    q= priority_queue<Op>();
    for(int i=0;i<n-1;i++){
      ll x,y,w,c;
      cin>>x>>y>>w>>c;
      G[x].emplace_back(y,w,c);
      G[y].emplace_back(x,w,c);
    }
    ccc(1);
    int cnt=0;
    bool findingLast=false;
    while(current>s){
      Op op = q.top();
      q.pop();

      if(current-op.op<=s && op.cost==2){
        findingLast=true;
        cerr << "   findingLast  " << op.weight<<" "<<op.times<<" "<<op.op << " " <<op.cost<<endl;
        break;
      }
      current-=op.op;
      cnt+=op.cost;
      cerr << "   op  " << op.weight<<" "<<op.times<<" "<<op.op << " " <<op.cost<<endl;
      cerr <<"      : " <<current << " " << cnt << endl;
      op=Op(op.weight/2, op.times, op.cost);
      if(op.op>0){
        q.push(op);
      }
    }
    if(findingLast){
      bool foundLast=false;
      while(!q.empty()){
        Op op = q.top();
        q.pop();
        if(op.cost==1 && current-op.op<=s){
          cnt++;
          foundLast=true;
          cerr<<"foundLast==true"<< " " <<endl;
          break;
        }
      }
      if(!foundLast){
        cnt+=2;
        cerr<<"foundLast==false"<<endl;
      }
    }
    cout<<cnt<<endl;
  }
}

