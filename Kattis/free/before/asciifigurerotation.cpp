#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	bool first = true;
	while (true) {
		int n;
		cin >> n;
		if (n==0) break;
		char fig[100][n+1];
		memset(fig, ' ', sizeof(fig));

		getchar();

		for (int i=0; i<n; i++) {
			char c;
			int j=0;
			while (true) {
				c=getchar();
				//cout << "wew" << c << "\\wew\n";
				if (c=='\n') {
					break;
				}
				else if (c=='|') {
					fig[j][n-1-i]='-';
				}
				else if (c=='-') {
					fig[j][n-1-i]='|';
				}
				else {
					fig[j][n-1-i]=c;
				}
				j++;
			}
		}
		if (!first) {
			puts("");
		}
		else {
			first = false;
		}
		for(int i=0; i<100; i++){
			int lastNonSpace = -1;
			for(int j=0; j<n; j++){
				if (fig[i][j] != ' ') {
					lastNonSpace = j;
				}
			}
			fig[i][lastNonSpace+1] = '\0';
			if (lastNonSpace!=-1) {
			puts(fig[i]);
			}
		}

	}

}
