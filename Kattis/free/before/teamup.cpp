#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


vector<unordered_map<int, int> > classes;

bool sss(int a, int b) {
	return classes[a].size() < classes[b].size();
}

int main() {
	int n, m, p;
	cin >> n >> m >> p;
	vector<vector<int> > children(m+1);
	classes.push_back(unordered_map<int, int>());
	for(int i=1; i<m+1; i++) {
	//cout << "adsfasd " << i << "\n" ;
		int size;
		cin >> size;

		int firstSkill;
		cin >> firstSkill;

		int c = 0;
		classes.push_back(unordered_map<int, int>());
		unordered_map<int, int> &current = classes.back();
		while (true) {
			//cout << "Going through "<< c << "\n";
			auto it = classes[c].find(firstSkill);
			if (it != classes[c].end() && it->second != -1 && classes[it->second].size() > size) {
				c = it->second;
			}
			else {
				break;
			}
		}
		//c should be parent


		unordered_map<int, int> &parent = classes[c];

		int currentPos = classes.size()-1;

		//cout << "Parent of "<< currentPos << " is " << c <<'\n';

		auto it = parent.find(firstSkill);
		if (it != parent.end()) {
			current[firstSkill] = it->second;
		}
		else {
			current[firstSkill] = -1;
		}
		parent[firstSkill] = currentPos;
		for (int j=1; j<size; j++) {
			int skill;
			cin >> skill;

			auto it = parent.find(skill);
			if (it != parent.end()) {
				current[skill] = it->second;
			}
		else {
			current[skill] = -1;
		}

			parent[skill] = currentPos;
		}
	}

	for(int i=0; i<m+1; i++) {

		unordered_set<int> keep;

		for (auto it = classes[i].begin(); it!=classes[i].end(); it++) {
			if (it->second !=-1 && keep.find(it->second) == keep.end()) {
				children[i].push_back(it->second);
				keep.insert(it->second);
				//cout << "Adding child "<< it->second << " to " << i << " \n";
			}
		}
	}


	vector<vector<int> > players(m+1);

	for(int i=1; i<=p; i++) {
		int c;
		cin >> c;

		players[c].push_back(i);
	////cout << "adsfasd\n";
	}

	vector<int> cs(m+1);
	for (int i=1; i<m+1; i++) {
		cs[i-1] = i;
	}
	cs[m] = 0;

	sort(cs.begin(), cs.end()-1, sss);
	/*
	cout << "weqr ";
	for(int i=0; i<cs.size(); i++) {
		cout << cs[i] << " ";
	}
	cout << "\n";
	*/

	vector<int> possibleTeams(m+1);

	for (int ii=0; ii<m+1; ii++) {
		int i = cs[ii];
		unordered_map<int, int> &current = classes[i];
		possibleTeams[i] = players[i].size();

		if (children[i].size()!=0) {
				//cout << i << " has children " << children[i].size() << " \n";
			int minTeamSize = 3000000;
			int tot = 0;
			for (int j=0; j< children[i].size(); j++) {
				//cout << "child " << children[i][j] <<'\n';
				tot+=classes[children[i][j]].size();
				//cout << "classes[child].size " << classes[children[i][j]].size() << '\n';
				if (possibleTeams[children[i][j]] < minTeamSize) {
					minTeamSize = possibleTeams[children[i][j]];
				}
			}
			//cout << "minTeamSize " << minTeamSize << '\n';
			//cout << "tot classes[i].size() " << tot << " " << classes[i].size() << '\n';
			if (tot==classes[i].size() || i==0) {
				//cout << " adding minTeamSize \n";
				possibleTeams[i] += minTeamSize;
			}
		}
		////cout << "ii i possibleTeams[i]" << ii << " " << i << " " << possibleTeams[i] << '\n';

	}

	cout << possibleTeams[0] << '\n';

	for(int i=0; i<possibleTeams[0]; i++){
		vector<int> stack;
		vector<int> result;
		stack.push_back(0);
		while(stack.size()!=0){
			int c = stack.back();
			stack.pop_back();
			if (players[c].size()!=0) {
				result.push_back(players[c].back ());
				players[c].pop_back();
			}
			else {
				for (int j = 0; j<children[c].size(); j++) {
					int u = children[c][j];
					stack.push_back(u);
				}
			}
		}
		cout << result.size() << " ";
		for(int j=0; j<result.size()-1; j++) {
			cout << result[j] << " ";
		}
		cout << result.back() << "\n";
	}
}




	
