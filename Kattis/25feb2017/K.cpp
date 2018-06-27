#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
using namespace std;


double tol(int a, int b) {
	return log(2.)*a + log(3.)*b;
}


int main() {
	int N;
	cin >> N;

	double maxl = -1;
	double minl = numeric_limits<double>::infinity();
	int maxa=0;
	int maxb=0;
	int mina=10000;
	int minb=10000;
	int maxla=0;
	int maxlb=0;
	int minla=10000;
	int minlb=10000;

	for (int i=0; i<N; i++) {
	int a, b;
	cin >> a >> b;
	double l = tol(a,b);
	if (l>maxl) {
		maxl= l;
		maxla = a;
		maxlb = b;
	}
	if (l<minl) {
		minl= l;
		minla = a;
		minlb = b;
	}
	if (a>maxa) {
		maxa = a;
	}
	if (a<mina) {
		mina = a;
	}
	if (b>maxb) {
		maxb = b;
	}
	if (b<minb) {
		minb = b;
	}
	}

	if (N==1) {cout << maxa << " " <<  maxb  << " " << maxa << " " << maxb <<'\n';}
	if (N==2) {
		cout << maxa << " " <<  maxb  << " " << maxa << " " << maxb <<'\n';
		cout << mina << " " <<  minb  << " " << mina << " " << minb <<'\n';}
	if (N==3) {
		cout << maxa << " " <<  maxb  << " " << maxa << " " << maxb <<'\n';
		cout << maxla << " " <<  maxlb  << " " << minla << " " << minlb <<'\n';
		cout << mina << " " <<  minb  << " " << mina << " " << minb <<'\n';}

	if (N>=4) {
	cout << maxa << " " <<  maxb  << " " << maxa << " " << maxb <<'\n';
	cout << maxa << " " <<  maxb  << " " << minla << " " << minlb <<'\n';
	for(int i=2; i<N-2; i++) {
		cout << maxa << " " <<  maxb  << " " << mina << " " << minb <<'\n';
	}
	cout << maxla << " " <<  maxlb  << " " << mina << " " << minb <<'\n';
	cout << mina << " " <<  minb  << " " << mina << " " << minb <<'\n';
	}
}






