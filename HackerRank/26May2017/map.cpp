#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull bitty[6];

ull masks[64];

ull field[(1<<(20))];



bool hasWeird;

ull countMask = ~((~(0ull))<<26);

char counts[(1<<13)];

ull mask13 = ~((~(0ull))<<13);

int countBits(int a) {
    //a &= countMask;
    int count = 0;
    while(a!=0) {
        if (a&1) {
            count ++;
        }
        a= a>>1;
    }
    return count;
}

int countBuff(int a) {
    return counts[a&mask13] + counts[(a>>13) &mask13];
}

int main() {

    //cout << "size " << sizeof(ull) << endl;
    
    /*
    std::bitset<64> y(countMask);
    std::cout << y << endl;
    */

    for (int i=0; i<1<<13; i++) {
        counts[i] = countBits(i);
    }
    

    for (int i=0; i<6; i++) {
        
        ull b= 1ull<<(1<<i);

        for (int j=0; j<i; j++) {
            b = b | (b<<(1<<j));
        }

        for (int j=i+1; j<6; j++) {
            b = b | (b<<(1<<j));
        }


        bitty[i] = b;
    }

    for (int i=0; i<64; i++) {
        masks[i] = ~(0ull);
        for (int j=0; j<6; j++) {
            if (i&(1ull<<j)) {
                masks[i] &= bitty[j];
            }
        }
    }

    int n;
    cin >> n;

    int maxx = 0;

    for (int i=0; i<n; i++) {
        ull a;
        cin >> a;

        if (a==(1ull<<26)) {
            hasWeird = true;
        }
        else {
            ull d = a/64;
            ull m = a%64;

            /*
            cout << "a " << a << endl;

            std::bitset<64> y(masks[m]);
            std::cout << y << endl;
            */

            maxx |= a;
            field[d] |= masks[m];
        }
    }

    ull bound = 1ull<<20;
    for (int i=0; i<bound; i++) {
        for (int j=0; j<20; j++) {
            int maskOn = 1<<j;
            int maskOff = ~maskOn;
            int a = i|maskOn;
            int b = i&maskOff;

            //cout << "a b \n";
            /*
            std::bitset<32> y(a);
            std::cout << y << endl;

            std::bitset<32> x(b);
            std::cout << x << endl;
            */

            field[a] |= field[b];
        }
    }

    int smallestCount = 100000;
    int smallest;

    /*
    cout << "field\n";
    std::bitset<64> y(field[(1<<20)-1]);
    std::cout << y << endl;
    */

    bound = 1ull<<26;
    for(int i=0; i<bound; i++) {
        int a = bound-1-i;
        ull d = a/64;
        ull m = a%64;

        if (!(field[d] & (1ull<<m))) {
            int count= countBuff(i);
            if ( count < smallestCount) {
                smallestCount = count;
                smallest = i;
            }
        }
    }
    
    if (hasWeird) {
        smallest |= (1<<26);
    }

    cout << smallest << endl;
}
