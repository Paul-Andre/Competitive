t = int(input())
for _ in range(t):
    n,x = map(int,input().split())
    A = list(map(int, input().split()))
    A.append(0)
    A.sort()
    diffs = []
    for i in range(len(A)-1):
        diffs.append(A[i+1]-A[i])

    diffs.append(2*(x-A[-1]))
    print(max(diffs))


