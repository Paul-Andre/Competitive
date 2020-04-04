#include <bits/stdc++.h>
using namespace std;

int N, K;

int have[50][50];

void checkValid() {
  for (int i=0; i<N; i++) {
    int found[51] = {};
    for (int j=0; j<N; j++) {
      found[have[i][j]] ++;
    }
    for (int j=1; j<=N; j++) {
      if (found[j] != 1) {
        cerr << "N K: " << N << " " << K << endl;
        cerr << "FAILLLLLLL\n";
        cerr << j << " "<< found[j] << endl;
        exit(1);
      }
    }
  }
  for (int i=0; i<N; i++) {
    int found[51] = {};
    for (int j=0; j<N; j++) {
      found[have[j][i]] ++;
    }
    for (int j=1; j<=N; j++) {
      if (found[j] != 1) {
        cerr << "N K: " << N << " " << K << endl;
        cerr << "FAILLLLLLL\n";
        cerr << j << " " << found[j] << endl;
        exit(1);
      }
    }
  }
  int trace =0;
  for (int i=0; i<N ; i++) {
    trace+=have[i][i];
  }
  if (trace != K) {
        cerr << "N K: " << N << " " << K << endl;
        cerr << "TRACE FAILLLLLLL\n";
        exit(1);
  }
}

void solveAB(int a, int b) {
  // a .. a b b
  // 1 .. 1 2 2
  //

  memset(have, 0, sizeof(have));
  
  for (int i=0; i<N-3; i++) {
    for (int j=0; j<N; j++) {
      have[i][j] = (j - i + N) % N + 1;
    }
  }
  have[N-3][0] = 2;
  for (int i=1; i<N-3; i++) {
    have[N-3][i] = i + 3;
  }
  have[N-3][N-3] = 1;
  have[N-3][N-2] = N;
  have[N-3][N-1] = 3;



  
    have[N-2][0] = 3;
    have[N-1][0] = 4;

    for (int i=1; i<N-3; i++) {
      if (i%2 == 1) {
        have[N-2][i] = i + 4;
        have[N-1][i] = i + 2;
      } else {
        have[N-2][i] = i + 2;
        have[N-1][i] = i + 4;
      }
    }
    if (N%2 == 0) {
      have[N-2][N-3] = N;
      have[N-1][N-3] = N-1;
    } else {
      have[N-2][N-3] = N-1;
      have[N-1][N-3] = N;
    }

    have[N-2][N-2] = 2;
    have[N-2][N-1] = 1;
    have[N-1][N-2] = 1;
    have[N-1][N-1] = 2;

    /*
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        cerr << have[i][j] << " ";
      }
      cerr << endl;
    }
    */


    int line[51];
    line[0] = a;
    line[1] = b;
    {
      int i = 2;
      int v = 1;
      while(i<N) {
        while(! (v!=a && v!=b) ){
          v ++;
        }
        line[i] = v;
        i++;
        v++;
      }
    }
    for(int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        have[i][j] = line[have[i][j]-1];
      }
    }
    cout << "POSSIBLE\n";
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        cout << have[i][j] << " ";
      }
      cout << endl;
    }
    checkValid();
    return;
}



void solve() {
  memset(have, 0, sizeof(have));

  if (N == 2) {
    if (K == 2) {
      cout << "POSSIBLE\n1 2\n2 1\n";
    } else if (K == 4) {
      cout << "POSSIBLE\n2 1\n1 2\n";
    } else {
      cout << "IMPOSSIBLE" <<endl;
    }
    return;
  } else if (N == 3) {
    if (K == 3) {
      cout << "POSSIBLE\n1 2 3\n3 1 2\n2 3 1\n";
    } else if (K == 6) {
      cout << "POSSIBLE\n2 3 1\n1 2 3\n3 1 2\n";
    } else if (K == 9) {
      cout << "POSSIBLE\n3 1 2\n2 3 1\n1 2 3\n";
    } else {
      cout << "IMPOSSIBLE" <<endl;
    }
    return;
  }

  if (K == N+1 || K == N*N-1 ) {
    cout << "IMPOSSIBLE" <<endl;
    return;
  }


  int a, b, c;
  if (K % N == 0) {
    cout << "POSSIBLE\n";
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        cout << (i-j +(K/N) - 1 + N)%N+1 << " ";
      }
      cout << endl;
    }
    return;
  } else if (K % N != 1 && K % N != N - 1) {
    // aa .. aa bb .. bb
    int aa = K/N;
    int bb = K/N + 1;
    int numA = N - K%N;
    int numB = K%N;

    if (numA == 2) {
      solveAB(bb, aa);
      return;
    } else if (numB == 2) {
      solveAB(aa, bb);
      return;
    }

    if (numB-2 <= N-bb) {
      a = bb;
      b = bb + numB-2;
      c = aa;
      //cerr << ":A\n";
    } else if (numA <= bb) {
      a = bb - numA + 1;
      b= bb - 1;
      c = bb;
      //cerr << ":B\n";
    } else {
      assert(false);
    }
  } else if (K == N*2 - 1) {
    a = N - 1;
    b = 2;
    c = 1;
      //cerr << ":C\n";
  } else if (K == N*N - N + 1) {
    a = 2;
    b = N-1;
    c = N;
      //cerr << ":D\n";
  } else if (K % N == 1) {
    a = K/N + 2;
    b = K/N - 1;
    c = K/N;
      //cerr << ":E\n";
  } else if (K % N == N - 1) {
    a = K/N - 1;
    b = K/N + 2;
    c = K/N + 1;
      //cerr << ":F\n";
  } else {
    assert(false);
  }
  int line[50];
  line[0] = a;
  line[1] = c;
  line[2] = b;
  {
    int i = 3;
    int v = 1;
    while(i<N) {
      while(! (v!=a && v!=b && v!=c) ){
        v ++;
      }
      line[i] = v;
      i++;
      v++;
    }
  }
  for (int i=0; i<N; i++) {
    have[0][i] = line[i];
  }
  for (int i=0; i<N; i++) {
    have[1][i] = line[(i+1)%N];
  }
  for (int i=2; i<N; i++) {
    for (int j=0; j<N; j++) {
      int offset = 1 - i;
      have[i][j] = line[(j+offset+N)%N];
    }
  }
  cout << "POSSIBLE\n";
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cout << have[i][j] << " ";
    }
    cout << endl;
  }
  checkValid();
  return;
}



int main() {
  /*
  for (int i=3; i<=50; i++) {
    for (int j=i+1; j<=i*i-2; j++) {
      N = i;
      K = j;
      cerr << i << " " << j << endl;
      solve();
    }
  }
  return 0;
  */
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cout << "Case #" << i << ":  ";
    cin >> N >> K;
    solve();
  }
}

