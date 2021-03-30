n,m = map(int, input().split())
A = [int(input()) for _ in range(n)]
G = [[] for _ in range(n)]
vis = [False for _ in range(n)]
for _ in range(m):
    x,y = map(int,input().split())
    G[x].append(y)
    G[y].append(x)

currentTot = 0
stack= []
def trav(i):
    global currentTot
    if vis[i]: return
    currentTot+=A[i]
    vis[i] = True
    for j in G[i]:
        if not vis[j]:
            stack.append(j)

good = True
for i in range(n):
    if not vis[i]:
        currentTot = 0
        stack = [i]
        while(len(stack)):
            trav(stack.pop())
        if currentTot!=0:
            good = False
if (good):
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")


