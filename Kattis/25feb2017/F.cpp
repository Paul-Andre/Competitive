#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define MOD 1000000007

int main() {
	int N, K;
	cin >> N >> K;

	vector<vector<int>> tree(N);

	for(int i=0; i<N-1; i++) {
		int u, v;
		cin >> u >> v;
		u--; 
		v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	vector<vector<long long>> table(17);
	vector<vector<vector<long long>>> tless(17);

	table[0] = vector<long long>(N,1);

	long long tot = N;

	for (int i=1; i<17; i++) {
		table[i] = vector<long long>(N);

		for(int j=0; j<N; j++) {
			//cout << "i j " << i << " " << j << '\n';

			int valid=0;
			int size = tree[j].size();

			//if (size < K) continue;

			vector<vector<long long>> tt(K+1,vector<long long>(size));
			for (int i=0; i<size; i++) {
				tt[0][i] = 1;
			}

			tt[1][0] = table[i-1][tree[j][0]];
			for (int k=2; k<=K; k++) {
				tt[k][0] = 0;
			}

			for (int k=1; k<=K; k++) {
				for (int ii=1; ii<size; ii++) {
					tt[k][ii] = tt[k][ii-1] + (tt[k-1][ii-1]*table[i-1][tree[j][ii]])%MOD;
					//cout << " table " << table[i-1][tree[j][ii]] << "\n";
					//cout << " tt[k-1][ii-1] " << table[k-1][ii-1] << "\n";
					tt[k][ii] %= MOD;
					//cout << "k ii tt[][] " << k << " " << ii << " " << tt[k][ii] << '\n';
				}
			}
			table[i][j] = tt[K][size-1];
			cout << i << " " << j <<  " got: " << tt[K][size-1] << '\n';
			tot += tt[K][size-1];
			tot %= MOD;
		}

	}


	cout << tot;
}





	

	


