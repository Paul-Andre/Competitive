#include <bits/stdc++.h>
using namespace std;

string s;
bool good[26];

int n;

int main(){
    string ss;
    cin>>ss;
    for(int i=0;i<ss.size(); i++){
        good[ss[i]-'a'] = true;
    }
    cin>>s;
    cin>>n;

    int f = s.find('*');
    for(int iiii=0;iiii<n;iiii++){

        string t;
        cin>>t;

        if(t.size() < s.size()-1)  goto bad;

        if (f!=string::npos) {
            for(int i=0; i<f; i++) {
                if (t[i] == s[i] || (s[i] == '?' && good[t[i]-'a'])) continue;
                else goto bad;
            }
            for (int i=0; i<(s.size()-f-1); i++) {
                int ti = t.size()-1-i;
                int si = s.size()-1-i;
                if (t[ti] == s[si] || (s[si] == '?' && good[t[ti]-'a'])) continue;
                else goto bad;
            }

            for(int i = f; i<(t.size() - (s.size() - f - 1)); i++) {
                if(good[t[i]-'a']) goto bad;
            }
        }
        else {
            if (s.size() != t.size()) {
                goto bad;
            }
            for(int i=0; i<s.size(); i++) {
                if (t[i] == s[i] || (s[i] == '?' && good[t[i]-'a'])) continue;
                else goto bad;
            }
        }


        cout<<"YES\n";
        continue;

bad:

        cout<<"NO\n";
        continue;
    }
}
