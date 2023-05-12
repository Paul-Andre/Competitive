t = int(input())
for _ in range(t):
    n = int( input())
    a = list(map(int, input().split()))
    n = len(a)
    aa = [a[0]]
    prev = a[0]
    i = 1;
    while (i<n):
        b = a[i];
        if b == prev:
            pass
        else:
            aa.append(b)
            prev = b
        i+=1

    a = aa
    n = len(a)

    s = n;

    if n == 1:
        print(1)
        continue
    if n == 2:
        print(2)
        continue

    x = a[0]
    y = a[1]
    i = 2
    while(i < n):
        f = a[i]
        assert (y != x)
        if y>x:
            if f >= y:
                y = f;
                s-=1
            else:
                x = y
                y = f;
        elif y<x:
            if f <= y:
                y = f;
                s-=1
            else:
                x = y
                y = f;
        i+=1
    print(s)

