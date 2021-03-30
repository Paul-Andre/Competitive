from collections import defaultdict
n =int(input())
G = defaultdict(set)
for _ in range(n):
    a = input().split()
    x = a[0]
    for y in a[1:]:
        G[x].add(y)
        G[y].add(x)


src, dst = input().split()

vis = set()
def trav(i, ret):
    if i in vis:
        return False
    if (i == dst):
        ret.append(dst)
        return True
    vis.add(i)
    ret.append(i)
    for j in G[i]:
        if trav(j, ret):
            return ret
    ret.pop()
    vis.remove(i)


ret = []
if(trav(src, ret)):
    print(" ".join(ret))
else:
    print("no route found")

