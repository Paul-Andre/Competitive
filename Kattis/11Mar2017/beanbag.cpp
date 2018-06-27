#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {

    int B;
    cin >> B;

    int V[B];

    for(int i=0; i< B; i++) {
        cin >> V[i];
    }

    int T;
    cin >> T;

    vector<int> farms[T];
    for(int i=0; i<T; i++) {
        int M;
        cin >> M;
        for (int j=0; j<M; j++) {
            int a;
            cin >>a;
            farms[i].push_back(a);
        }
    }
    // bean chosen
    vector<vector<int>> ct(T,vector<int>(B,10000000));
    // bean no chosen
    vector<vector<int>> nt(T,vector<int>(B,10000000));


    int min = V[0];
    int mini = 0;
    for (int i=1; i<V; i++) {
        if (V[i]>min) {
            min = V[i];
            mini = i;
        }
    }
    int min2 = 10000000;
    int mini2 = -1;
    for (int i=0; i<V; i++) {
        if (i!=mini && V[i]>min2) {
            min2 = V[i];
            mini2 = i;
        }
    }

    for (int j=0; j<farms[0].size(); j++) {
        int b = farms[0][j];
        ct[0][b] = V[b];
    }
    for (int i=0; j<B; j++) {
        nt[0][b] = min;
    }
    nt[0][mini] = min2;

    for (int i=1; i<
    




}
