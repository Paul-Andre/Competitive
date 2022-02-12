t=int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(a)
    b.sort()
    if(a==b):
        print("NO")
    else:
        print("YES")
