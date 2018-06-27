#include <bits/stdc++.h>

using namespace std;

int findWithShorten(vector<int> &parent, int i) {
	//cout << "Parent of " << i << " is " << parent[i] << '\n';
	if (parent[i]==-1) {
		return i;
	}
	int p = findWithShorten(parent, parent[i]);
	parent[i] = p;
	return p;
}

void merge(vector<int> &parent, vector<int> &rank, int i, int j) {
	//cout << "merging " << i << " " << j << '\n';
	int pi = findWithShorten(parent, i);
	int pj = findWithShorten(parent, j);
	//cout << "found parents\n";
	if (pi == pj) return;
	if (rank[pi]<rank[pj]) {
		parent[pi] = pj;
	}
	else if (rank[pi]>rank[pj]) {
		parent[pj] = pi;
	}
	else {
		parent[pj] = pi;
		rank[pi]++;
	}
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector< vector<char> > board(n,vector<char>(m));
    for(int board_i = 0;board_i < n;board_i++){
       for(int board_j = 0;board_j < m;board_j++){
          cin >> board[board_i][board_j];
       }
    }
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
		//cout << "Query number " << a0 << "\n";
        int x1;
        int y1;
        int x2;
        int y2;
        cin >> x1 >> y1 >> x2 >> y2;
		//cout << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';

		x1--; x2--; y1--; y2--;
		int w = x2-x1+1;
		int h = y2-y1+1;
		//cout << "x1 y1, x2 y2, w h  " << x1 << " " <<  y1 << " " << x2 << " " << y2 << " " << w << " " << h << '\n';

		vector<int> parent(w*h, -1);
		vector<int> rank(w*h, 0);
		for (int i=0; i<parent.size(); i++) {
			parent[i]=-1;
			rank[i]=0;
		}

		//cout << "x top part\n";
		for(int i=x1+1; i<=x2; i++) {
			if (board[i][y1]==board[i-1][y1]) {
				int enc1 = (i-x1)*h;
				int enc2 = (i-1-x1)*h;
				merge(parent,rank,enc1,enc2);
			}
		}
		//cout << "y left part\n";
		for(int i=y1+1; i<=y2; i++) {
			if (board[x1][i]==board[x1][i-1]) {
				int enc1 = i-y1;
				int enc2 = i-1-y1;
				merge(parent,rank,enc1,enc2);
			}
		}

		//cout << "x and y parts\n";
		for(int i=x1+1; i<=x2; i++) {
			for(int j=y1+1; j<=y2; j++) {
				////cout << i << " " << j << '\n';
				if (board[i][j]==board[i-1][j]) {
					//cout << "reshifted " << i-x1 << " " << j-y1 << '\n';
					int enc1 = (i-x1)*h+(j-y1);
					int enc2 = (i-1-x1)*h+(j-y1);
					merge(parent,rank,enc1,enc2);
				}
				if (board[i][j]==board[i][j-1]) {
					int enc1 = (i-x1)*h+(j-y1);
					int enc2 = (i-x1)*h+(j-1-y1);
					merge(parent,rank,enc1,enc2);
				}
			}
		}

		//cout << "diagonals\n";
		for(int i=x1; i<=x2-1; i++) {
			for(int j=y1+1; j<=y2; j++) {
				if (board[i][j]==board[i+1][j-1]) {
					int enc1 = (i-x1)*h+(j-y1);
					int enc2 = (i+1-x1)*h+(j-1-y1);
					merge(parent,rank,enc1,enc2);
				}
			}
		}
		
		//cout << "counting\n";
		int count = 0;
		for (int i=0; i<parent.size(); i++) {
			if (parent[i]==-1) {
				//cout << "Count incremented " << i << '\n';
				count++;
			}
		}
		cout << count << '\n';

    }
    return 0;
}

