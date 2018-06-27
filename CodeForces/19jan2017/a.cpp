#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long sum = 0;
	long long max = 0;
	for(int i = 0; i<n; i++){
		int a;
		cin >> a;
		if (a>max) max = a;
		sum+=a;
	}
	cout << (max*n)-sum << '\n';
}


