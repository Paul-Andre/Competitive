t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    A = list(map(int, input().split()))
    cum = 0
    tot = 0
    for a in A:
        if a == 1:
            tot+=(cum+1)//(k+1)
            cum = 0
        else:
            cum+=1

    tot+=(cum+1)//(k+1)
    cum = 0

    print(tot)




