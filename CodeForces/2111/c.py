t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(a) for a in input().split()]
    prev = None
    running = 0
    best = float("inf")
    for a in A:
        if a == prev:
            running+=1
        else:
            running = 1

        best = min(best, a*(n-running))
        prev = a
    print(best)
