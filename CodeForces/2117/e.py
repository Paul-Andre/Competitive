import sys
from collections import Counter
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

t = int(input())
for _ in range(t):
    n, = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    n = len(A)
    assert(len(A) == len(B))

    AA = []
    BB = []
    for i,(a,b) in enumerate(zip(A,B)):
        if (i%2):
            a,b= b,a
        AA.append(a)
        BB.append(b)
    
    A,B = AA,BB
    #eprint(A,B)

    best = 0

    cA = set()
    cB = set()
    for i in range(n-1, -1, -1):
        cA.add(A[i])
        cB.add(B[i])
        if A[i] in cB or B[i] in cA:
            best = max(best, i+1)

    cA = set()
    cB = set()
    for i in range(n-3, -1, -1):
        cA.add(A[i+2])
        cB.add(B[i+2])
        if A[i] in cA or B[i] in cB:
            best = max(best, i+1)

    print(best)




      


    
