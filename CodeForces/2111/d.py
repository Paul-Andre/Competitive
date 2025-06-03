t = int(input())
for _ in range(t):
    n,m = map(int,input().split())
    A = [int(a) for a in input().split()]
    A.sort()

    tot = 0
    for i in range(n):
        ii = i//2
        c1 = A[ii]
        c2 = A[-1-ii]
        if (i%2) :
            c1,c2 = c2,c1
        print(c1,c2,c1,c2,c1,c2)









