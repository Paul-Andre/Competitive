t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(a) for a in input().strip().split()]
    n = len(A)
    a = min(A)
    b = max(A)
    aa = sum(k == a for k in A)
    bb = sum(k == b for k in A)
    if (a!=b):
        print(2*aa*bb)
    else:
        print(n*(n-1))

