class Stuff:
    def __init__(self,parent,size):
        self.parent = parent
        self.size =size

    def find(self):
        if self.parent == None:
            return self
        else:
            pp = self.parent.find()
            self.parent = pp
            return pp
    def union(self, other):
        sp = self.find()
        op = other.find()
        if sp==op:
            return sp
        sp.parent = op
        op.size+=sp.size
        return op

for _ in range(int(input())):
    m = dict()
    for _ in range(int(input())):
        a,b=input().split()
        if a not in m:
            m[a] = Stuff(None,1)
        if b not in m:
            m[b] = Stuff(None,1)

        aa = m[a]
        bb = m[b]

        print(aa.union(bb).size)


