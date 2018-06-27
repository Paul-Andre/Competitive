#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n, m, k, x, y;
	cin >> n >> m >> k >> x >> y;

	ll div = ((2*n-1-(ll)(n>1))*m);

	ll d = k / div;
	ll r = k % div;
	cout << d << " " << r << '\n';

	ll max, min, sergei;

	ll t; 
	if (n>=3) t = 2;
	else t=1;


	if(r>n*m) {
		max = d*t+2;
	}
	else if (r>0) {
		max = d*t+1;
	}
	else {
		max = d*t;
	}

	if(r>=n*m) {
		min = d+1;
	}
	else {
		min = d;
	}

	if (x==1 || x==n) {
		sergei = d + (ll)(r>= (x-1)*m+y);
	}
	else {
		sergei = 2*d + (ll)(r>= (x-1)*m+y)
			+ (ll)(r>= (2*n-x-1)*m+y);
	}

	cout << max << " " << min << " " << sergei << "\n";

}


