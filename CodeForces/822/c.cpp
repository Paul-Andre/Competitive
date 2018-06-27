#include <bits/stdc++.h>
using namespace std;


int n,x;

struct Vouch{
    int l,r,c,id;
    Vouch(){}
    Vouch(int ll,int rr, int cc, int idid) {
        l = ll;
        r = rr;
        c = cc;
        id = idid;
    }
};

bool sA(Vouch a, Vouch b) {
    int wa = a.r-a.l+1;
    int wb = b.r-b.l+1;
    if (wa!=wb) return wa<wb;
    return a.l<b.l;
}

bool sB(Vouch a, Vouch b) {
    int wa = a.r-a.l+1;
    int wb = b.r-b.l+1;
    if (wa!=wb) return wa>wb;
    return a.l<b.l;
}

Vouch A[200000];
Vouch B[200000];

int W(Vouch a) {
        int wa = a.r-a.l+1;
    return wa;
}

int main(){
    cin>>n>>x;

    for(int i=0; i<n; i++) {
        int l,r,c;
        cin>>l>>r>>c;
        A[i] = Vouch(l,r,c,i);
        B[i] = Vouch(l,r,c,i);
    }

    sort(A, A+n, sA);
    sort(B, B+n, sB);
    
    int i = 0;
    int j = 0;

    int oo = ((unsigned) (-1))>>1;
    int mm = ((unsigned) (-1))>>1;
    //cerr <<mm<<endl;

    int mA = A[0].c;
    int pA = A[0].r-A[0].l+1;

    while(true) {
        Vouch a = A[i];
        Vouch b = B[j];
        int wa = a.r-a.l+1;
        int wb = b.r-b.l+1;

        if (wa + wb < x) {
            i++;
        }
        else if(wa+wb>x) {
            j++;
        }
        else if (a.r>=b.l) {
            j++;
        }
        else {
            mm = min(mm, mA + b.c);
            //cerr <<mm <<endl;
            if (i==n-1) j++;
            else if (j==n-1) i++;
            else if (W(A[i+1]) != W(A[i])) j++;
            else if (W(B[j+1]) != W(B[j])) i++;
            else if (A[i+1].r<B[j].l) i++;
            else j++;
        }
        
        if (i>=n || j>=n) break;

        int npA = A[i].r-A[i].l+1;
        if (pA != npA) {
            pA = npA;
            mA = A[i].c;
        }
        else {
            mA = min(mA, A[i].c);
        }
    }

    if (mm == oo) {
        cout<<"-1\n";
    }
    else {
        cout <<mm<<endl;
    }
}




