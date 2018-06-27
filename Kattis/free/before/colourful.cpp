#include <iostream>
#include <vector>
using namespace std;

vector<int> color;
vector<int> colorCount;
vector<int> target;
vector<int> targetCount;
vector<int> wrongCount;

vector<int> inRightPlace; // the 
vector<vector<int> > graph;
vector<vector<int> > tree;

void printGraph() {
	for (int i=0; i<color.size()-1; i++) {
		cout << color[i] << " ";
	}
	cout << color.back() << '\n';
}



bool moveElsewhere(int i, vector<bool> &vis) {
	for (int j=0; j<graph[i].size(); j++) {
		int u = graph[i][j];
		if (!vis[u]) {
			vis[u] = true;
			if (target[u] != color[u] && target[u] == color[i]) {
				int tmp = color[u];
				color[u] =  color[i];
				color[i] = tmp;
				printGraph();
				return true;
			}
			else {
				int tmp = color[u];
				color[u] =  color[i];
				color[i] = tmp;
				printGraph();
				bool ret = moveElsewhere(u,vis);

				tmp = color[u];
				color[u] =  color[i];
				color[i] = tmp;
				printGraph();

				if (ret) return true;
			}
		}
	}
	return false;
}

bool getColorFromElsewhere(int col, int i, vector<bool> &vis) {
	for (int j=0; j<graph[i].size(); j++) {
		int u = graph[i][j];
		if (!vis[u]) {
			vis[u] = true;
			//cout << "u " << u << "\n";
			if (color[u] == col) {
				color[i] = col;
				printGraph();
				return true;
			}
			else {
				int tmp = color[u];
				color[u] =  color[i];
				color[i] = tmp;
				printGraph();
				bool ret = getColorFromElsewhere(col, u,vis);

				tmp = color[u];
				color[u] =  color[i];
				color[i] = tmp;
				printGraph();

				if (ret) return true;
			}
		}
	}
	return false;
}
				

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	colorCount = vector<int>(k,0);
	targetCount = vector<int>(k,0);

	inRightPlace = vector<int>(k,0);

	color = vector<int>(n);
	target = vector<int>(n);
	graph = vector<vector<int> >(n);
	tree = vector<vector<int> >(n);

	for(int i=0; i<n; i++){
		int c;
		cin >> c;
		color[i] = c;
		colorCount[c]++;
	}

	for(int i=0; i<n; i++){
		int c;
		cin >> c;
		target[i] = c;
		targetCount[c]++;
		if (color[i]==c) {
			inRightPlace[c]++;
		}
		if (colorCount[c]==0) {
			cout << "Impossible\n";
			return 0;
		}
	}

	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	printGraph();
	for (int i=0; i<n; i++) {
		//cout << "first "<< i <<"\n";
		while (color[i]!=target[i] && inRightPlace[color[i]]!=targetCount[color[i]]) {
		//cout << "first inner "<< i <<"\n";
			int col = color[i];
			vector<bool> vis(n,false);
			vis[i] = true;
			moveElsewhere(i,vis);
			inRightPlace[col]++;
			if (color[i] == target[i]) {
				inRightPlace[color[i]]++;
			}
		}
	}

	for (int i=0; i<n; i++) {
		////cout << "second "<< i <<"\n";
		while (color[i]!=target[i]) {
		//cout << "second inner " << i << "\n";
			int col = color[i];
			vector<bool> vis(n,false);
			vis[i] = true;
			getColorFromElsewhere(target[i], i,vis);
			inRightPlace[col]++;
		}
	}
}

