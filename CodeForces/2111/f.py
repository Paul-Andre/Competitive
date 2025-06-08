import math
t = int(input())
for _ in range(t):
    p,s = map(int,input().split())
    g = math.gcd(p,s)
    p = p//g
    s = s//g

    if p%2 != 0:
        p*=2
        s*=2

    for i in range(1,50000):
        pp = p*i
        ss = s*i

        if (ss > 50000):
            print(-1)
            break;

        min_s = pp//2-1

        if (ss < min_s) :
            print(-1)
            break

        w = min_s//2 + 1
        h = min_s//2 + min_s%2

        max_s = w*h
        if (ss > max_s):
            continue

        print(ss)

        rem = ss
        for i in range(w):
            print(0, i)
            ss-=1

        for j in range(1,h):
            print(j, 0)
            ss-=1

        for j in range(1,h):
            if ss==0:break;
            for i in range(1,w):
                if ss==0:break;
                print(j,i)
                ss-=1

        break;





