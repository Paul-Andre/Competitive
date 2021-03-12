import heapq
n,m=map(int,input().split())
places = [tuple(map(int, input().split())) for _ in range(n)]
G=[[] for _ in range(n)]
for _ in range(m):
    a,b,movement = input().split()
    a = int(a)
    b = int(b)
    af,ax,ay = places[a]
    bf,bx,by = places[b]
    if movement == "walking" or movement == "stairs":
        dist = ((ax-bx)**2 + (ay-by)**2 + ((af-bf)*5)**2)**.5
        G[a].append((b,dist))
        G[b].append((a,dist))
    if movement == "lift":
        G[a].append((b,1))
        G[b].append((a,1))
    if movement == "escalator":
        dist = ((ax-bx)**2 + (ay-by)**2 + ((af-bf)*5)**2)**.5
        G[a].append((b,1))
        G[b].append((a,dist*3))

#for i,g in enumerate(G):
#    print(i,":", g)

q = int(input())
for _ in range(q):
    a,b = map(int,input().split())

    vis=[False for _ in range(n)]
    prev = [None for _ in range(n)]
    q = [(0,a, -1)]

    while(len(q)):
        size, x, pp = heapq.heappop(q)
        if vis[x]: continue
        vis[x] = True
        prev[x] = pp
        if (x == b):
            break;
        for y, dist in G[x]:
            heapq.heappush(q,(size + dist, y, x))

    #print(prev)
    #print(vis)
    wew = []
    wew.append(b)
    bb = b
    while(bb != a):
        bb = prev[bb]
        wew.append(bb)
    print(" ".join(map(str,reversed(wew))))






