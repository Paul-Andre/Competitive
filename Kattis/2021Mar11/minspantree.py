import heapq

class Stuff:
    def __init__(self):
        self.parent = None
        self.size =1

    def find(self):
        if self.parent is None:
            return self
        else:
            pp = self.parent.find()
            self.parent = pp
            return pp
    def union(self, other):
        sp = self.find()
        op = other.find()
        if sp==op:
            return False
        sp.parent = op
        op.size+=sp.size
        return True


while(True):
    n,m = map(int, input().split())
    if (n==0): break;
    sets = [Stuff() for _ in range(n)]

    edges = []
    for _ in range(m):
        u,v,w = map(int,input().split());
        edges.append((w, u, v))

    edges.sort()

    tot_unl = 0
    ans = []

    for (u,x,y) in edges:
        if (sets[x].union(sets[y])):
                tot_unl+=u
                ans.append((min(x,y), max(x,y)))

    if (len(ans) == n-1):
        ans.sort()
        print(tot_unl)
        for i,j in ans:
            print(i,j)
    else:
        print("Impossible")


