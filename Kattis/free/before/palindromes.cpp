#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string s;
	cin >> s;

	int n = s.size();

	// I calculate the number of palindromes that are centered within a certain substring.
	// That will take n^2 time and each query will furthermore take n time.
	
	// [center]
	int odd[n];
	int even[n];

	for (int i=0; i<n; i++) {
		int count = 1;
		for (int len=1; len<=i && len<=n-1-i; len++) {
			if (s[i-len]==s[i+len]) {
				count++;
			}
			else break;
		}
		odd[i]=count;
	}

	for (int i=0; i<n; i++) {
		int count = 0;
		for (int len=1; len<=i && len<=n-i; len++) {
			if (s[i-len]==s[i+len-1]) {
				count++;
			}
			else break;
		}
		even[i]=count;
	}


	int m;

	cin >> m;

	while(m--){
		int l, r;
		cin >> l >> r;
		l--;
		r--;

		long total=0;
		for (int i=l; i<=r; i++) {
			total+=min(min(odd[i],(i-l+1)),(r-i+1));
			total+=min(min(even[i],(i-l)),(r-i+1));
		}
		cout << total <<'\n';
	}
}

