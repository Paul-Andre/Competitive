#include <iostream>
using namespace std;

#define mod 1000000007

int main(){
	char c;
	long numOnes=0;
	long sum=0;
	long var=1;
	while( cin >> c && c!='\n'){
		if (c=='1') {
			numOnes=(numOnes+var)%mod;
		}
		if (c=='0') {
			sum=(sum+numOnes)%mod;
		}
		if (c=='?') {
			sum= (sum*2)%mod;
			sum=(sum+numOnes)%mod;
			numOnes=(numOnes*2+var)%mod;
			var=(var*2)%mod;
		}
			//cout <<"'"<<c<<"' "<< numOnes << " " << sum << " " << var << "\n";
	}
	cout << sum << "\n";
}
