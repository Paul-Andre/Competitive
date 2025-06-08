import sys
from collections import Counter
def eprint(*args, **kwargs):
    #print(*args, file=sys.stderr, **kwargs)
    pass

t = int(input())
for _ in range(t):
    n, = map(int, input().split())
    G = [[] for _ in range(n+1)]
    for _ in range(n-1):
        x,y = map(int,input().split())
        G[x].append(y)
        G[y].append(x)
    rooted = [[] for _ in range(n+1)]
    vis = [False for _ in range(n+1)]
    eprint(G)

    stack = [1]
    
    while(stack):
        i = stack.pop()
        vis[i] = True

        for v in G[i]:
            if not vis[v]:
                rooted[i].append(v)
                stack.append(v)


    vis = [False for _ in range(n+1)]

    good = True
    num_leaves = 0
    num_split = 0
    split = None
    eprint(rooted)
    for A in rooted[1:]:

        num_leaves += (len(A) == 0)

        if (len(A) > 2):
            good = False
        if (len(A) == 2):
            num_split+=1
            split = A

    if (num_split > 1): good = False;

    if (not good):
        print(0)
        continue

    def get_len(i):
        l = 1
        A = rooted[i]
        while(A):
            assert(len(A) <= 1)
            l+=1
            A = rooted[A[0]]
        return l


    MOD = 10**9 + 7
    if (num_split == 0):
        print(pow(2,n,MOD))
    else:
        l1 = get_len(split[0])
        l2 = get_len(split[1])
        rem = n-l1-l2
        diff = abs(l1-l2)
        eprint("n,l1,l2,rem,diff:", n,l1,l2,rem,diff)
        if (l1 == l2):
            print((pow(2,rem, MOD)*2)%MOD)
        else:
            print((pow(2,rem+diff-1, MOD)*3)%MOD)
















      


    
