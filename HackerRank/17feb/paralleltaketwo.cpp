#include <bits/stdc++.h>

#define NO_PARENT (-800*800*800)

using namespace std;

struct Rect {
	int x1;
	int x2;
	int y1;
	int y2;
};

Rect makeRect(int x1, int y1, int x2, int y2) {
	Rect r;
	r.x1 = x1;
	r.y1 = y1;
	r.x2 = x2;
	r.y2 = y2;
	return r;
}

Rect bbMerge(Rect const &a, Rect const &b) {
	Rect c;
	c.x1 = min(a.x1, b.x1);
	c.y1 = min(a.y1, b.y1);
	c.x2 = max(a.x2, b.x2);
	c.y2 = max(a.y2, b.y2);
	return c;
}

bool isInside(Rect const &a, Rect const &b) {
	return
		a.x1>=b.x1
		&& a.x2<=b.x2
		&& a.y1>=b.y1
		&& a.y2<=b.y2;
}

bool intersects(Rect const &a, Rect const &b) {
	return
		a.x1<=b.x2
		&& b.x1<=a.x2
		&& a.y1<=b.y2
		&& a.y2>=b.y1;
}

struct Quad {
	int tot;
	Rect bb;
	vector<Rect> free;
	vector<Quad> subs;
};

#define CHILD_SIZE 9

void initQuad(Quad &q, Rect bb) {
	//cout << "Initing quad with " << bb.x1 << " " << bb.y1 << " " << bb.x2 << " " << bb.y2 << '\n';
	q.tot=0;
	q.bb=bb;
	if (bb.x2-bb.x1>=CHILD_SIZE && bb.y2-bb.y1>=CHILD_SIZE) {
		//cout << "Creating a new vector of children\n";
		//cout << "(int quad of ) " << bb.x1 << " " << bb.y1 << " " << bb.x2 << " " << bb.y2 << '\n';
		q.subs = vector<Quad>(4);
		int xm = (bb.x2+bb.x1)/2;
		int ym = (bb.y2+bb.y1)/2;
		initQuad(q.subs[0],makeRect(bb.x1,bb.y1,xm,ym));
		initQuad(q.subs[1],makeRect(xm+1,bb.y1,bb.x2,ym));
		initQuad(q.subs[2],makeRect(bb.x1,ym+1,xm,bb.y2));
		initQuad(q.subs[3],makeRect(xm+1,ym+1,bb.x2,bb.y2));
	}
}

void insertIntoQuad(Quad &q, Rect r) {
	q.tot++;
	for(int i=0; i<q.subs.size(); i++){
		if(isInside(r, q.subs[i].bb)){
			insertIntoQuad(q.subs[i],r);
			return;
		}
	}
	q.free.push_back(r);
}

int findInside(Quad &q, Rect r) {
	//cout << "FInding rectangles in quad " << q.bb.x1 << " " << q.bb.y1 << " " << q.bb.x2 << " " << q.bb.y2 << "\n";
	//cout << "rectangle is " << r.x1 << " " << r.y1 << " " << r.x2 << " " << r.y2 << "\n";
	if (isInside(q.bb,r)) {
		//cout <<  "Returning tot\n";
		return q.tot;
	}
	if (!intersects(q.bb,r)) {
		//cout <<  "Not intersecting, returning 0\n";
		return 0;
	}
	int tot = 0;
	for(int i=0; i<q.subs.size(); i++) {
		tot += findInside(q.subs[i], r);
	}
	for (int i=0; i<q.free.size(); i++) {
		if (isInside(q.free[i], r)){
			tot++;
		}
	}
	return tot;
}

int findWithShorten(vector<int> &parent, int i) {
	//cout << "Parent of " << i << " is " << parent[i] << '\n';
	if (parent[i]==-1) {
		return i;
	}
	int p = findWithShorten(parent, parent[i]);
	parent[i] = p;
	return p;
}

