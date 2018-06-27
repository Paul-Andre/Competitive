#include <iostream>
using namespace std;

struct Node{
	int x;
	int y;
	int rank;
};

struct Pair{
	int x;
	int y;
};

bool operator==(const Pair &self, const Pair &other){
	return self.x==other.x && self.y==other.y;
}

bool operator!=(const Pair &self, const Pair &other){
	return !(self == other);
}

int r, c;
bool map[1000][1000];
Node nodes[1000][1000];

Pair find(int x, int y){
	Node *node = &nodes[x][y];
	if (node->x==-1) {
		Pair ret;
		ret.x = x;
		ret.y = y;
		return ret;
	}
	Pair root = find(node->x, node->y);
	node->x = root.x;
	node->y = root.y;
	return root;
}

void merge(int x1, int y1, int x2, int y2) {
	Pair p1 = find(x1,y1);
	Pair p2 = find(x2,y2);
	if (p1 != p2) {
		Node *n1 = &nodes[p1.x][p1.y];
		Node *n2 = &nodes[p2.x][p2.y];
		if (n1->rank < n2->rank) {
			n1->x = p2.x;
			n1->y = p2.y;
		}
		else if (n1->rank > n2->rank) {
			n2->x = p1.x;
			n2->y = p1.y;
		}
		else {
			n1->x = p2.x;
			n1->y = p2.y;
			n2->rank++;
		}
	}
}

void initializeNode(int x, int y) {
	nodes[x][y].rank=0;
	nodes[x][y].x=-1;
}


int main(){
	cin >> r >> c;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			char ch;
			cin >> ch;
			map[i][j] = (ch=='1');
			initializeNode(i,j);
		}
	}


	for (int i=1; i<r; i++) {
		if (map[i-1][0]==map[i][0]) {
			merge(i-1,0,i,0);
		}
	}

	for (int j=1; j<c; j++) {
		if (map[0][j-1]==map[0][j]) {
			merge(0,j-1, 0,j);
		}
	}

	for (int i=1; i<r; i++) {
		for (int j=1; j<c; j++) {
			if (map[i-1][j]==map[i][j]) {
				merge(i-1,j,i,j);
			}
			if (map[i][j-1]==map[i][j]) {
				merge(i,j-1, i,j);
			}
		}
	}

	int n;
	cin >> n;
	while(n--){
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--;
		c1--;
		r2--;
		c2--;
		/*
			Pair p1 = find(r1,c1);
			Pair p2 = find(r2,c2);
			cout << "\n" << p1.x << " " << p1.y << " , " << p2.x << " " << p2.y << "\n";
			*/
		if (map[r1][c1] == map[r2][c2] && find(r1,c1) == find(r2,c2)){
			if (map[r1][c1]) {
				cout << "decimal\n";
			}
			else {
				cout << "binary\n";
			}

		}
		else {
			cout << "neither\n";
		}

	}
	
}

