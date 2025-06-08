t = int(input())
for _ in range(t):
    n,x = map(int, input().split())
    A = list(map(int, input().split()))
    l = -1
    r = -1
    for i,a in enumerate(A):
        if (a == 1):
            if (l == -1):
                l = i
            r = i

    if x>= r-l+1:
        print("YES")
    else:
        print("NO")


