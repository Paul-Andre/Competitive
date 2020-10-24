#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int B[121];
int W[121];

vector<int> Binv[121];
vector<int> Winv[121];

bool vis[121][121];
char trans[121][121];
int steps[121][121];

int n;
void printThing() {

    for (int i=1; i<=n;i++){
      cerr << i << ": ";
      for (int j=1; j<=n; j++) {
        if (trans[i][j]) {
          cerr <<trans[i][j] << " ";
        } else {
          cerr << "~" << " " ;
        }
      }
      cerr << endl;
    }
}
  

vector<pair<int,int>> toRecheck;

void doThings(int x, int y) {
  if (vis[x][y]) return;
  vis[x][y] = true;

  {
    auto & K = Winv;
    for (int i=0; i<K[x].size(); i++) {
      int xx = K[x][i];
      for (int j=0; j<K[y].size(); j++) {
        int yy = K[y][j];
        if (yy != xx && !vis[xx][yy]) {
          trans[xx][yy] = 'W';
          doThings(xx, yy);
        }
      }
    }
  }
  {
    auto & K = Binv;
    for (int i=0; i<K[x].size(); i++) {
      int xx = K[x][i];
      for (int j=0; j<K[y].size(); j++) {
        int yy = K[y][j];
        if (yy != xx && !vis[xx][yy]) {
          trans[xx][yy] = 'B';
          doThings(xx, yy);
        }
      }
    }
  }
  
  //printThing();

}

bool A[121];
bool tmp[121];

void cast(char c){
  for(int i=0; i<=n; i++) {
    tmp[i] = false;
  }
  if (c=='W') {
    for (int i=1; i<=n; i++) {
      if (A[i]) {
        tmp[W[i]] = true;
      }
    }
  }else if (c=='B') {
    for (int i=1; i<=n; i++) {
      if (A[i]) {
        tmp[B[i]] = true;
      }
    }
  }
  for (int i=1; i<=n; i++) {
    A[i]=tmp[i];
  }
}

pair<int,int> findPair() {
  
  bool lookingFirst = true;
  int x = 0;
  int y = 0;
  for (int i=1; i<=n; i++) {
    if (A[i]) {
      if (lookingFirst) {
        x=i;
        y=i;
        lookingFirst = false;
      } else {
        y=i;
        break;
      }
    }
  }
  return pair<int,int>(x,y);
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    cin>>n;
    for (int i=0; i<=n; i++) {
        A[i] = 
        B[i] = 
        W[i] = 
        0;
    Winv[i] = vector<int>();
    Binv[i] = vector<int>();
      for (int j=0; j<=n; j++) {
        vis[i][j] = 
        trans[i][j] = 
        steps[i][j] = 
        0;
      }
    }

    for (int i=1; i<= n;i++) {
      int x;
      cin>>x;
      W[i] = x;
      Winv[x].push_back(i);
    }
    for (int i=1; i<= n;i++) {
      int x;
      cin>>x;
      B[i] = x;
      Binv[x].push_back(i);
    }

    for (int i=1; i<=n;i++){
      trans[i][i] = '.';
      doThings(i,i);
    }
    printThing();
    cerr << endl;
    //exit(0);


    bool good = true;
    for (int i=1; i<=n; i++){
      for (int j=1; j<=n; j++) {
        if (!trans[i][j]) {
          good = false;
        }
      }
    }
    if (!good) {
      cout << "impossible\n";
      continue;
    }

    for (int i=0; i<121;i++){
      A[i] = 0;
    }
    for (int i=1; i<=n;i++){
      A[i] = 1;
    }
    

    string out;
    while(true) {
      pair<int,int> p = findPair();
      if (p.first == p.second) {
        break;
      }
      int i = p.first;
      int j = p.second;
      while(i!=j) {
        char instr = trans[i][j];


        out.push_back(instr);
        cast(instr);
        if (instr == 'W') {
          i = W[i];
          j = W[j];
        } else if (instr == 'B') {
          i = B[i];
          j = B[j];
        }
      }

        for (int i=0; i<=n; i++) {
          cerr << A[i] << " "
            ;
        }
        cerr <<endl;
    }

    cout << out <<endl;
  }
}


