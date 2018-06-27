#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;


int n,a, b;
int seals[100][2];

int main() {
    cin>>n>>a>>b;
    for(int i=0; i<n; i++) {
        cin >> seals[i][0] >> seals[i][1];
    }

    int tot = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (i != j) {

                for(int kkk=0; kkk<2; kkk++) {
                    for(int kkk=0; kkk<2; kkk++) {
                        for(int kkk=0; kkk<2; kkk++) {


                            if ( a>= seals[i][0] && a>=seals[j][0] && b>=seals[i][1] + seals[j][1]) {
                                tot = max(tot, seals[i][0]*seals[i][1] + seals[j][0]*seals[j][1]);
                            }

                            swap(seals[i][0], seals[i][1]);
                        }
                        swap(seals[j][0], seals[j][1]);
                    }
                    swap(a, b);
                }
            }
        }
    }
    cout<< tot<<endl;
}





