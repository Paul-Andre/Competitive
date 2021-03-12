import heapq
while(True):
    try:
        n,m=map(int,input().split())
    except EOFError:
        break
    if n==0: break;

    g = [[] for _ in range(n)]
    for _ in range(m):
        i = input().split()
        x = int(i[0])
        y = int(i[1])
        z = float(i[2])
        g[x].append((y,z))
        g[y].append((x,z))

    vis=[False for _ in range(n)]
    q = [(-1,0)]
    ans = None
    while(len(q)):
        size, x = heapq.heappop(q)
        if vis[x]: continue
        vis[x] = True
        if (x == n-1):
            ans = -size
            break;
        for y, fact in g[x]:
            heapq.heappush(q,(size*fact, y))
    print("{:.4f}".format(ans))





