#include <iostream>
using namespace std;
#define MarsM 239075
#define EarthM 11679
#define LCM 250755

int main(){
	long e, m;
	int i = 1;
	while(cin >> e >> m){
		cout << "Case "<< i <<": "
			<<( (EarthM*e+MarsM*m)%LCM ) <<"\n";
		i++;
	}
}
