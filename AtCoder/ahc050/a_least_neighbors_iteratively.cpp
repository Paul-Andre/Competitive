#include <bits/stdc++.h>
using namespace std;

// Version 2
// Current algorithm:
// Iteratively pick the cell with the least neighboring rocks (and place a rock there)


// True means empty
bool grid[42][42];

int n;
int m;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main() {
	cin>>n>>m;
	assert(n==40);

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			char c;
			cin>>c;
			grid[i][j] = (c=='.');
		}
	}

	vector<pair<int,int>> positions;

	// I wish I had at least python style iterators, lol
	int empty_count = 0;


	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			empty_count += (grid[i][j]==true);
		}
	}

	for(int loops =0; loops<empty_count; loops++) {
		int best_i = -1;
		int best_j = -1;
		int best_score = 100;

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

				if (n_neigh < best_score) {
					best_i = i;
					best_j = j;
					best_score = n_neigh;
				}
			}
		}

		if (best_i != -1) {
			positions.push_back(make_pair(best_i,best_j));
			grid[best_i][best_j] = false;

		}else{
			break;
		}
	}
	
	empty_count = 0;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			empty_count += (grid[i][j]==true);
		}
	}
	assert(empty_count==0);

	for (auto &p: positions) {
		int x = p.first;
		int y = p.second;
		cout<<(x-1)<<" "<<(y-1)<<endl;
	}
}

			




	
