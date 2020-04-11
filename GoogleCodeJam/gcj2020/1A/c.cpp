#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int R, C;

void solve() {
  cin>>R>>C;
  vector<vector<ll>> S(R,vector<ll>(C,0));
  ll run = 0;
  ll tot = 0;
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      ll v;
      cin >> v;
      run+=v;
      S[i][j] = v;
    }
  }
  vector<vector<ll>> down(R,vector<ll>(C,-1));
  vector<vector<ll>> up(R,vector<ll>(C,-1));
  vector<vector<ll>> left(R,vector<ll>(C,-1));
  vector<vector<ll>> right(R,vector<ll>(C,-1));

  vector<pair<int,int>> considered;
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      if (j != C-1) {
        right[i][j] = j+1;
      }
      if (j != 0) {
        left[i][j] = j-1;
      }
      if (i != R-1) {
        down[i][j] = i+1;
      }
      if (i != 0) {
        up[i][j] = i-1;
      }
    considered.push_back(pair<int,int>(i, j));
    }
  }
  while(considered.size() != 0) {
    /*
    cerr << "conssiz " << considered.size();
    cerr << ": ";
    for(auto k: considered) {
      cerr << "("<<k.first<<","<<k.second<<") ";
    }
    cerr << endl;

    cerr << " run "<< run << endl;
    */
    tot += run;
    vector<pair<pair<int,int>, int>> new_down;
    vector<pair<pair<int,int>, int>> new_up;
    vector<pair<pair<int,int>, int>> new_left;
    vector<pair<pair<int,int>, int>> new_right;
    vector<pair<int,int>> removed;
    vector<pair<int,int>> newConsidered;
    map<pair<int,int>,bool> seen;
    for (int k=0; k<considered.size(); k++) {
      int x = considered[k].first;
      int y = considered[k].second;
      if (seen.count(make_pair(x,y))) continue;
      if (S[x][y] == 0) continue;
      seen[make_pair(x,y)] = true;
      ll self = S[x][y];
      ll op = 0;
      ll div = 0;
      if (up[x][y] != -1) {
        op += S[up[x][y]][y];
        div++;
      }
      if (down[x][y] != -1) {
        op += S[down[x][y]][y];
        div++;
      }
      if (left[x][y] != -1) {
        op += S[x][left[x][y]];
        div++;
      }
      if (right[x][y] != -1) {
        op += S[x][ right[x][y]];
        div++;
      }
      
      /*
      cerr << "x y op div self  ";
        cerr << x <<  " ";
        cerr << y<<  " ";
        cerr << op <<  " ";
        cerr << div <<  " ";
        cerr << self <<  " ";
        cerr <<endl;
        */
        
      if (div != 0 && self*div < op) {
        //S[x][y] = 0;
        removed.emplace_back(x,y);
        run -= self;
        if (up[x][y] != -1) {
          new_down.push_back(make_pair(make_pair(up[x][y],y), down[x][y]));
          new_down.push_back(make_pair(make_pair(x,y), -1));
          newConsidered.push_back(pair<int,int>(up[x][y],y));
        }

        if (down[x][y] != -1) {
          new_up.push_back(make_pair(make_pair(down[x][y],y), up[x][y]));
          new_up.push_back(make_pair(make_pair(x,y), -1));
        newConsidered.push_back(pair<int,int>(down[x][y],y));
        }

        if (left[x][y] != -1) {
          new_right.push_back(make_pair(make_pair(x,left[x][y]), right[x][y]));
          new_right.push_back(make_pair(make_pair(x,y), -1));
        newConsidered.push_back(pair<int,int>(x,left[x][y]));
        }

        if (right[x][y] != -1) {
          new_left.push_back(make_pair(make_pair(x,right[x][y]), left[x][y]));
          new_left.push_back(make_pair(make_pair(x,y), -1));
        newConsidered.push_back(pair<int,int>(x,right[x][y]));
        }

      }
    }
    considered = move(newConsidered);
    for (auto v: new_down) {
      auto a = v.first;
      int b = v.second;
      int x = a.first;
      int y = a.second;
      down[x][y] = b;
    }
    for (auto v: new_up) {
      auto a = v.first;
      int b = v.second;
      int x = a.first;
      int y = a.second;
      up[x][y] = b;
    }
    for (auto v: new_left) {
      auto a = v.first;
      int b = v.second;
      int x = a.first;
      int y = a.second;
      left[x][y] = b;
    }
    for (auto v: new_right) {
      auto a = v.first;
      int b = v.second;
      int x = a.first;
      int y = a.second;
      right[x][y] = b;
    }
    for (auto a: removed) {
      int x = a.first;
      int y = a.second;
      S[x][y] = 0;
    }
    
    /*
    cerr << "down \n";
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        cerr <<  down[i][j] << " ";
      }cerr << endl;
    }
    cerr << "up \n";
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        cerr <<  up[i][j] << " ";
      }cerr << endl;
    }
    cerr << "left \n";
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        cerr <<  left[i][j] << " ";
      }cerr << endl;
    }
    cerr << "right \n";
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        cerr <<  right[i][j] << " ";
      }cerr << endl;
    }

    cerr << "weadsgas \n";
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        cerr <<  S[i][j] << " ";
      }cerr << endl;
    }
    */
    
  }
    cout << tot << endl;
}


int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  int T;
  cin >> T;
  for(int i=1; i<=T; i++) {
    cout << "Case #" << i << ":  ";
    solve();
  }
}

