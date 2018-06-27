#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
    int m;
    int q;
    int k;
    cin >> n >> m >> q >> k;
    string s;
    cin >> s;

    vector< vector<int> > pairs(m,vector<int>(2));
    for(int pairs_i = 0;pairs_i < m;pairs_i++){
       for(int pairs_j = 0;pairs_j < 2;pairs_j++){
          cin >> pairs[pairs_i][pairs_j];
       }
    }

    for(int a0 = 0; a0 < q; a0++){
        string w;
        int a;
        int b;
        cin >> w >> a >> b;

		ll sum=0;
		for (int i=a; i<=b; i++) {

			int l = pairs[i][0];
			int r = pairs[i][1];
			int length = r-l+1;

			vector<int> t(length+1);

			t[0]=-1;
			t[1]=0;

			{
				//cout << "doing preprocessing \n";
				int i = 2;
				int j = 0;
				while(i<=length) {
					if (w[l+i-1] == w[l+j]) {
						t[i] = j+1;
						j++;
						i++;
					}
					else if (j>0) {
						j = t[j];
					}
					else {
						t[i] = 0;
						i++;
					}
				}
			}
			/*
			for (int j=0; j<t.size(); j++) {
				cout << t[j] << ' ';
			}
			cout << '\n';
			*/

			ll count = 0;
			{
				//cout << "doing searchin \n";
			int m=0;
			int i=0;
			
			while (m+i < s.size()) {
				//cout << "m i " << m << " " << i << "\n";
				//cout << "w[l+i] s[m+i]" << w[l+i << " " << i << "\n";
				if (w[l+i] == s[m+i]) {
					if (i == length - 1) {
						//cout << "money\n";
						count ++ ;
						i++;
						m=m+i - t[i];
						i= t[i];
						continue;
					}
					i++;
				}
				else {
					if ( t[i] > -1 ) {
						m=m+i - t[i];
						i= t[i];
					}
					else {
						m=m+1;
						i=0;
					}
				}
			}
			}
			sum += count;
		}

		cout << sum << '\n';

    }
    return 0;
}

