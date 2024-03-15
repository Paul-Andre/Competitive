import math
t = int(input())

def make_s(off, n):
    p2 = list(range(off, off + n//2+n%2 ))
    p1 = list(range(off + n//2+n%2 , off+n))
    return p1+p2



for _ in range(t):
    n,k = map(int,input().split())
    q = n//k + (n%k != 0)
    A = [];
    r = 0;
    while(r<n):
        kk = min(k, (n)-len(A));
        A = A + make_s(r+1, kk);
        r+=k;

    print(" ".join(map(str, A)));
    print(q)
    C = [i//k+1 for i in range(n)];
    print(" ".join(map(str, C)));


