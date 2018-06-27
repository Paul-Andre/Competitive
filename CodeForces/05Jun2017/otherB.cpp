#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define gc getchar_unlocked
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define vi vector<int>

using namespace std;

ll pow(ll base, ll exp)
	{
	if(exp==0)
	return 1;
	else if(exp==1)
	return base;
 
	ll root=pow(base,exp>>1);
	
	if((exp&1)==0)
	return (root*root);
	else 
	return (((root*root))*base);
	}	 

int intlog(double base, double x) {
    return (int)(log(x) / log(base));
}

int main() {
    int n,i,j,k,no=0,m;
    ll x,y,l,r;
    cin>>x>>y>>l>>r;
     n = intlog(x,r);
    k = intlog(y,r);
    ll ar[300000];
    for(i=0; i<=n; i++){
        ll p = pow(x,i);
        for(j=0; j<=k; j++){
            ll q=pow(y,j);
            if(q+p < 0 || q+p > r)
                break;
            else
                ar[no++] =  q+p;
        }
    }
    ar[no++] = r+1;
    sort(ar,ar+no);
    i=0; 
    while(i<no && ar[i] < l)
        i++;
    if(i>=no)
        {
        cout<<0;
        return 0;
    }
    ll rng=0;   
    ll max = rng = ar[i]-l;
    if(ar[i]>r){
        cout<<(r-l+1);
        return 0;
    }
    
    for(i=i+1; i<no; i++){        
       //cout<<ar[i-1]<<"  "<<ar[i]<<endl;
        
        rng = ar[i]-ar[i-1]-1;
        if(rng > max)
            max=rng;
        //cout<<rng<<endl;
    }
   cout<<max;
    return 0;
}
