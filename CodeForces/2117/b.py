t = int(input())
for _ in range(t):
    n, = map(int, input().split())

    if (n%2):
        print(" ".join(map(str,list(range(1,n+1,2))+list(range(n-1,1,-2)))))
    else:
        print(" ".join(map(str,list(range(1,n,2))+list(range(n,1,-2)))))



