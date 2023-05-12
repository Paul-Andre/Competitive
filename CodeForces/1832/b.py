t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    s = 0
    for i in range(n-k):
        s += a[i]

    best = s
    i = 0
    j = n-k;
    for _ in range(k):
        s += a[j] - a[i] - a[i+1]
        j+=1
        i+=2
        best = max(s,best)
    print(best)
