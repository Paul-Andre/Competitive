#include <bits/stdc++.h>
using namespace std;

// Version 03_1
// Current algorithm:
// Calculate the probability of the robot being there, and select the cell with the least chance
// Additionally, randomly break ties


// True means empty
bool grid[42][42];

// The expected value of a robot being there
// This is an expected value and not a probability. It will sum up to less than 1.
// The sum over all cells, over all turns will give us the final score.
float ex[42][42];
float new_ex[42][42];

int n;
int m;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


pair<int,int> get_coord_trans(int x, int y, int version) {
	assert(n==40);
	if (version == 2 || version == 3) {
		int tmp = x;
		x = y;
		y = tmp;
	}
	if (version == 1 || version == 3) {

		x = 42 - x - 1;
		y = 42 - y - 1;
	}
	return make_pair(x, y);
};


void recalc_ex() {
	// zero out new_exp
	memset(new_ex, 0, sizeof(new_ex));


	for(int version = 0; version < 4; version++) {
		for (int i=1; i<=n; i++) {
			double running_sum = 0.0;
			for (int j=1; j<=n; j++) {
				auto c = get_coord_trans(i, j, version);
				auto nc = get_coord_trans(i, j+1, version);

				if (grid[c.first][c.second]) {
					running_sum += ex[c.first][c.second];
					if(!grid[nc.first][nc.second]) {
						new_ex[c.first][c.second] += running_sum / 4.0;
						running_sum = 0.0;
					}
				}
			}
		}
	}
	// Write the new expected values back to ex
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			ex[i][j] = new_ex[i][j];
		}
	}


}

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

	// initialize the expected values
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (grid[i][j]) {
				ex[i][j] = 1.0/empty_count;
			}else{
				ex[i][j] = 0.0;
			}
		}
	}

	for(int loops =0; loops<empty_count; loops++) {
		int best_i = -1;
		int best_j = -1;
		double best_score = 100;
		double random_tie_breaker = (1.0 * rand() / RAND_MAX);
		recalc_ex();
		// // print the expected values
		// for (int i=1; i<=n; i++) {
		// 	for (int j=1; j<=n; j++) {
		// 		if (grid[i][j]) {
		// 			cout<<ex[i][j]<<" ";
		// 		}else{
		// 			cout<<"# ";
		// 		}
		// 	}
		// 	cout<<endl;
		// }
		// cout<<"------------------------"<<endl;
		// char c;
		// cin>>c;

		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if (!grid[i][j]) continue;

				double score = ex[i][j];
				double tie_breaker = (1.0 * rand() / RAND_MAX);

				if (score < best_score || (score == best_score && tie_breaker < random_tie_breaker)) {
					best_i = i;
					best_j = j;
					best_score = score;
					random_tie_breaker = tie_breaker;
				}
			}
		}

		if (best_i != -1) {
			positions.push_back(make_pair(best_i,best_j));
			grid[best_i][best_j] = false;
			ex[best_i][best_j] = 0.0;
			cout<<best_i-1<<" "<<best_j-1<<endl;

		}else{
			break;	
		}
	}
	
	{
		empty_count = 0;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				empty_count += (grid[i][j]==true);
			}
		}
		assert(empty_count==0);
	}

	// for (auto &p: positions) {
	// 	int x = p.first;
	// 	int y = p.second;
	// 	cout<<(x-1)<<" "<<(y-1)<<endl;
	// }
}

			




	
