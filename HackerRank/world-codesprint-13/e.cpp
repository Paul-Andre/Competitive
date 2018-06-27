
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;



int find(int i, int *parent, int *rk) {
    if (parent[i] == 0) {
        return i;
    }
    else {
        int par = find(parent[i], parent, rk);
        parent[i] = par;
        return par;
    }
}

void join(int a, int b, int *parent, int *rk) {
    int pa =find(a, parent, rk);
    int pb =find(b, parent, rk);
    if (pa != pb) {
        if (rk[pa] > rk[pb]) {
            parent[pb] = pa;
        }
        else if (rk[pb] > rk[pa]) {
            parent[pa] = pb;
        }
        else {
            parent[pa] = pb;
            rk[pb] ++;
        }
    }
}


int n, q;
int f[4];


int parent[112345];
int rk[112345];
int size[112345];

map<int,int> cnt;
ll tot;

void ins(int r) {
  cnt[r] ++;
  tot ++;
}

void rem(int r) {
  cnt[r] --;
  tot --;
  if (cnt[r] == 0) {
    cnt.erase(r);
  }
}

int main() {
  cin>>n>>q;

  for (int i=1; i<=n; i++) {
    size[i] = 1;
    ins(1);
  }

  for(int i=0; i<q; i++) {
    int cmd ;
    cin >>cmd;
    if (cmd == 1) {
      int x, y;
      cin>>x>>y;
      int xp = find(x, parent, rk);
      int yp = find(y, parent, rk);
      if (xp != yp) {
        //cerr << "join " << xx << " " << yy <<endl;
        join(xp, yp, parent, rk);
        int p = find(xp, parent, rk);
        rem(size[xp]);
        rem(size[yp]);
        ins(size[yp] + size[xp]);

          size[p] = size[xp] + size[yp];
      }
    } else {
      int c;
      cin >> c;

      /*
      cerr << "wew ";
      for (pair<int,int> p: cnt) {
        cerr << p.first << " " << p.second<< ",  ";
      }
      cerr <<endl;
      */

      if (c == 0) {
        cout << tot*(tot-1)/2 <<endl;
      }else {

        map<int,int>::iterator i= cnt.begin();
        map<int,int>::iterator j= cnt.begin();

        ll good = 0;
        ll tot = 0;

        while(j != cnt.end()) {
          //cerr << i->first << " " << j->first << " " << good << endl;
          if (j->first - i->first >= c) {
            good += i->second;
            i++;
          } else {
            tot += j->second*good;
            j++;
          }
        }
        cout << tot <<endl;
      }

    }
  }
}
