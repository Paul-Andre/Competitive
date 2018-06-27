#include <map>
#include <iostream>
using namespace std;

int main() {
	map<int,string> a;
	a[0] = "Hello0";
	a[1] = "Hello1";
	a[2] = "Hello2";
	a[3] = "Hello3";

	auto itlow = a.lower_bound(0);
	auto ithigh = a.upper_bound(2);

	for(auto it = itlow; it!=ithigh; it++) {
		cout << it->first << " " << it->second << '\n';
	}
}

