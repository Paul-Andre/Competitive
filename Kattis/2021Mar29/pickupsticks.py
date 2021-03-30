from collections import defaultdict

n,m = map(int, (input().split()))
g = [[] for _ in range(n+1)]

for _ in range(m):
    a,b = map(int, input().split())
    g[a].append(b)

order = []
vis = [0]*(n+1)
stack = []
good = True
def trav(i):
    global good
    if vis[i]==2:
        return
    elif vis[i] == 1:
        good = False;
        return
    vis[i] = 1
    stack.append((add_list, i))
    for j in g[i]:
        stack.append((trav, j))

def add_list(i):
    order.append(i)
    vis[i] = 2

for i in range(1, n+1):
    stack = [(trav, i)]
    while(stack):
        f,p = stack.pop()
        f(p)

if good:
    for s in reversed(order):
        print(s)
else:
    print("IMPOSSIBLE")


