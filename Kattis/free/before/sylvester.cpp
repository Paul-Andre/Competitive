#include <iostream>
using namespace std;

int v(long x, long y) {
	if (x==0 && y==0) {
		return 1;
	}
	if (x%2==1 && y%2==1) {
		return -v(x/2,y/2);
	}
	else return v(x/2,y/2);
}

int main(){
	int kk; 
	cin >> kk;
	while(kk--){
		long n, x, y, w, h;
		cin >> n >> x >> y >> w >> h;
		for(int j=0; j<h; j++){
			for(int i=0; i<w-1; i++){
				cout << v(x+i,y+j) << ' ';
			}
			cout << v(x+w-1,y+j) << '\n';
		}
		cout << '\n';
	}

}
