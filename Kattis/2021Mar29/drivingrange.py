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


n,m = map(int, input().split())
cities = [Stuff() for _ in range(n)]
roads = []
for _ in range(m):
    x,y, l = map(int, input().split())
    roads.append((l,x,y))

roads.sort()
components = n
finished=False
for l,x,y in roads:
    if(cities[x].union(cities[y])):
        components-=1;
    if components == 1:
        print(l)
        finished = True
        break;
if not finished:
    print("IMPOSSIBLE")


