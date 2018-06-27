#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int ms[26];
int mt[26];
int mp[26];

string s, t;
int main() {
    cin>>s>>t;

    int q = 0;

    for(int i=0; i<s.size(); i++) {
        if (s[i] == '?') q++;
        else ms[s[i]-'a']++;
    }
    for(int i=0; i<t.size(); i++) {
        mt[t[i]-'a']++;
    }


    vector<char> adds;


    priority_queue<pii> heap;

    for(int c=0; c<26; c++) {
        if (mt[c] != 0) {
            mp[c] = ms[c] / mt[c];
            heap.push(pii(-mp[c], c));
        }
    }

    while(q!=0) {
        pii p = heap.top();
        heap.pop();

        int c = p.second;

        adds.push_back(c);

        ms[c]++;
        mp[c] = ms[c] / mt[c];
        heap.push(pii(-mp[c], c));
        q--;
    }

    int j = 0;

    for(int i=0; i<s.size(); i++) {
        if (s[i] == '?') {
            s[i] = (adds[j] + 'a');
            j++;
        }
    }

    cout << s <<endl;
}
