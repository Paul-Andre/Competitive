for _ in range(int(input())):
    n,m = map(int, input().split())
    good = False
    # n<=m
    if m<n:
        n,m=m,n
    if n>=2 and m>=3:
        print("YES")
    else:
        print("NO")


