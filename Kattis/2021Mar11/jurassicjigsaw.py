import heapq

def unlikeliness(a,b):
    return sum(aa != bb for  aa,bb in zip(a,b))

n,k = map(int, input().split())
A = [input() for _ in range(n)]
vis = [False for _ in range(n)]

unl = [[unlikeliness(a, b) for j,b in enumerate(A) if j<i] for i,a in enumerate(A)]

def get_unl(i,j):
    if (i==j): return 0
    if (j<i): return unl[i][j]
    return unl[j][i]


tot_unl = 0
ans = []
q =[]
vis[0] = True
for j in range(n):
    if not vis[j]:
        heapq.heappush(q, (get_unl(0,j), 0, j))

while(len(q)):
    dist,x,y = heapq.heappop(q)
    if not vis[y]:
        vis[y]=True
        tot_unl += dist
        ans.append((x,y))

        for j in range(n):
            if not vis[j]:
                heapq.heappush(q, (get_unl(y,j), y, j))

print(tot_unl)
for i,j in ans:
    print(i,j)


