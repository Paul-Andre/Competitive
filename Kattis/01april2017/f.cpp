#include <iostream>
#include <priority_queue>
using namespace std;


Employee emp[100001];
vector<int> orig[100001];
vector<int> chang[100001];

struct Employee {
    int m;
    int r;
    int t;
}


bool operator<(Employee a, Employee b) {
    return a.r<b.r;
}

priority_queue<Employee> changeGraph(int e) {
    priority_queue<Employee> res;
    for (int i=0; i<orig[e].size(); i++) {



int main() {
    int E;
    cin >> E;


    for(int i=1; i<=E; i++) {
        int m, r, t;
        cin >> m >> r >> t;
        if (m==-1) {
            m = 0;
        }
        emp[i].m = m;
        emp[i].r = r;
        emp[i].t = t;
        orig[m].push_back(i);
    }
