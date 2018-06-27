#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

typedef pair<int,int> pii;

int A[112345];
pii B[112345];
int leftHighest[112345];
int rightHighest[112345];

map<int,int> M;

void ins(int i) {
  if (i != 0) {
    M[i] ++;
  }
}

void rem(int i) {
  M[i] --;
  if (M[i] == 0) {
    M.erase(i);
  }
}

int main() {

  cin>>n;
  for (int i=0; i<n; i++) {
    int a;
    cin >> a;
    A[i] = a;
    B[i] = pii(a,i);
  }
  sort(B, B+n);

  {
    vector<pii> biggests;
    biggests.push_back(pii(2123456789, -1));
    for (int i=0; i<n; i++) {
      while(A[i] > biggests.back().first) {
        biggests.pop_back();
      }
      leftHighest[i] = biggests.back().second;
      biggests.push_back(pii(A[i],i));
    }
  }

  {
    vector<pii> biggests;
    biggests.push_back(pii(2123456789, n));
    for (int i=n-1; i>=0; i--) {
      while(A[i] > biggests.back().first) {
        biggests.pop_back();
      }
      rightHighest[i] = biggests.back().second;
      biggests.push_back(pii(A[i],i));
    }
  }

  int max_loc = 1;
  int max_val = B[n-1].first+1;

  M[n]++;
  for (int i=n-1; i>=0; i--) {
    pii p = B[i];

    rem(rightHighest[p.second] - leftHighest[p.second] - 1);
    ins(rightHighest[p.second] - p.second - 1);
    ins(p.second - leftHighest[p.second] - 1);

    if (M.size() == 1) {
      for (pii q: M) {
        if (q.second >= max_loc) {
          max_loc = q.second;
          max_val = p.first;
        }
        break;
      }
    }
  }

  for (int i=n-1; i>=0; i--) {
    pii p = B[i];
    if (p.first < max_val) {
      cout << p.first+1 <<endl;
      return 0;
    }
  }

}



