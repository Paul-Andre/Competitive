t = int(input())
for _ in range(t):
    n,s = map(int, input().split())
    X = list(map(int,input().split()))
    x_max = max(X)
    x_min = min(X)
    a = abs(x_max-s) + x_max-x_min
    b = abs(s-x_min) + x_max-x_min
    print(min(a,b))
