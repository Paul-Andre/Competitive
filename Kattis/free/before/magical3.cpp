#include <iostream>
#include <cmath>
using namespace std;

int main(){
	while(true) {
		int n ;
		cin >> n;
		if (n==0) return 0;

		if (n==3) {
			cout << 4 <<'\n';
		}
		else if (n<=6) {
			cout << "No such base\n";
		}
		else {
			bool finished = false;
			int m = n-3;
			while(!finished) {
				int max = m;
				if (m>=30) {
					max = (int)sqrt(m)+1;
				}

				bool divBy2 = (m%2==0);
				bool divBy3 = (m%3==0);

				for(int d = 4; d<=max; d++) {
					if (m%d==0) {
						cout << d << '\n';
						finished = true;
						break;
					}
				}
				if (!finished) {
					if (divBy2) m/=2;
					else if (divBy3) m/=3;
					else {
						cout << m <<'\n';
						finished = true;
					}
				}
			}
		}
	}
}
