#include <iostream>
#include <cmath>

using namespace std;


int link[10001];
int rank[10001];

int find(int m) {
	if (link[m]==-1) {
		return m;
	}
	else {
		return find(link[m]);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		link[i]=-1;
		rank[i]=0;
	}
	for(int i=0; i<n; i++){
		int m;
		cin >> m;
		m--;

		int iRoot = find(i);
		int mRoot = find(m);

		if (iRoot != mRoot) {
			if (rank[iRoot] < rank[mRoot]) {
				link[iRoot] = mRoot;
			}
			else if (rank[iRoot] > rank[mRoot]) {
				link[mRoot] = iRoot;
			}
			else {
				link[iRoot] = mRoot;
				rank[mRoot] ++;
			}
		}
	}
	int count=0;
	for(int i=0; i<n; i++){
		if (link[i]==-1) {
			count++;
		}
	}
	cout << count << "\n";
}

