#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int A[154321];
vector<int> factors[154321];

bool seive[1654321];

vector<int> primes;

// bipart graph
vector<int> X[154321];
vector<int> Y[1000];

bool vis[154321];


int main() {

  for(int i=2; i<1654321; i++) {
    if (seive[i] == false) {
      primes.push_back(i);
      for (int j=i*2; j<1654321; j+=i) {
        seive[j] = true;
      }
    }
  }
  cerr << primes.size() <<endl;
  cerr << primes[0] <<endl;

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> A[i];
  }

  for(int i=0; i<n; i++) {
    if (sqrt(A[i]) *sqrt(A[i]) == A[i]) {
      cout << 1 <<endl;
      return 0;
    }
    for (int j=0; j<215; j++) {
      while (A[i] % (primes[j] * primes[j]) == 0) {
        A[i] /= (primes[j] * primes[j]);
      }
      if (A[i] % primes[j] == 0) {
        X[i].push_back(j);
        Y[j].push_back(i);
      }
    }
    if (X[i].size() == 0) {
      X[i].push_back(-1);
    }
  }
}
