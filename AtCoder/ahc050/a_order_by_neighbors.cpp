#include <bits/stdc++.h>
using namespace std;

// Current algorithm:
// Simply order cells in terms of how many neighbors they have and return them


// True means empty
bool grid[42][42];

int n;
int m;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main() {
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			char c;
			cin>>c;
			grid[i][j] = (c=='.');
		}
	}

	vector<pair<int,pair<int,int>>> positions;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (!grid[i][j]) continue;
			int n_neigh = 0;
			for (int k=0; k<4; k++) {
				int xx = i+dx[k];
				int yy = j+dy[k];
				// If the grid has a rock
				if (!grid[xx][yy]) {
					n_neigh+=1;
				}
			}
			positions.push_back(make_pair(n_neigh, make_pair(i,j)));
		}
	}
	sort(positions.begin(), positions.end());

	for (auto &p: positions) {
		int x = p.second.first;
		int y = p.second.second;
		cout<<(x-1)<<" "<<(y-1)<<endl;
	}
}

			




	
