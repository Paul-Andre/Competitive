#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


struct frac{
    long num;
    long den;
};

frac mF(long a, long b) {
    if (b < 0) {
        a *=-1;
        b *=-1;
    }
    frac f;
    f.num = a;
    f.den = b;
    return f;
}

bool fracEq(frac a, frac b) {
    return a.num*b.den == b.num*a.den;
}

bool fracGe(frac a, frac b) {
    return a.num*b.den >= b.num*a.den;
}

bool operator<(frac a, frac b) {
    return a.num*b.den < b.num*a.den;
}

int slopesMax(vector<frac> &slope1, vector<frac> &slope2) {
    int m = 0;
    int i=slope1.size();
    int j=slope2.size();
    frac s = mF(0,1);
    while (true) {
        //cout << s << '\n';
        //cout << "i j " <<  i << " " << j << '\n';
        //cout << "asdfad " <<  slope1[i] << " " << slope2[j] << '\n';
        int saw = 0;
        while (i>0 && fracGe( slope1[i-1], s)) {
            //cout << "weadfi";
            if ( fracEq(slope1[i-1],s) ) {
                saw ++;
            }
            i--;
        }
        while (j>0 && fracGe (slope2[j-1], s)) {
            //cout << "weadfj";
            j--;
        }
        //cout << "i j :" <<  i << " " << j << '\n';

        m = max(m, (i) + saw + (int)(slope2.size()- j));
        if (i==0 && j==0) break;
        else if (i==0) {
            m = max(m, (int)(slope2.size())- j);
            break;

        }
        else if (j==0) {
            m = max(m, i);
            break;
        }
        else {
            //cout << "asdfa asdfa asdf\n";
            s = max(slope1[i-1], slope2[j-1]);
        }
    }
    return m;
}

int main() {
    int N;
    cin >> N;
    N--;

    int a, b;
    cin >> a >> b;

    int better = 0;
    int same = 0;

    int sameABetter = 0;
    int sameBBetter = 0;
    int sameAWorse = 0;
    int sameBWorse = 0;

    vector<frac> slope1;
    vector<frac> slope2;

    for (int i=0; i< N; i++) {
        int c, d;
        cin >> c >> d;
        if (c> a && d > b) {
            better ++;
        }
        else if (c< a && d < b) {
        }
        else if (c==a && d == b) {
            same ++;
        }
        else if (c==a && d == b) {
            same ++;
        }
        else if (c==a && d > b) {
            sameABetter ++;
        }
        else if (c>a && d == b) {
            sameBBetter ++;
        }
        else if (c==a && d < b) {
            sameAWorse ++;
        }
        else if (c<a && d == b) {
            sameBWorse ++;
        }
        else if (c<a) {
            //cout << "asasdf " << c << " " << d << '\n';
            slope1.push_back(mF(d-b, c-a));
        }
        else if (c>a) {
            slope2.push_back(mF(d-b, c-a));
        }
    }

    sort(slope1.begin(), slope1.end());
    sort(slope2.begin(), slope2.end());

    /*
    for (int i=0; i< slope1.size(); i++) {
        //cout << slope1[i] << " ";
    }
    //cout << " twas \n";
    for (int i=0; i< slope2.size(); i++) {
        //cout << slope2[i] << " ";
    }
    //cout << "twas \n";
    */

    int maxBetterThan = slopesMax(slope1, slope2);

    int minBetterThan = slope1.size() + slope2.size() - slopesMax(slope2, slope1);

    //cout << maxBetterThan << " " << minBetterThan << '\n';

    cout << min( (int)(better + sameABetter + slope1.size()),
            min((int)(better + sameBBetter + slope2.size()),
                better + sameABetter + sameBBetter + minBetterThan)) + 1
        << " "
        << max (better+ sameABetter + sameBBetter + same + maxBetterThan,
            max (
    (int)(better + sameABetter + slope1.size() +sameBBetter + sameBWorse + same),
(int)(better + sameABetter + slope2.size() +sameBBetter + sameAWorse + same))) + 1
        << '\n';

}
