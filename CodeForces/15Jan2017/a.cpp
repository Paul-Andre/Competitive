#include <iostream>
#include <cmath>

using namespace std;


bool isPrime(int a) {
	if (a==2 || a==3) return true;
	int s = (int)sqrt(a)+1;
	for (int i=2; i<=s; i++){
		if (a%i==0) return false;
	}
	return true;
}


int main(){
	int n;
	cin >> n;
	for(int m=1; m<=1000; m++){
		if (!isPrime(n*m+1)) {
			cout << m << "\n";
			return 0;
		}
	}
}


