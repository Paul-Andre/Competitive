# 1454A

t = int(input())
for _ in range(t):
    n = int(input())
    print(" ".join(map(str,([ i for i in range(2,n+1)] + [1]))))
