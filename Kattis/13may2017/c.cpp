#include <bits/stdc++.h>
using namespace std;

// This is probably stupid as well

typedef complex<double> comp;

typedef vector<comp>  vc;
typedef vector<vector<comp> > vvc;
comp temp[2048];

void fft(vector<comp> &a, comp w, int n, int offset, int jump) {
    //cout << n << '\n';
    if (n == 1) {
        return ;
    }
    else {
        fft(a, w*w, n/2, offset, jump*2);
        fft(a, w*w, n/2, offset+jump, jump*2);
        comp x = 1;
        for (int j=0; j<n/2; j++) {
            comp u = a[offset + j*jump*2] + x*a[offset + jump + j*jump*2];
            comp v = a[offset + j*jump*2] - x*a[offset + jump + j*jump*2];
            temp[j] = u;
            temp[j+n/2] = v;
            x*=w;
        }

        for (int i=0; i<n; i++) {
            a[offset + i*jump] = temp[i];
        }
    }
}


void trans(vector<vector<comp> > &a) {
    for (int i=0; i<a.size(); i++) {
        for (int j=i; i<a.size(); i++) {
            comp tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }
}

void fft2d(vector<vector<comp> > &a) {
    int n = a.size();
    comp w(cos(2*M_PI/n), sin(2*M_PI/n));

    cout << "  fft columns\n";
    for (int i=0; i<n; i++) {
        //cout << i << '\n';
        fft(a[i], w, n, 0, 1);
    }

    cout << "  trans\n";
    trans(a);

    cout << "  fft rows\n";
    for (int i=0; i<n; i++) {
        fft(a[i], w, n, 0, 1);
    }

    cout << "  trans\n";
    trans(a);
}

void fftinv2d(vector<vector<comp> > &a) {
    int n = a.size();
    comp w(cos(-2*M_PI/n), sin(-2*M_PI/n));

    cout << "  inv fft columns\n";
    for (int i=0; i<n; i++) {
        //cout << i << '\n';
        fft(a[i], w, n, 0, 1);
    }

    cout << "  inv trans\n";
    trans(a);

    cout << "  inv fft rows\n";
    for (int i=0; i<n; i++) {
        fft(a[i], w, n, 0, 1);
    }

    cout << "  inv trans\n";
    trans(a);
}

void convolve(vvc &a, vvc &b) {
    cout << "doing fft a\n";
    fft2d(a);
    cout << "doing fft b\n";
    fft2d(b);
    cout << "doing mult";
    for (int i=0; i<2048; i++) {
        for (int j=0; j<2048; j++) {
            a[i][j] *= b[i][j];
        }
    }
    cout << "doing inv\n";
    fftinv2d(a);
}

int main() {
    int hp, wp, hm, wm;
    cin >> hp >> wp >> hm >> wm;
    vvc p(2048,vector<comp>(2048,0));
    vvc m(2048,vector<comp>(2048,0));

    vvc pf(2048,vector<comp>(2048,1));
    vvc mf(2048,vector<comp>(2048,1));
    for (int i=0; i<hp; i++) {
        for (int j=0; j<wp; j++) {
            char x;
            cin >> x;
            p[2048-1-i][2048-1-j] = comp(int(x=='x'));
            pf[2048-1-i][2048-1-j] = comp(int(x!='x'));
        }
    }
    for (int i=0; i<hm; i++) {
        for (int j=0; j<wm; j++) {
            char x;
            cin >> x;
            m[i][j] = comp(int(x=='x'));
            mf[i][j] = comp(int(x!='x'));
        }
    }

    convolve(m, p);

    for (int i=0; i<hm; i++) {
        for (int j=0; j<wm; j++) {
            cout << m[i][j] << " " ;
        } 
        cout << '\n';
    }
    
}

