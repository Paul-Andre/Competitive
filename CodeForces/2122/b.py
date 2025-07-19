for _ in range(int(input())):
    n, = map(int, input().split())
    A = [tuple(map(int,input().split())) for _ in range(n)]
    tot = 0
    for a,b,c,d in A:
        if d<b:
            # zeros moved
            tot += min(a,c)
        tot += max(0,a-c)
        tot += max(0,b-d)
    print(tot)


    


