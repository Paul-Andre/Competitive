t = int(input())
for _ in range(t):
    n, = map(int,input().split())
    M = [[int(s) for s in input().split()] for _ in range(n)]

    A = []
    for i in range(0, n):
        acc = 2**30 - 1
        for j in range(0, n):
            if j!=i:
                acc &= M[i][j]
        A.append(acc)

    good = True
    for i in range(0,n):
        for j in range(0,n):
            if i==j:
                continue
            if A[i]|A[j] != M[i][j]:
                good = False


    if good:
        print("YES")
        print(" ".join(map(str, A)))
    else:
        print("NO")







