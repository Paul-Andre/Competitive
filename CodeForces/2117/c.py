from collections import Counter
t = int(input())
for _ in range(t):
    n, = map(int, input().split())
    A = list(map(int, input().split()))
    n = len(A)
    l = Counter(A)
    i = n-1
    hasR = set()
    tot = 0
    while(i>=0):
        a = A[i]

        l[a]-=1
        if(l[a] == 0):
            del l[a]
            if a in hasR:
                hasR.remove(a)
        else:
            hasR.add(a)

        if len(hasR) >= len(l):
            assert(len(hasR) == len(l))
            tot+=1
            hasR = set()
        i-=1


    assert(tot>=1)
    print(tot)










