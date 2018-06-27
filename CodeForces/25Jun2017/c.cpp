#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;

    priority_queue<int, std::vector<int>, std::greater<int> > heap;

    stack<int> stack;

    int tot = 0;

    int re  = 1;

    for(int ii=0; ii<2*n; ii++) {
        string com;
        cin >> com;
        if (com == "add") {

            int i;
            cin >> i;

            stack.push(i);
            
        }
        else {
            
            if( !stack.empty() ) {
                if( stack.top() == re) {
                    //cerr << "re " << stack.top() << endl;
                    stack.pop();
                }
                else {
                    //cerr<< "top was " << stack.top() << endl;
                    while(!stack.empty() ) {
                        heap.push(stack.top());
                        stack.pop();
                    }
                    tot ++;
                    //cerr << "sort\n";

                    //cerr << "re " << heap.top() << endl;
                    heap.pop();
                }
            }
            else {
                //cerr << "re " << heap.top() << endl;
                heap.pop();
            }

            re ++;
        }
    }

    cout << tot <<endl;
}

