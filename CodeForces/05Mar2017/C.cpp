#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<vector<int> > tree(n);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        tree[u].push_back(v);
        tree[v].push_back(u);

    }

    vector<bool> vis(n,false);
    vector<int> color(n,0);
    vector<int> prev(n,0);

    vector<int> stack;
    vector<int> prevStack;

    color[0] = 1;
    vis[0] = true;
    
    for (int i=0; i<tree[0].size(); i++) {
        int j = tree[0][i];
        color[j] = i+2;
         //       cout << "Colored " << j << " with " << i+2 << '\n';
        prev[j] = 1;
        vis[j] = true;
        stack.push_back(j);
    }

    while(stack.size()!=0) {
        int u = stack.back();
        //cout << u << " u \n";
        stack.pop_back();

        int col = 1;
        for (int i=0; i<tree[u].size(); i++) {
            int j = tree[u][i];
            
            if (!vis[j]) {
                //cout << " a: " << col;
                if (col==color[u]) col++;
                if (col==prev[u]) col++;
                if (col==color[u]) col++;
                //cout << " c: " << col;

                //cout << '\n';

                //cout << "color[u] prev[u] " << color[u] << " " << prev[u] << '\n';
                //cout << "Colored " << j << " with " << col << '\n';

                color[j] = col;
                prev[j] = color[u];
                vis[j] = true;
                stack.push_back(j);
                col++;
            }
        }
    }

    int m = 0;
    for (int i=0; i<n; i++) {
        m = max(m, color[i]);
    }
    cout << m <<'\n';
    for (int i=0; i<n; i++) {
        cout << color[i] << ' ';
    }
    cout <<'\n';

    return 0;
}
