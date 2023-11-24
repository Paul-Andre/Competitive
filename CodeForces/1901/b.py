t = int(input())
for _ in range(t):
    (n,) = map(int,input().split())
    A = list(map(int, input().split()))
    tot = A[0]-1
    for i in range(len(A)-1):
        if (A[i+1] > A[i]):
            tot+= A[i+1]-A[i]

    print(tot);