void merge(vector<int> &parent, vector<int> &rank, vector<Rect> &bb, int i, int j) {
	//cout << "merging " << i << " " << j << '\n';
	int pi = findWithShorten(parent, i);
	int pj = findWithShorten(parent, j);
	//cout << "found parents\n";
	if (pi == pj) return;

	Rect newBB = bbMerge(bb[pi], bb[pj]);

	if (rank[pi]<rank[pj]) {
		parent[pi] = pj;
		bb[pj] = newBB;
	}
	else if (rank[pi]>rank[pj]) {
		parent[pj] = pi;
		bb[pi] = newBB;
	}
	else {
		parent[pj] = pi;
		bb[pi] = newBB;
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

	vector<int> parent(n*m, -1);
	vector<int> rank(n*m, 0);
	vector<Rect> bb(n*m);

    vector< vector<int> > horizontalDiff(m,vector<int>(n));
    vector< vector<int> > verticalDiff(n,vector<int>(m));

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			bb[i*m+j].x1=i;
			bb[i*m+j].x2=i;
			bb[i*m+j].y1=j;
			bb[i*m+j].y2=j;
		}
	}


	for(int i=0; i<n; i++) {
		verticalDiff[i][0] = 0;
		for(int j=1; j<m; j++) {
			verticalDiff[i][j] = verticalDiff[i][j-1];
			if (board[i][j]!=board[i][j-1]) {
				verticalDiff[i][j] ++;
			}
		}
	}

	for(int j=0; j<m; j++) {
		horizontalDiff[j][0] = 0;
		for(int i=1; i<n; i++) {
			horizontalDiff[j][i] = horizontalDiff[j][i-1];
			if (board[i][j]!=board[i-1][j]) {
				horizontalDiff[j][i] ++;
			}
		}
	}

	//cout << "x top part\n";
	for(int i=1; i<n; i++) {
		if (board[i][0]==board[i-1][0]) {
			int enc1 = (i)*m;
			int enc2 = (i-1)*m;
			merge(parent,rank,bb,enc1,enc2);
		}
	}
	//cout << "y left part\n";
	for(int i=1; i<m; i++) {
		if (board[0][i]==board[0][i-1]) {
			int enc1 = i;
			int enc2 = i-1;
			merge(parent,rank,bb,enc1,enc2);
		}
	}

	for(int i=1; i<n; i++) {
		for(int j=1; j<m; j++) {
			////cout << i << " " << j << '\n';
			if (board[i][j]==board[i-1][j]) {
				//cout << "reshifted " << i-x1 << " " << j-y1 << '\n';
				int enc1 = (i)*m+(j);
				int enc2 = (i-1)*m+(j);
				merge(parent,rank,bb,enc1,enc2);
			}
			if (board[i][j]==board[i][j-1]) {
				int enc1 = (i)*m+(j);
				int enc2 = (i)*m+(j-1);
				merge(parent,rank,bb,enc1,enc2);
			}
		}
	}

	//cout << "diagonals\n";
	for(int i=0; i<n-1; i++) {
		for(int j=1; j<m; j++) {
			if (board[i][j]==board[i+1][j-1]) {
				int enc1 = (i)*m+(j);
				int enc2 = (i+1)*m+(j-1);
				merge(parent,rank,bb,enc1,enc2);
			}
		}
	}


	//map<int,map<int,map<int,map<int,int > > > > cycles;
	Quad newCycles;
	initQuad(newCycles, makeRect(0,0, n, m));


	
	for (int i=0; i<parent.size(); i++) {
		if (parent[i]==-1) {
			if (bb[i].x1!=0 && bb[i].y1!=0 && bb[i].x2!=n-1 && bb[i].y2!=m-1) {
				Rect newRect;
				newRect.x1 = bb[i].x1-1;
				newRect.x2 = bb[i].x2+1;
				newRect.y1 = bb[i].y1-1;
				newRect.y2 = bb[i].y2+1;
				/*
				if (newRect.x1==47 && newRect.y1==94) {
				cout << "Found cycle: at position " << newRect.x1 << " " << newRect.y1 << " " << newRect.x2 << " " << newRect.y2 << "\n";
				for (int i=newRect.x1; i<=newRect.x2; i++) {
					for (int j=newRect.y1; j<=newRect.y2; j++) {
						if (board[i][j]=='B') {
							cout << '@';
						}
						else {
							cout << ' ';
						}
					}
					cout << '\n';
				}
				}
				*/

				//cycles[newRect.x1][newRect.y1][newRect.x2][newRect.y2]++;
				insertIntoQuad(newCycles, newRect);
			}
		}
	}

    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
		//cout << "\n\nQuery number " << a0+1 << "\n";
        int x1;
        int y1;
        int x2;
        int y2;
        cin >> x1 >> y1 >> x2 >> y2;
		//cout << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';

		x1--; x2--; y1--; y2--;
		//int w = x2-x1+1;
		//int h = y2-y1+1;
		//

		/*
		for (int i=x1; i<=x2; i++) {
			for (int j=y1; j<=y2; j++) {
				if (board[i][j]=='B') {
					cout << '@';
				}
				else {
					cout << ' ';
				}
			}
			cout << '\n';
		}
		*/

		/*

		int naturalBirths = 1;
		int naturalDeaths = 1;

		//cout << "doing thing in x on bottom : \n";
		//cout << board[x1][y2];
		for(int i=x1+1; i<=x2; i++) {
			//cout << board[i][y2];
			if (board[i][y2]!=board[i-1][y2]) {
				naturalBirths++;
			}
		}
		//cout << '\n';

		//cout << "doing thing in y on left: \n";
		//cout << board[x1][y2];
		for(int i=y1+1; i<=y2; i++) {
			//cout << board[x1][i];
			if (board[x1][i]!=board[x1][i-1]) {
				naturalBirths++;
			}
		}

		//cout << "doing thing in x on top : \n";
		//cout << board[x1][y1];
		for(int i=x1+1; i<=x2; i++) {
			//cout << board[i][y1];
			if (board[i][y1]!=board[i-1][y1]) {
				naturalDeaths++;
			}
		}
		//cout << '\n';

		//cout << "doing thing in y on right: \n";
		//cout << board[x2][y2];
		for(int i=y1+1; i<=y2; i++) {
			//cout << board[x2][i];
			if (board[x2][i]!=board[x2][i-1]) {
				naturalDeaths++;
			}
		}
		*/

		int testingNaturalBirths = 1 + horizontalDiff[y2][x2] - horizontalDiff[y2][x1] + verticalDiff[x1][y2] - verticalDiff[x1][y1];
		int testingNaturalDeaths = 1 + horizontalDiff[y1][x2] - horizontalDiff[y1][x1] + verticalDiff[x2][y2] - verticalDiff[x2][y1];

		/*
		if (testingNaturalBirths!=naturalBirths || testingNaturalDeaths!=naturalDeaths) {
			cout << "ERROR, test did not succeed\n";
			return 0;
		}
		*/

		//cout << '\n';

		//cout << "naturalBirths naturalDeaths " << naturalBirths << " " << naturalDeaths << '\n';

		// shit
		// // this shit actually made my code fail one more test case. Maybe I should just use plain arrays?
		//int numCycles = 0;
		int newNumCycles = findInside(newCycles, makeRect(x1,y1,x2,y2));

		/*
		auto itLow = cycles.lower_bound(x1);
		auto itHigh = cycles.upper_bound(x2);
		for(auto it = itLow; it!=itHigh; it++){
			auto ittLow = it->second.lower_bound(y1);
			auto ittHigh = it->second.upper_bound(y2);
			for(auto itt = ittLow; itt!=ittHigh; itt++){
				auto itttLow = itt->second.begin();
				auto itttHigh = itt->second.upper_bound(x2);
				for(auto ittt = itttLow; ittt!=itttHigh; ittt++){
					auto ittttLow = ittt->second.begin();
					auto ittttHigh = ittt->second.upper_bound(y2);
					for(auto itttt = ittttLow; itttt!=ittttHigh; itttt++){
						numCycles += itttt->second;
					}
				}
			}
		}
		if (numCycles != newNumCycles) {
			cout << "ERROR: don't match\n";
			cout << "numCycles newNumCycles " << numCycles << " " << newNumCycles << '\n';
			return 1;
		}
		*/

		cout << (testingNaturalBirths+testingNaturalDeaths)/2+newNumCycles << '\n';

    }
    return 0;
}
