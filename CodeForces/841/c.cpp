#include <bits/stdc++.h>
using namespace std;

int m;

typedef pair<int,int> pii;
typedef pair<pii,int> piii;

int ans[200000];

int A[200000];
pii B[200000];

int main() {
    ios::sync_with_stdio(false);
    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>A[i];
        A[i] *= -1;
    }
    for(int i=0;i<m;i++) {
        cin>>B[i].first;
        B[i].second = i;
    }

    sort(A, A+m);
    sort(B, B+m);

    for(int i=0; i<m; i++) {
        ans[B[i].second] = A[i]*-1;
    }

    for(int i=0; i<m; i++)  {
        cout << ans[i] << " ";
    }
    cout <<endl;
}
