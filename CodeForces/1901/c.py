t = int(input())
for _ in range(t):
    (n,) = map(int,input().split())
    A = list(map(int, input().split()))

    x = max(A)
    y = min(A)

    for i in range(0, 64):
        xtop = x>>i;
        ytop = y>>i;

        xbot = x % (1<<i)
        ybot = y % (1<<i)
        if (xtop == ytop):
            turns = i
            change = 0
            break;
        if (xtop == ytop+1 and xbot < ybot):
            turns = i
            change = (1<<i)-ybot
            break;

    print(turns)
    if (turns<=n and turns>=1):
        print(" ".join(map(str,[change]+[0]*(turns-1))))
    


