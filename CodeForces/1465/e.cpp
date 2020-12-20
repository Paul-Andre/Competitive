#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct BigInt{
  int sign = 1;
  vector<uint32_t> digits;

  BigInt static powerOfTwo(int pow){
    assert(pow >= 0);
    BigInt a;
    a.digits = vector<uint32_t>(pow/32, 0);
    a.digits[pow/32] = 1<<(pow%32);
  }

  void negate(){
    sign*=-1;
  }

  bool operator>(BigInt &other) {
    if (digits.size() > other.digits.size()) return true;
    if (digits.size() < other.digits.size()) return false;
    for(int i=digits.size()-1; i>=0; i--) {
      if (digits[i] > other.digits[i]) return true;
      if (digits[i] < other.digits[i]) return false;
    }
    return false;
  }
};


int pos(char c) {
  return c - 'a';
}

int main() {
  ll n, t;
  string s;
  cin>>n>>t;
  cin>>s;
  n = s.size();

  t-=(1ll << pos(s[s.size() - 1]));
  t+=(1ll << pos(s[s.size() - 2]));

  if (t < 1) t*=-1;

  map<ll,ll> want;
  {
    int i = 0;
    while(t) {
      want[i] += (t%2);
      t/=2;
      i++;
    }
  }


  map<ll,ll> have;
  for (int i=0; i<s.size()-2; i++) {
    have[pos(s[i])] +=1;
  }

  cerr << "Want: ";
  for (int i=0; i<30; i++) {
    cerr <<want[i]<<" ";
  }cerr<<endl;

  cerr << "Have: ";
  for (int i=0; i<30; i++) {
    cerr <<have[i]<<" ";
  }cerr<<endl;

  bool good = true;
  for (int i=100; i>=0; i--) {
    ll h = want[i];
    //cerr << "i  h  " << i << " " << h <<endl;
    if (h > 2*n || h < -2*n) {
      cerr << "tooo big \n";
      good = false;
      break;
    }
    ll sign = (h < 0) ? -1 : 1;
    ll can_remove = min(sign*h, have[i]);

    have[i] -= can_remove;
    h -= sign*can_remove;
    have[i] %= 2;
    h -= have[i];

    if (i == 0) {
      if (h!=0) {
        cerr << "i == 0 && h!= 0\n";
        good = false;
        break;
      }
    } else {
      want[i-1] += h*2;
    }
  }
  if (good) {
    cout << "Yes\n";
  }else{
    cout << "No\n";
  }
}
