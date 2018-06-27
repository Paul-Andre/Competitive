#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <cmath>
using namespace std;


int main() {
	int n;
	string s;
	cin >> n >> s;
	int len = 1+ (int)log10(n);

	long long mult = 1;
	long long res = 0;
	int i= s.size()-1;
	while(i>=0) {
		int beg = i-len+1;
		if (beg<0) beg = 0;
		string sub = s.substr(beg, i + 1 - beg);
			while (sub.size()>1 && sub[0]=='0'){
				sub = sub.substr(1);
				i++;
			}

		long long in;
		in = strtoull(sub.c_str(), NULL, 10);
		if (in < n) {
			i-=len;
		}
		else {
			int beg = i-len+2;
			if (beg<0) beg = 0;
			sub = s.substr(beg, i + 1 - beg);
			while (sub.size()>1 && sub[0]=='0'){
				sub = sub.substr(1);
				i++;
			}
			in = atoll(sub.c_str());
			i-=len-1;
		}
		res += mult*in;
		mult*=n;
	}

	cout << res << '\n';
	
}
