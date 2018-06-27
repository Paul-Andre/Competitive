#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t; 
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long sum = 0;
		for(int i=0; i<n; i++){
			int x, y;
			cin >> x >> y;
			double r = sqrt(double(x*x+y*y));
			int c = (int)ceil(r/20.);
			if (c==0) c = 1;
			//cout << "adsfa " << c << "\n";
			if (c<=10) {
				sum += 11-c;
			}
		}
		cout << sum << '\n';
	}
}
