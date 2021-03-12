from collections import defaultdict

n = int(input())
stuff = {input() for _ in range(n)}
m = int(input())
G = defaultdict(list)
for _ in range(m):
    x,y = input().split()
    G[x].append(y)
    G[y].append(x)

walter = set()
jesse = set()

vis = set()

def traverse(x, w, queue):
    if x in vis:
        if x in walter and not w:
            return False
        if x in jesse and w:
            return False
        return True
    else:
        vis.add(x)
        if w:
            walter.add(x)
        else:
            jesse.add(x)
        for y in G[x]:
            queue.append((y, not w))
        return True

good = True
for st in stuff:
    if st not in vis:
        queue =  [(st, True)]
        while(len(queue)):
            x, w = queue.pop()
            if not traverse(x,w,queue):
                good = False


if not good:
    print("impossible")
else:
    print(" ".join(walter))
    print(" ".join(jesse))



