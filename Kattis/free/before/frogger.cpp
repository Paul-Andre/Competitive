#include <iostream>
#include <queue>
using namespace std;

int main(){
	int kkk;
	cin >> kkk;
	while(kkk--){
		int maxRounds, n, m;
		cin >> maxRounds >> n >> m;
		// [time cycle][lane(+ curbs)][position in lane]
		bool map[m][n+2][m];
		for(int i=0; i<m; i++){
			for(int k=0; k<m; k++){
				map[k][0][i]=false;
				map[k][n+1][i]=false;
			}
		}
		int goal;
		for(int i=0; i<m; i++){
			char c;
			cin >> c;
			if(c=='G'){
				goal=i;
			}
		}

		int alt;
		if (n%2==0) {
			alt=-1;
		}
		else {
			alt=1;
		}
		for(int j=0; j<n; j++){
			for(int i=0; i<m; i++){
				char c;
				cin >> c;
				for(int k=0; k<m; k++){
					map[k][j+1][(m+i+alt*k)%m]= (c=='X');
				}
			}
			alt*=-1;
		}

		/*
		for(int k=0; k<m; k++){
			cout << "At time " << k << ":\n";
			for(int j=0; j<n+2; j++){
				for(int i=0; i<m; i++){
					cout << map[k][j][i];
				}
				cout << "\n";
			}
			cout << "\n";
		}
		*/

		int time = 0;
		queue<int> xq;
		queue<int> yq;
		{
			int x;
			int y=n+1;
			for(int i=0; i<m; i++){
				char c;
				cin >> c;
				if(c=='F'){
					x=i;
				}
			}
			xq.push(x);
			yq.push(y);
			map[time][y][x]=true;
		}

		while(time<=maxRounds && !xq.empty()){
			int currentStep = xq.size();
			int nextTime = (time+1)%m;
			for(int i=0; i<currentStep; i++){
				int x = xq.front(); xq.pop();
				int y = yq.front(); yq.pop();
				//cout << x << " " << y<< endl;
				if (x==goal && y==0){
					cout << "The minimum number of turns is "<<time<<".\n";
					goto continue_outer;
				}

				if(x>=1 && !map[nextTime][y][x-1]){
					map[nextTime][y][x-1]=true;
					xq.push(x-1);
					yq.push(y);
				}
				if(x<=m-2 && !map[nextTime][y][x+1]){
					map[nextTime][y][x+1]=true;
					xq.push(x+1);
					yq.push(y);
				}
				if(y>=1 && !map[nextTime][y-1][x]){
					map[nextTime][y-1][x]=true;
					xq.push(x);
					yq.push(y-1);
				}
				if(y<=n && !map[nextTime][y+1][x]){
					map[nextTime][y+1][x]=true;
					xq.push(x);
					yq.push(y+1);
				}
				if(!map[nextTime][y][x]){
					map[nextTime][y][x]=true;
					xq.push(x);
					yq.push(y);
				}
			}
			time++;
		}
		cout << "The problem has no solution.\n";

continue_outer:;
	}
}

