#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

#define square(x) ((x)*(x))

double PI;


double pointSegmentDistance(double px, double py, double ax, double ay, double bx, double by) {
	/*
	if (ax == bx) {
		return abs(px- ax);
	}
	*/

	px -= ax;
	py -= ay;
	bx -= ax;
	by -= ay;
	ax = ay = 0;

	double a = (px*bx + py*by) / (bx*bx + by*by);
	//cout << " a " << a << '\n';
	if (a>=0 && a<=1) {
		return sqrt(square(a*bx-px) + square(a*by-py));
	}
	else {
		return min(sqrt(px*px + py*py), sqrt(square(px-bx)+ square(py-by)));
	}
}

double segmentSegmentDistance(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy) {
	double ret = pointSegmentDistance(ax, ay, cx, cy, dx, dy);
	ret = min (ret, pointSegmentDistance(bx, by, cx, cy, dx, dy));
	ret = min (ret, pointSegmentDistance(cx, cy, ax, ay, bx, by));
	ret = min (ret, pointSegmentDistance(dx, dy, ax, ay, bx, by));
	return ret;
}

int main() {
	double R, l, w;
	cin >> R >> l >> w;
	int T;
	cin >> T;

	PI = acos(-1);

	for(int i=0; i<T; i++) {
		double A, B;
		cin >> A >> B;

		double d = l;

		if (A<PI/2.) {
			//d = l*sin(A);
			d = pointSegmentDistance(0,w, l, w , l-cos(A)*l, w+ sin(A)*l);
		}

		d = min(d, segmentSegmentDistance(l, w, l-cos(A)*l, w+sin(A)*l, l, 0, l-cos(B)*l, sin(B)*l));

		if (B>=PI/2.) {
			d = min (d, w - sin(B)*l);
		}


		//cout << " " << a1 << " " << a2 << " " << a3 << '\n';
		cout << std::setprecision (15) << min(d/2.,R) << "\n";
	}
}

