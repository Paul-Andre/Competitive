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
        if (sp.size > op.size):
            op.parent = sp
        elif (op.size > sp.size):
            sp.parent = op
        else:
            sp.parent = op
            op.size+=sp.size
        return True


def unlikeliness(a,b):
    (ax,ay), (bx,by) = a,b
    return ((ax-bx)**2 + (ay-by)**2)**.5

t = int(input())
for ttt in range(t):
    if (ttt!=0):
        print()
    input()
    (n,) = map(int, input().split())
    A = [tuple(map(float, input().split())) for _ in range(n)]

    sets = [Stuff() for _ in range(n)]

    edges = []
    for i,a in enumerate(A):
        for j,b in enumerate(A):
            if j<i:
                u = unlikeliness(a,b)
                edges.append((u,i,j))

    edges.sort()

    tot_unl = 0

    for (u,x,y) in edges:
        if (sets[x].union(sets[y])):
                tot_unl+=u

    print("{:0.2f}".format(tot_unl))


