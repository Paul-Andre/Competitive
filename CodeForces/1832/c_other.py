t = int(input())
for _ in range(t):
    n = int( input())
    a = list(map(int, input().split()))
    n = len(a)

    s = n;

    if n == 1:
        print(1)
        continue

    x = a[0]
    y = None
    i = 1
    while(i < n):
        f = a[i]
        if y is None:
            if f == x:
                s-=1
            else:
                y = f;
        else:
            assert (y != x)
            if y>x:
                if f >= y:
                    y = f;
                    s-=1
                else:
                    x = y
                    y = f;
            if y<x:
                if f <= y:
                    y = f;
                    s-=1
                else:
                    x = y
                    y = f;
        i+=1
    print(s)

