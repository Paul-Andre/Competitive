t=int(input())
for _ in range(t):
    n=int(input())
    gears = [tuple(map(int, input().split())) for _ in range(n)]
    tops = [b**2/(4*a) + c for (a,b,c) in gears]
    a = 0
    for i in range(n):
        if tops[i] > tops[a]:
            a = i
    print(a+1)


