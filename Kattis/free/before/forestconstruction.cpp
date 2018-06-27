#include <iostream>
#include <vector>
using namespace std;

int main() {
	int V;
	cin >> V;
	int nonTrivial = V;
	vector<int> d(V);
	int leaves = 0;

	int sum = 0;
	for(int i=0; i<V; i++) {
		int dd;
		cin >> dd;
		d[i] = dd;
		sum += dd;
		if (dd==0) {nonTrivial--;}
		if (dd==1) {leaves++;}
	}

	if (sum%2==1 || ((sum/2)>=nonTrivial && nonTrivial!=0)) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	cout << "POSSIBLE\n";

	if (sum == 0) {
		return 0;
	}

	int j = 0;
	if (nonTrivial-leaves!=0) {
	int first = 0;
	while(d[first]<=1) {
		first++;
	}
	int prev = first;
	for (int k=0; k<d[first]-1; k++) {
		while(d[j]!=1){
			j++;
		}
		leaves--;
		cout << first+1 << " " << j+1 << '\n';
		j++;
	}

	for (int i=first+1; i<V; i++) {
		//cout << "wea \n";
		if (d[i]>1) {
			cout << prev+1 << " " << i+1 << '\n';
		for (int k=0; k<d[i]-2; k++) {
			while(d[j]!=1){
				j++;
			}
			cout << i+1 << " " << j+1 << '\n';
		leaves--;
			j++;
		}
		prev = i;
		}
	}

	while(d[j]!=1){
		j++;
	}
	//cout << "hop adf \n";
	cout << prev+1 << " " << j+1 << '\n';
		leaves--;
		j++;
	}

	while(leaves!=0) {
		while(d[j]!=1){
			j++;
		}
		int a = j;
		leaves--;
			j++;
		while(d[j]!=1){
			j++;
		}
		int b = j;
		leaves--;
			j++;
		cout << a+1 << " " << b+1 << '\n';
	}
}
