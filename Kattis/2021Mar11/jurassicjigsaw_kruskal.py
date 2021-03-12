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


def unlikeliness(a,b):
    return sum(aa!=bb for aa,bb in zip(a,b))

n,k = map(int, input().split())
A = [list(input()) for _ in range(n)]
sets = [Stuff() for _ in range(n)]

edges = []
for i,a in enumerate(A):
    for j,b in enumerate(A):
        if j<i:
            u = unlikeliness(a,b)
            edges.append((u,i,j))

edges.sort()

tot_unl = 0
ans = []

for (u,x,y) in edges:
    if (sets[x].union(sets[y])):
            tot_unl+=u
            ans.append((x,y))
            
print(tot_unl)
for i,j in ans:
    print(i,j)


