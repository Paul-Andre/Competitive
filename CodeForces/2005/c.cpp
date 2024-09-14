#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  int T;
  cin>>T;
  for (int ttt=0; ttt<T; ttt++) {
    int n, m;
    cin>>n>>m;
    vector<string> S(n);
    for (auto &s: S) {
      cin>>s;
    }
    string name = "narek";
    int ns = name.size();

    vector<vector<int>> score(n+1, vector<int>(ns, 0));

    for (int j = 0; j<name.size(); j++) {
      score[n][j] = -(1<<29);
    }

    for (int i =n-1; i>=0; i--) {
      const string &s = S[i];
      for (int j = 0; j<ns; j++) {
        int portionScore = 0;
        bool foundLast  = false;
        int l = j;
        for (int k =0; k<s.size(); k++) {
          if (s[k] == name[l]) {
            portionScore ++;
            if (l==ns-1) {
              foundLast = true;
            }
            l+=1;
            l%=ns;
          } else if (name.find(s[k]) != string::npos) {
            portionScore --;
          }
        }
        int portionScoreIfFinal;
        if (foundLast) {
          portionScoreIfFinal = portionScore - 2*l;
        } else {
          portionScoreIfFinal = -(1<<29);
        }

        score[i][j] = max(score[i+1][j], max(portionScoreIfFinal, 
            portionScore+score[i+1][l]));
      }
    }

    /* for (int i =0; i<=n; i++) { */
    /*   for (int j = 0; j<ns; j++) { */
    /*     cerr << score[i][j] <<","; */
    /*   }cerr<<"  "; */
    /* }cerr<<endl; */

   cout<<(max(0,score[0][0])) <<endl;
    //cout<<((score[0][0])) <<endl;
  }
}
    



