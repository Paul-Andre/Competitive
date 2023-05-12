t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    s = sum(a)
    i = 0
    j = len(a)-1
    for _ in range(k):
        l = a[i]+a[i+1]
        r = a[j]
        if l < r:
            s-=l
            i+=2
        else:
            s-=r
            j-=1
    print(s)
