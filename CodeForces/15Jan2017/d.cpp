#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main(){
	ll n, k;
	cin >> n >> k;
	if (k>n/2) {
		k=n-k;
	}
	ll p = k;
	ll count = 0;
	ll tot = 2;
	cout << tot << " ";
	while(true) {
		p+=k;
		if(p<n){
			tot+=1+count*2;
		}
		else if (p>n) {
			tot+=2+count*2;
			count++;
			p-=n;
		}
		else {
			tot+=1+count*2;
			cout << tot << '\n';
			return 0;
		}
		cout << tot << " ";
	}
}

