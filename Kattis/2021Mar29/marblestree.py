while(True):
    n = int(input())
    if (n==0): break;
    tree = [[] for _ in range(n+1)]
    M = [0 for _ in range(n+1)]
    vis = [False for _ in range(n+1)]

    totMove = 0

    def traverse(i, brought):
        global totMove
        vis[i]=True
        have = brought+M[i]-1
        for k in tree[i]:
            if vis[k]: continue
            have = traverse(k, have)
        totMove += abs(have-brought)
        return have

    for _ in range(n):
        a = [int(a) for a in input().split()]
        v = a[0]
        m = a[1]
        M[v] = m
        d = a[2]
        children =a[3:]
        for child in children:
            tree[child].append(v)
            tree[v].append(child)

    traverse(1, 0)
    print(totMove)


