#include <bits/stdc++.h>
using namespace std;

int n, k;
int q;
int A[100001];

class T{
    public:
    int a, b;
    int num;
    T * left;
    T * right;

    T(int a, int b) {
        this->a = a;
        this->b = b;
        if (a == b) {
            num = A[a];
        }
        else {
            int c = (a+b)/2;
            left = new T(a, c);
            right = new T(c+1, b);
            num = left->num + right ->num;
        }
    }

    int get(int a_, int b_) {
        if (a_>b || b_<a) {
            return 0;
        }
        if (a_<=a && b_>=b) {
            return num;
        }
        else {
            return left->get(a_, b_) + right->get(a_, b_);
        }
    }
};

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> A[i+1];
    }

    T t(1, 100000);

    int last = 0;

    cin >> q;

    for (int i=0; i<q; i++) {
        int x, y;
        cin >> x >> y;

        int l = ((x + last)%n) + 1;
        int r = ((y + last)%n) + 1;

        if (l>r) {
            int tmp = l;
            l = r;
            r = tmp;
        }

        cout << l << " " << r << endl;

        last = t.get(l,r);
        cout << last << endl;
    }
}
