t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    casinos = [tuple(map(int, input().split())) for _ in range(n)]
    casinos.sort()

    current = k
    
    for (l,r,real) in casinos:
        if (l <= current <=r):
            current = max(current, real)

    print(current)

        






