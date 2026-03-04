t = int(input())
for _ in range(t):
    n = int(input())
    P = list(map(int, input().split()))
    j = None
    for i,p in enumerate(P):
        if p == n:
            j = i
            break;
    P[j], P[0] = P[0], P[j];
    print(" ".join(str(p) for p in P))

