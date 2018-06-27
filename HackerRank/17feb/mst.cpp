#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        ll n;
        ll m;
        ll s;
        cin >> n >> m >> s;
		if (m <= ((n-1)*(n-2))/2+1) {
			ll result = s-n+1+m;
			cout << result << '\n';
			continue;
		}
		ll np = n-1;
		ll k = m - ((n-1)*(n-2))/2;
		ll c = s - np + 1;
		//cout << "c k " << c << " " << k << '\n';
		if (2*k<=np) {
			ll result = ((n-1)*(n-2))/2 + k*c;
			cout << result << '\n';
			continue;
		}
		else {
			ll div = s/np;
			ll mod = s%np;
			//cout << "div mod " << div << " " << mod << '\n';
			c = div+mod;
			ll min = 0;
			ll chan = 0;
			ll chanchan = 0;
			if (mod!=0){
				chanchan = -(mod-1)*k + np*(mod-1) - ((mod-1)*(mod))/2;
			}

			/*
			for (int i=1; i<mod; i++) {
				chan-=k;
				chan+=np-i;
				if (chan<min) {
					min = chan;
				}
			}
			*/
			if (chanchan>0) chanchan = 0;
			ll result = ((n-1)*(n-2))/2*div +c*k + chanchan;
			//cout << "min chan chanchan " << min << " " << chan << " " << chanchan << '\n';
			cout << result << '\n';
			continue;
		}
    }
    return 0;
}

