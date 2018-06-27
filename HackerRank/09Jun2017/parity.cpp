#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 7340033

ll T[2][150001]; // Number of odd

ll factorial(ll n) {
    ll tot = 1;
    for (ll i=1; i<=n; i++) {
        tot *= i;
        tot %= MOD;
    }
    return tot;
}



ll exp(ll base, ll exp) {
    ll ac = 1;
    while(exp != 0) {
        if ( exp%2==0) {
            base = base*base;
            base %= MOD;
            exp /= 2;
        }
        else {
            ac *= base;
            ac %= MOD;
            exp --;
        }
    }
    /*
    ac += MOD;
    ac %= MOD;
    */
    return ac;
}


ll inv(ll a) {
    //cerr << "inverseing " << a << '\n';
    return exp(a, MOD-2);
}

ll facts[150001];

ll multipliers[150001];

int parityParty(int n, int a, int b, int c) {

    int k = a  + b + c;

    { 
        ll fact = 1;
        ll fact2 = 1;

        for(int i=0; i<=a+c; i++) {
            if ( i>= a) {
                facts[i] = (fact*fact2) % MOD;
                fact2 *= (c-i+a);
                fact2 %= MOD;
                fact2 *= inv(i-a+1);
                fact2 %= MOD;
            }
            fact *= inv(k-i);
            fact %= MOD;
            fact *= (i+1);
            fact %= MOD;
        }
    }

    if (false) {

    }
    else {
        // Prepare to use Eigenwhatever

        for (int i=0; i<=k; i++) {
            ll n = -(-k + i*2);
            cerr << "Eigenvector for " << -n << ": ";

            vector<ll> side(k+1);

            ll prevRight = inv(n);

            side[0] = prevRight;

            for(int i=1; i<k; i++) {
                ll left = k-i+1;
                ll center = n;
                ll right = i+1;
                //cerr << "left right " << left << " " << right << endl;

                center -= (prevRight * left) % MOD;
                center %= MOD;

                right *= inv(center);
                right %= MOD;

                side[i] = right;
                prevRight = right;
            }

            multipliers[i] += (facts[k] * 1) % MOD;
            multipliers[i] %= MOD;
                cerr << 1 << " ";


            ll tot = side[k-1];
            multipliers[i] += (facts[k-1] * - tot) % MOD;
            multipliers[i] %= MOD;
                cerr << tot << " ";

            for(int j=k-2; j>=0; j--) {
                tot *= -(side[j]);
                tot %= MOD;

                cerr << tot << " ";

                multipliers[i] += (facts[k] * - tot) % MOD;
                multipliers[i] %= MOD;
            }
        cerr << endl;
        }
    }

    T[0][0] = 1;

    for (int i=1; i<=n; i++) {
        T[i%2][0] = T[(i-1)%2][1];
        T[i%2][k] = T[(i-1)%2][k-1];
        for (int j=1; j<k; j++) {
            //T[i%2][j] = (T[(i-1)%2][j+1] +T[(i-1)%2][j-1]) % MOD;
            T[i%2][j] = ((j+1)*T[(i-1)%2][j+1] +  (k-j+1)*T[(i-1)%2][j-1]) % MOD;
        }
    }

    ll tot = 0;

    for(int i=a; i<=a+c; i++) {
        tot += (facts[i]*T[n%2][i]) % MOD;
        tot %= MOD;
    }

    //cerr << tot <<endl;
    return (tot + MOD) % MOD;


                









    
    
    /*
    for (int i=0; i<=k; i++) {
        cerr << T[n%2][i] << " ";
    }
    cerr << endl;

     {  

        ll fact = 1;
         for (int i=0; i<=k; i++) {
             cerr << (fact*T[n%2][i])%MOD << " ";
        fact *= inv(k-i);
        fact %= MOD;
        fact *= (i+1);
        fact %= MOD;
         }
         cerr << endl;
     }
     */

}

int main() {

    int n;
    int a;
    int b;
    int c;
    cin >> n >> a >> b >> c;
    int result = parityParty(n, a, b, c);
    cout << result << endl;
    return 0;
}

