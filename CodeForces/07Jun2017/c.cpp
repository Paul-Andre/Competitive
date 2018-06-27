#include <bits/stdc++.h>
using namespace std;


int n;
string s;
int q;

int t[26][1501];

int main() {
    cin >> n;
    cin >> s;

    for (char l = 'a'; l<='z'; l++) {

        ////cerr << "letter " << l << endl;
        vector<int> rewards;
        vector<int> prices;

        int i = 0;

        while(i<s.size() && s[i]!=l){
            i++;
        }

        if (i == s.size()) {
            continue;
        }

        bool in = true;
        int found = 1;
        i++;

        for (; i<s.size(); i++) {
            if (in) {
                if (s[i] == l) {
                    found ++;
                }
                else {
                    //cerr << "reward: " << found << endl;

                    rewards.push_back(found);
                    found = 1;
                    in = false;
                }
            }
            else {
                if (s[i] != l) {
                    found ++;
                }
                else {
                    //cerr << "price: " << found << endl;
                    prices.push_back(found);
                    found = 1;
                    in = true;
                }
            }
        }

        if(in){
                    //cerr << "reward: " << found << endl;
            rewards.push_back(found);
        }
        else{
                    //cerr << "price: " << found << endl;
            prices.push_back(found);
        }


        for (int i=0; i<rewards.size(); i++) {
            int totPrice = 0;
            int totReward = 0;

            totReward += rewards[i];

            t[l-'a'][totPrice] = max(t[l-'a'][totPrice], totReward);

            for(int j=i+1; j<rewards.size(); j++) {
                totReward += rewards[j];
                totPrice += prices[j-1];

                t[l-'a'][totPrice] = max(t[l-'a'][totPrice], totReward);
            }
        }


        for(int i=1; i<1501; i++) {
            t[l-'a'][i] = max(t[l-'a'][i], t[l-'a'][i-1]);
        }

        cerr << l << ": ";
        for (int i=0; i<=n; i++) {
            cerr << t[l-'a'][i] << " ";
        }
        cerr << endl;
    }




    cin >> q;

    for (int i=0; i<q; i++) {
        int m;
        char c;
        cin >> m >> c;

        int r = t[c-'a'][m];

        r += m;

        r = min(r, n);
        cout << r << endl;
    }
}
