#include <bits/stdc++.h>
using namespace std;


int N;

vector<int> orig[1001];

int depth[1001];

vector<int> childs[1001];
int parent[1001];

vector<int> ordering;

void rooot(int i, int d) {
    if (depth[i] != 0) return;
    depth[i] = d;
    for(int j=0;j<orig[i].size(); j++) {
        int u = orig[i][j];
        parent[u] = i;
        childs[i].push_back(u);
        rooot(u, d+1);
    }
    ordering.push_back(i);
}

int origA[1000];
int origB[1000];
int origX[1000];
int origT[1000];


double mult[1001];
bool super[1001];

double minn[1001];

int main() {
    cin >> N;

    for(int i=0; i<N-1; i++) {
        int A,B,X,T;
        cin>>A>>B>>X>>T;
        orig[B].push_back(A);
        orig[A].push_back(B);
        origA[i] = A;
        origB[i] = B;
        origX[i] = X;
        origT[i] = T;
    }

    rooot(1,1);

    for(int i=0; i<N-1; i++) {
        int A = origA[i];
        int B = origB[i];
        int X = origX[i];
        int T = origT[i];

        if (depth[A] > depth[B]) {
            B = A;
        }

        mult[B] = X*0.01;
        super[B] = T;
    }
    
    for(int i=1; i<=N; i++) {
        cin >> minn[i];
    }


    for(int ii=0; ii<N; ii++) {
        int i = ordering[ii];

        if (minn[i] == -1) {

            double tot = 0;

            for(int j=0; j<childs[i].size(); j++) {
                int u = childs[i][j];



    



