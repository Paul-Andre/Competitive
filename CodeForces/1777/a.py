t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x)%2 for x in input().split()]
    cnt = 0
    prev = A[0]
    for a in A[1:]:
        if prev==a:
            cnt+=1
        prev = a

    print(cnt)
