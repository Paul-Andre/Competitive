t = int(input())
for _ in range(t):
    n, m = map(int,input().split())
    A = [tuple(sorted(map(int, input().split()))) for _ in range(m)]
    A.sort()
    l = n
    i = m-1
    min_r = n+1
    tot = 0
    while l> 0:
        while (i >= 0) and A[i][0]==l:
            min_r = min(min_r, A[i][1])
            i-=1
        tot+=min_r-l
        l-=1
    print(tot)

