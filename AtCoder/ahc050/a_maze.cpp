#include <bits/stdc++.h>
using namespace std;

// Version 04
// Current algorithm (in development):
// Calculate the probability of the robot being there, and select the cell with the least chance
// To break ties, look at how placing a rock will "decrease entropy" and concentrate value in tighter spaces


// True means empty
bool grid[42][42];

// The expected value of a robot being there
// This is an expected value and not a probability. It will sum up to less than 1.
// The sum over all cells, over all turns will give us the final score.
float ex[42][42];
float new_ex[42][42];
float prev_ex[42][42];
float running_sum_arr[4][42][42];
float running_count_arr[4][42][42];

int n;
int m;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

struct Node {
	int x, y;
	float ex[42][42];
	bool grid[42][42];
	// TODO: don't need grid as a separate field, since can encode the grid into ex (-1 for rock)
	vector<Node*> children;
};


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

void run_fallback() {
	// Fallback: just place rocks in the first empty cells
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (grid[i][j]) {
				grid[i][j] = false;
				cout<<i-1<<" "<<j-1<<endl;
			}
		}
	}
	exit(0);
}

void recalc_ex() {
	// zero out new_exp
	memset(new_ex, 0, sizeof(new_ex));
	memset(running_sum_arr, 0, sizeof(running_sum_arr));
	memset(running_count_arr, 0, sizeof(running_count_arr));
	memcpy(prev_ex, ex, sizeof(ex));


	for(int version = 0; version < 4; version++) {
		for (int i=1; i<=n; i++) {
			double running_sum = 0.0;
			int running_count = 0;
			for (int j=1; j<=n; j++) {
				auto c = get_coord_trans(i, j, version);
				auto nc = get_coord_trans(i, j+1, version);

				if (grid[c.first][c.second]) {
					running_sum += ex[c.first][c.second];
					running_count++;
					running_sum_arr[version][c.first][c.second] = running_sum;
					running_count_arr[version][c.first][c.second] = running_count;
					if(!grid[nc.first][nc.second]) {
						new_ex[c.first][c.second] += running_sum / 4.0;
						running_sum = 0.0;
						running_count = 0;
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

	// find the best place to place the "hub"
	// The hub is a structure that looks somewhat like this:
	// *#.#*
	// #...#
	// *###*
	//
	// Basically, it's two "caps" to have the robot keep moving back and forth,
	// and there's at least one "entrance" to the hub.

	vector<vector<bool>> places_empty = 
		{{0,0,1,0,0},
		 {0,1,1,1,0},
		 {0,0,0,0,0}};
	vector<vector<bool>> places_full = {
		 {0,1,0,1,0},
		 {1,0,0,0,1},
		 {0,1,1,1,0}
	};

	recalc_ex();


	pair<int,int> best_hub = make_pair(-1, -1);
	int best_score = 0;
	for (int i=1; i<=n-places_empty.size(); i++) {
		for (int j=1; j<=n-places_empty[0].size(); j++) {
			int rocks_matched = 0;
			assert(places_empty.size() == places_full.size());
			bool good = true;
			for (int ii=0; ii<places_empty.size(); ii++) {
				assert(places_empty[ii].size() == places_full[ii].size());
				for (int jj=0; jj<places_empty[ii].size(); jj++) {
					// Remember grid[i+ii][j+jj] is true if empty
					if (places_empty[ii][jj] && !grid[i+ii][j+jj]) {
						good = false;
						break;
					}
					if (places_full[ii][jj] && ex[i+ii][j+jj]>0.0) {
						good = false;
						break;
					}
					if (places_full[ii][jj] && !grid[i+ii][j+jj]) {
						rocks_matched++;
					}
				}
				if (!good) break;
			}
			if (rocks_matched > best_score) {
				best_score = rocks_matched;
				best_hub = make_pair(i,j);
			}
		}
	}

	if (best_hub.first == -1) {
		cerr << "No suitable hub found, running fallback." << endl;
		run_fallback();
	}
	cerr << "Best hub found at: " << best_hub.first << ", " << best_hub.second << " with score: " << best_score << endl;

	// Place the hub
	for (int ii=0; ii<places_full.size(); ii++) {
		for (int jj=0; jj<places_full[ii].size(); jj++) {
			if (places_full[ii][jj] && grid[best_hub.first + ii][best_hub.second + jj]) {
				int x = best_hub.first + ii;
				int y = best_hub.second + jj;
				grid[x][y] = false; // Place a rock
				ex[x][y] = 0.0; // Reset expected value
				cout << x-1 << " " << y-1 << endl; // Output the position
			}	
		}
	}


	// for(int loops =0; loops<empty_count; loops++) {
	// 	int best_i = -1;
	// 	int best_j = -1;
	// 	tuple<double,double,double> best_score = make_tuple(1e9, 1e9, 1e9);
	// 	recalc_ex();


	// 	for (int i=1; i<=n; i++) {
	// 		for (int j=1; j<=n; j++) {
	// 			if (!grid[i][j]) continue;

	// 			// Calculate amount of rocks in the neighborhood
	// 			int rock_count = 0;
	// 			double neighborhood_sum = 0.0;
	// 			for (int d=0; d<4; d++) {
	// 				int ni = i + dx[d];
	// 				int nj = j + dy[d];
	// 				rock_count+= (!grid[ni][nj]);
	// 				if (grid[ni][nj]) {
	// 					neighborhood_sum += ex[ni][nj];
	// 				}
	// 			}


	// 			 tuple<double,double,double> score = make_tuple(ex[i][j], -neighborhood_sum, (1.0*rand())/(RAND_MAX+1.0));	
	// 			// tuple<double,double,double> score = make_tuple(ex[i][j], total_concentration, (1.0*rand())/(RAND_MAX+1.0));

	// 			if (score < best_score ) {
	// 				best_i = i;
	// 				best_j = j;
	// 				best_score = score;
	// 			}
	// 		}
	// 	}

	// 	if (best_i != -1) {
	// 		positions.push_back(make_pair(best_i,best_j));
	// 		grid[best_i][best_j] = false;
	// 		ex[best_i][best_j] = 0.0;
	// 		cout<<best_i-1<<" "<<best_j-1<<endl;

	// 	}else{
	// 		break;	
	// 	}
	// }
	
	// {
	// 	empty_count = 0;
	// 	for (int i=1; i<=n; i++) {
	// 		for (int j=1; j<=n; j++) {
	// 			empty_count += (grid[i][j]==true);
	// 		}
	// 	}
	// 	assert(empty_count==0);
	// }

	// for (auto &p: positions) {
	// 	int x = p.first;
	// 	int y = p.second;
	// 	cout<<(x-1)<<" "<<(y-1)<<endl;
	// }
}

			




	
