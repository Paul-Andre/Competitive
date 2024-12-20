import sys
t = int(input())
for _ in range(t):
    n,x,y = map(int, input().split())
    x-=1
    y-=1
    A = [-1 for _ in range(n)]
    for i in range(len(A)):
        cons = [A[(i-1)%n], A[(i+1)%n]]
        if i==x:
            cons.append(A[y])
        if i==y:
            cons.append(A[x])

        choose = 3
        if all(c != 0 for c in cons):
            choose = 0
        elif all(c != 1 for c in cons):
            choose = 1
        elif all(c != 2 for c in cons):
            choose = 2
        A[i] = choose

    # for i in range(len(A)):
    #     cons = [A[(i-1)%n], A[(i+1)%n]]
    #     if i==x:
    #         cons.append(A[y])
    #     if i==y:
    #         cons.append(A[x])

    #     choose = 3
    #     if all(c != 0 for c in cons):
    #         choose = 0
    #     elif all(c != 1 for c in cons):
    #         choose = 1
    #     elif all(c != 2 for c in cons):
    #         choose = 2

    #     if A[i] != choose:
    #         print("WRONG", file=sys.stderr)


    print(" ".join(map(str, A)))

