# 1454A

t = int(input())
for _ in range(t):
    n,k = map(int,input().split())
    A = [int(s) for s in input().split()]
    if sorted(A) == A:
        print("YES")
    elif k >= 2:
        print("YES")
    else:
        print("NO")
