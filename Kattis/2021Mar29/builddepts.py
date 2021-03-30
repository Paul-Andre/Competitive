from collections import defaultdict
g = defaultdict(set)
n = int(input())
for _ in range(n):
    s = input().split()
    t = s[0][:-1]
    for dep in s[1:]:
        g[dep].add(t)

order = []
vis = set()
stack = []
def trav(i):

    if i in vis:
        return
    vis.add(i)
    stack.append((add_list, i))
    for j in g[i]:
        stack.append((trav, j))

def add_list(i):
    order.append(i)

changed = input()
stack = [(trav, changed)]

while(stack):
    f,p = stack.pop()
    f(p)

for s in reversed(order):
    print(s)


