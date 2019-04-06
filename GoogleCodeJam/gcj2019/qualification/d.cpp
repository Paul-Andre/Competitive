#include <bits/stdc++.h>
using namespace std;

void proint(vector<int> &v) {
  return;
  for (int i=0; i<(int)v.size(); i++) {
    cerr << v[i] << " ";
  }
}

int main() {
  int T;
  cin >> T;
  for (int ttt = 0; ttt < T; ttt++) {
    int N, B, F;
    cin >> N >> B >> F;
    (void) F;
    int step = 16;
    vector<int> conts;
    while(step != 0) {
      int acc = 0;
      char curr = '0';
      for (int i=0; i<N; i++) {
        cout << curr;
        acc ++;
        if (acc == step) {
          acc = 0;
          if (curr == '0') curr = '1'; else curr = '0';
        }
      }

      cout << endl;
      string res;
      cin >> res;
      if (step == 16) {
        char curr = '0';
        conts.push_back(0);
        for (int i=0; i<(int)res.size(); i++) {
          if (res[i] == curr) {
            conts.back() += 1;
          } else {
            conts.push_back(1);
            curr = res[i];
          }
        }
      } else {
        vector<int> newConts;
        int i=0; 
        for (int J: conts) {
          int w =0; int b = 0;
          for (int j=0; j<J; j++, i++) {
            if (res.at(i) == '0') w++;
            else b++;
          }
          newConts.push_back(w);
          newConts.push_back(b);
        }
        conts = newConts;
      }
      proint(conts);
      //cerr <<endl;

      step /= 2;
    }
    for (int i=0; i<N; i++) {
      if(conts[i] == 0) cout << i << " ";
    }
    cout <<endl;
    int verdict;
    cin >> verdict;
    if (verdict == -1) return -1;
  }
  return 0;
}
