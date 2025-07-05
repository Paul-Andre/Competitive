t = int(input())
for _ in range(t):
    a,b,x,y = map(int,input().split())
    if (b<a and b == a^1):
        print(y)
    elif b<a:
        print(-1)
    else:
        best = (b-a)*x
        a0 = a & 1
        b0 = b & 1
        if a0 == b0:
            best = min(best, (b-a)//2 * (x+y))
        elif a0 == 1 and b0 == 0:
            best = min(best, (b-a)//2 * (x+y) + x)
        elif a0 == 0 and b0 == 1:
            best = min(best, (b-a)//2 * (x+y) + y)
        else:
            assert(False)
        print(best)

            




