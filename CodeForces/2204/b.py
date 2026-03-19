t = int(input())
for _ in range(t):
    n = int(input())
    s = list(map(int,input().split()))
    tot = 0
    m = 0
    for c in s:
        if c >= m:
            tot+=1
            m = c

    print(tot);


