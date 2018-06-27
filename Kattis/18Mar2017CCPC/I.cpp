#include <iostream>
using namespace std;

int main(){
    int H, W, N, M;

    cin >> H >> W >> N >> M;
    
    long long image[W][H];
    long long kernel[M][N];

    for (int j=0; j<H; j++) {
        for (int i=0; i<W; i++) {
            cin>> image[i][j];
        }
    }

    for (int j=N-1; j>=0; j--) {
        for (int i=M-1; i>=0; i--) {
            cin>> kernel[i][j];
        }
    }

    long long result[W-M+1][H-N+1];

    for (int j=0; j<H-N+1; j++) {
        for (int i=0; i<W-M+1; i++) {
            result[i][j] = 0;
            for (int y=0; y<N; y++) {
                for (int x=0; x<M; x++) {
                    result[i][j] += kernel[x][y] * image[i+x][j+y];
                }
            }
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
}

