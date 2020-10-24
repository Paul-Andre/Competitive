#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct Pt{
  int x;
  int y;
  Pt() {
    x = 0;
    y = 0;
  }
  Pt(int x,int y): x(x), y(y) {}
};

bool topSpike(Pt a) {
  return a.x == 0 && a.y > 0;
}
bool botSpike(Pt a) {
  return a.x == 0 && a.y < 0;
}

int sign(int a) {
  if (a<0) return -1;
  if (a > 0) return 1;
  return 0;
}

  

bool operator<(Pt a, Pt b) {
  if (topSpike(a) && topSpike(b)) return false;
  if (topSpike(a)) return false;
  int sa = sign(a.x);
  int sb = sign(b.x);
  if (sa != sb) return sa < sb;
  if (sa == 0) return false;
  return  (a.y * b.x) < (b.y * a.x);
}

bool operator==(Pt a, Pt b) {
  if (topSpike(a) && topSpike(b)) return true;
  int sa = sign(a.x);
  int sb = sign(b.x);
  if (sa != sb) return false;
  if (sa == 0) return true;
  return  (a.y * b.x) == (b.y * a.x);
}

Pt operator-(Pt a) {
  return Pt(-a.x, -a.y);
}


void printM(map<int,int> m) {
  cout << "-1: " << m[-1] << "  1: " << m[1] << " ";
}


int main() {

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<pair<Pt, int>> A;
    for(int i=0; i<n;i++){
      float x,y,v;
      cin>>x>>y>>v;
      if (x==0 && y==0) continue;
      A.emplace_back(Pt(x*100, y*100), v);
    }

    n = A.size();
    sort(A.begin(), A.end());

    if (n == 0) {
      cout << "YES\n";
      continue;
    }

    for (int i=0; i<10 && i<n; i++) {
      auto a = A[i];
      cerr << a.first.x << " " << a.first.y << " " << a.second << endl;
    }


    map<int,int> tot;
    for (auto a: A) tot[a.second]++;


    for (int i=0; i<n; i++) {
      A.push_back(A[i]);
    }
    n = A.size();

    
    map<int,int> insideHalf;
    map<int,int> onBorder;




    bool good = false;
    auto checkGood = [&]() {

      printM(insideHalf);
      cout << " insideHalf \n";
      printM(onBorder);
      cout << " onBorder \n";




      if (insideHalf[1] == 0 && tot[-1] - insideHalf[-1] - onBorder[-1] == 0) {
        good = true;
      }
      if (insideHalf[-1] == 0 && tot[1] - insideHalf[1] - onBorder[1] == 0) {
        good = true;
      }
    };

    int i = 0;
    int j = 0;
    onBorder[A[0].second]++;

    auto includeAll = [&]()
    {
      while(i<n) {
        if (A[i].first == A[i+1].first) {
          i++;
          j++;
          onBorder[A[i].second]++;
        }else {
          break;
        }
      }
    };
    includeAll();

    bool closeOnBorder = false;

    while (j < n) {
      while(j + 1 < n) {
        Pt next = A[j+1].first;
        int l = A[j+1].second;
        Pt close = -(A[i].first);
        if (next < close) {
          j++;
          insideHalf[l]++;
          closeOnBorder = false;
        } else if ( next == close) {
          j++;
          onBorder[l]++;
          closeOnBorder = true;
        } else {
          break;
        }
      }
      checkGood();
      if (i == j) {
        onBorder[A[i].second]--;
        i++;
        j++;
        onBorder[A[i].second]++;

        includeAll();
      } else {
        onBorder[A[i].second]--;
        i++;
        onBorder[A[i].second]++;
        if (closeOnBorder) {
          onBorder[A[j].second]--;
          insideHalf[A[j].second]++;
          closeOnBorder = false;
        }
        while(i<n) {
          if (A[i].first == A[i+1].first) {
            i++;
            onBorder[A[i].second]++;
          }else {
            break;
          }
        }
      }
      //cerr << i <<  " " << j << " i  j\n";
    }
    if (good) {
      cout << "YES\n";
    }else {
      cout << "NO\n";
    }
  }
}


