#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int dead[4] = {0,0,0,0};
	int color[4] = {-1,-1,-1,-1};

	for(int i=0; i<s.size(); i++) {
		char c = s[i];
		if(c=='!'){
			dead[i%4]++;
		}
		else {
			int a; 
		   	if(c=='R') {
				a=0;
			}
			else if(c=='B') {
				a=1;
			}
			else if(c=='Y') {
				a=2;
			}
			else if(c=='G') {
				a=3;
			}
			color[a]=i%4;
		}
	}
	cout << dead[color[0]] << " "
		<< dead[color[1]] << " "
		<< dead[color[2]] << " "
		<< dead[color[3]] << "\n";


}


