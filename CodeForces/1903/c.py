t = int(input())
for _ in range(t):
    n, = map(int,input().split())
    A = [int(s) for s in input().split()]

    tot = 0

    running = A[-1]
    for i in range(n-2, -1, -1):
        if (running > 0):
            tot += running

        running += A[i]

    tot += running

    print(tot)



