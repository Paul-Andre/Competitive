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

void calculate_running_sums() {

	memset(running_sum_arr, 0, sizeof(running_sum_arr));
	memset(running_count_arr, 0, sizeof(running_count_arr));


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
						running_sum = 0.0;
						running_count = 0;
					}
				}
			}
		}
	}
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

	for(int loops =0; loops<empty_count; loops++) {
		int best_i = -1;
		int best_j = -1;
		tuple<double,double,double> best_score = make_tuple(1e9, 1e9, 1e9);
		recalc_ex();
		// calculate_running_sums();

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

				// Calculate amount of rocks in the neighborhood
				int rock_count = 0;
				double neighborhood_sum = 0.0;
				for (int d=0; d<4; d++) {
					int ni = i + dx[d];
					int nj = j + dy[d];
					rock_count+= (!grid[ni][nj]);
					if (grid[ni][nj]) {
						neighborhood_sum += ex[ni][nj];
					}
				}
				// int num_rs_zero = 0;
				// double rs_sum = 0.0;
				// 				double total_concentration = 0.0;

				// for (int d=0; d<4; d++) {
				// 	if (running_sum_arr[d][i][j] == 0.0) {
				// 		num_rs_zero++;
				// 	}
				// 	rs_sum += running_sum_arr[d][i][j];
				// 	if (running_count_arr[d][i][j] > 1) {
				// 		total_concentration += (running_sum_arr[d][i][j]-ex[i][j]) / (running_count_arr[d][i][j]-1);
				// 	}
				// }
				// // First process horizontal runs, then vertical runs

				// double increased_concentration = 0.0;
				// for (int orient= 0; orient<4; orient+=2) {
				// 	double Aval = running_sum_arr[orient][i][j] - ex[i][j];
				// 	double Bval = running_sum_arr[orient+1][i][j] - ex[i][j];
				// 	int Anum = running_count_arr[orient][i][j]-1;
				// 	int Bnum = running_count_arr[orient+1][i][j]-1;
				// 	if (Anum == 0 || Bnum == 0) {
				// 		continue;
				// 	}
					
				// 	int ABnum = Anum + Bnum;
				// 	double ABval = Aval + Bval;
				// 	double ABunit = ABval / ABnum;
				// 	double ABscore = ABnum*(ABnum+1) / 2.0 * ABunit;

				// 	double Aunit = Aval / Anum;
				// 	double Bunit = Bval / Bnum;
					
				// 	{
				// 		double Ascore = Anum*(Anum+1) / 2.0 * Aunit;
				// 		double Bscore = Bnum*(Bnum+1) / 2.0 * Bunit;
				// 		double partitioned_score = max(
				// 			Ascore + Anum*Bnum*Bunit + Bscore,
				// 			Bscore + Bnum*Anum*Aunit + Ascore
				// 		);
				// 		increased_concentration += partitioned_score - ABscore;

				// 	}
				
				// }


				//tuple<double,double,double> score = make_tuple(ex[i][j], -neighborhood_sum, (1.0*rand())/(RAND_MAX+1.0));
				 tuple<double,double,double> score = make_tuple(ex[i][j], -neighborhood_sum, (1.0*rand())/(RAND_MAX+1.0));	
				// tuple<double,double,double> score = make_tuple(ex[i][j], total_concentration, (1.0*rand())/(RAND_MAX+1.0));

				if (score < best_score ) {
					best_i = i;
					best_j = j;
					best_score = score;
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

			




	
