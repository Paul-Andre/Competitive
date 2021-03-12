n,h,l = map(int, input().split())
queue = list(map(int,input().split()))
vis = [False for _ in range(n)]
for asdf in queue:
    vis[asdf] = True

G = [[] for _ in range(n)]
for _ in range(l):
    x,y=map(int,input().split())
    G[x].append(y)
    G[y].append(x)

position = [10000000000 for _ in range(n)]
q_i = 0
iteration = 0
while(q_i<len(queue)):
    cr = len(queue)
    while(q_i<cr):
        x = queue[q_i]
        position[x]=iteration
        q_i+=1
        for y in G[x]:
            if not vis[y]:
                queue.append(y)
                vis[y]=True
    iteration+=1

m = -10000000
mi = -1
for i,p in enumerate(position):
    if p > m:
        m = p
        mi = i
print(mi)




